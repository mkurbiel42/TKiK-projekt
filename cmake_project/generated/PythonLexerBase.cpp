#include "PythonLexer.h"
#include "PythonParser.h"
#include "PythonLexerBase.h"
#include <regex>
using namespace antlr4;

PythonLexerBase::PythonLexerBase(antlr4::CharStream *input): Lexer(input)
{
    opened = 0;
    lastToken = nullptr;
}

void PythonLexerBase::emit(std::unique_ptr<antlr4::Token> t){
    tokens.push_back(cloneToken(t));
    setToken(std::move(t));
}

std::unique_ptr<antlr4::Token> PythonLexerBase::nextToken(){
    if(_input->LA(1) == EOF && !indents.empty()){
        for(int i=tokens.size()-1;i>=0;i--){
            if(tokens[i]->getType() == EOF){
                tokens.erase(tokens.begin()+i);
            }
        }
        emit(commonToken(PythonParser::NEWLINE, "\n"));
        while (!indents.empty()){
            emit(createDedent());
            indents.pop();
        }
        emit(commonToken(PythonParser::ENDMARKER, "ENDMARKER"));
    }
    std::unique_ptr<antlr4::Token> next = Lexer::nextToken();
    if (next->getChannel() == antlr4::Token::DEFAULT_CHANNEL) {
        lastToken = cloneToken(next);
    }
    if (!tokens.empty())
    {
        next = std::move(*tokens.begin());
        tokens.erase(tokens.begin());
    }
    return next;
}

std::unique_ptr<antlr4::Token> PythonLexerBase::createDedent(){
    std::unique_ptr<antlr4::CommonToken> dedent = commonToken(PythonParser::DEDENT, "");
    return dedent;
}

std::unique_ptr<antlr4::CommonToken> PythonLexerBase::commonToken(size_t type, const std::string& text){
    int stop = getCharIndex() - 1;
    int start = text.empty() ? stop : stop - text.size() + 1;
    return _factory->create({ this, _input }, type, text, DEFAULT_TOKEN_CHANNEL, start, stop, lastToken ? lastToken->getLine() : 0, lastToken ? lastToken->getCharPositionInLine() : 0);
}

int PythonLexerBase::getIndentationCount(const std::string& spaces){
    int count = 0;
    for (char ch : spaces) {
        switch (ch) {
            case '\t':
                count += 4 - (count % 4);
                break;
            default:
      // A normal space char.
                count++;
        }
    }

    return count;
}

bool PythonLexerBase::atStartOfInput() {
    return getCharPositionInLine() == 0 && getLine() == 1;
}

void PythonLexerBase::openBrace() {
    this->opened++;
}

void PythonLexerBase::closeBrace() {
    this->opened--;
}

void PythonLexerBase::onNewLine(){
    std::string newLine = std::regex_replace(getText(), std::regex("[^\r\n\f]+"), "");
    std::string spaces = std::regex_replace(getText(), std::regex("[\r\n\f]+"), "");
    int next = _input->LA(1);
    int nextnext = _input->LA(2);
    if (opened > 0 || (nextnext != -1 && (next == '\r' || next == '\n' || next == '\f' || next == '#'))) {
        skip();
    }
    else {
        emit(commonToken(PythonLexer::NEWLINE, newLine));
        int indent = getIndentationCount(spaces);
        int previous = indents.empty() ? 0 : indents.top();
        if (indent == previous) {
            skip();
        }
        else if (indent > previous) {
            indents.push(indent);
            emit(commonToken(PythonLexer::INDENT, spaces));
        }
        else {
            while(!indents.empty() && indents.top() > indent) {
                emit(createDedent());
                indents.pop();
            }
        }
    }
}

void PythonLexerBase::reset(){
    tokens = std::vector<std::unique_ptr<antlr4::Token>>{};
    indents = std::stack<int>{};
    opened = 0;
    lastToken = nullptr;
    Lexer::reset();
}

std::unique_ptr<antlr4::CommonToken> PythonLexerBase::cloneToken(const std::unique_ptr<antlr4::Token>& source){
    return _factory->create({ this, _input }, source->getType(), source->getText(), source->getChannel(), source->getStartIndex(), source->getStopIndex(), source->getLine(), source->getCharPositionInLine());
}