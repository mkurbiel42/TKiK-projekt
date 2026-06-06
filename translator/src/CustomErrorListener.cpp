#include "CustomErrorListener.h"

#include "antlr4-runtime.h"

CustomErrorListener::CustomErrorListener(){
    errors = {};
    error = false;
}

void CustomErrorListener::syntaxError(antlr4::Recognizer* recognizer, antlr4::Token* offendingSymbol, size_t line, size_t charPositionInLine, const std::string& msg, std::exception_ptr e){
    errors.push_back("Syntax error at line " + std::to_string(line) + ":" + std::to_string(charPositionInLine) + ": " + msg);
    error = true;
}
