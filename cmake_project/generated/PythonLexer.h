#include "PythonLexerBase.h"

// Generated from PythonLexer.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  PythonLexer : public PythonLexerBase {
public:
  enum {
    DEDENT = 1, INDENT = 2, ENDMARKER = 3, NEWLINE = 4, EQUALS = 5, RETURN = 6, 
    RAISE = 7, PASS = 8, DEL = 9, BREAK = 10, CONTINUE = 11, GLOBAL = 12, 
    NONLOCAL = 13, COMMA = 14, DEF = 15, PAR_LEFT = 16, PAR_RIGHT = 17, 
    BRACKET_LEFT = 18, BRACKET_RIGHT = 19, BRACE_LEFT = 20, BRACE_RIGHT = 21, 
    LAMBDA = 22, COLON = 23, IF = 24, ELIF = 25, ELSE = 26, FOR = 27, IN = 28, 
    WHILE = 29, CLASS = 30, TRY = 31, EXCEPT = 32, FINALLY = 33, MATCH = 34, 
    CASE = 35, UNDERSCORE = 36, DOT = 37, WALRUS = 38, OR = 39, AND = 40, 
    NOT = 41, PLUS = 42, MINUS = 43, STAR = 44, SLASH = 45, EQEQUAL = 46, 
    NOTEQUAL = 47, LESS = 48, GREATER = 49, LESSEQUAL = 50, GREATEREQUAL = 51, 
    DOUBLESLASH = 52, PERCENT = 53, DOUBLESTAR = 54, TRUE = 55, FALSE = 56, 
    NONE = 57, PLUSEQUAL = 58, MINUSEQUAL = 59, STAREQUAL = 60, SLASHEQUAL = 61, 
    PERCENTEQUAL = 62, DOUBLESTAREQUAL = 63, DOUBLESLASHEQUAL = 64, NAME = 65, 
    NUMBER = 66, STRING = 67, WHITESPACESKIP = 68
  };

  explicit PythonLexer(antlr4::CharStream *input);

  ~PythonLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  void action(antlr4::RuleContext *context, size_t ruleIndex, size_t actionIndex) override;

  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.
  void NEWLINEAction(antlr4::RuleContext *context, size_t actionIndex);
  void PAR_LEFTAction(antlr4::RuleContext *context, size_t actionIndex);
  void PAR_RIGHTAction(antlr4::RuleContext *context, size_t actionIndex);
  void BRACKET_LEFTAction(antlr4::RuleContext *context, size_t actionIndex);
  void BRACKET_RIGHTAction(antlr4::RuleContext *context, size_t actionIndex);
  void BRACE_LEFTAction(antlr4::RuleContext *context, size_t actionIndex);
  void BRACE_RIGHTAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.
  bool NEWLINESempred(antlr4::RuleContext *_localctx, size_t predicateIndex);

};

