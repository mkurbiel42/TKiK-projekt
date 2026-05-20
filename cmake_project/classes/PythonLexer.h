#include "PythonLexerBase.h"

// Generated from ./PythonLexer.g4 by ANTLR 4.13.2

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
    CASE = 35, AS = 36, UNDERSCORE = 37, DOT = 38, WALRUS = 39, OR = 40, 
    AND = 41, NOT = 42, PLUS = 43, MINUS = 44, STAR = 45, SLASH = 46, EQEQUAL = 47, 
    NOTEQUAL = 48, LESS = 49, GREATER = 50, LESSEQUAL = 51, GREATEREQUAL = 52, 
    DOUBLESLASH = 53, PERCENT = 54, DOUBLESTAR = 55, TRUE = 56, FALSE = 57, 
    NONE = 58, PLUSEQUAL = 59, MINUSEQUAL = 60, STAREQUAL = 61, SLASHEQUAL = 62, 
    PERCENTEQUAL = 63, DOUBLESTAREQUAL = 64, DOUBLESLASHEQUAL = 65, NAME = 66, 
    NUMBER = 67, STRING = 68, WHITESPACESKIP = 69
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

