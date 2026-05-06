
// Generated from PythonParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  PythonParser : public antlr4::Parser {
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

  enum {
    RuleFile = 0, RuleStatements = 1, RuleStatement = 2, RuleSimple_stmt = 3, 
    RuleCompound_stmt = 4, RuleAssignment = 5, RuleAugassign = 6, RuleReturn_stmt = 7, 
    RuleRaise_stmt = 8, RulePass_stmt = 9, RuleDel_stmt = 10, RuleBreak_stmt = 11, 
    RuleContinue_stmt = 12, RuleGlobal_stmt = 13, RuleNonlocal_stmt = 14, 
    RuleFunction_def = 15, RuleLambdef = 16, RuleIf_stmt = 17, RuleElif_stmt = 18, 
    RuleElse_block = 19, RuleFor_stmt = 20, RuleWhile_stmt = 21, RuleClass_def = 22, 
    RuleTry_stmt = 23, RuleExcept_block = 24, RuleFinally_block = 25, RuleMatch_stmt = 26, 
    RuleSubject_expr = 27, RuleCase_block = 28, RulePattern = 29, RuleAttr_pattern = 30, 
    RuleBlock = 31, RuleFunction_params = 32, RuleExpressions = 33, RuleExpression = 34, 
    RuleAssignment_expression = 35, RuleNamed_expression = 36, RuleDisjunction = 37, 
    RuleConjunction = 38, RuleInversion = 39, RuleComparison = 40, RuleComp_op = 41, 
    RuleComp_eq = 42, RuleComp_noteq = 43, RuleComp_lte = 44, RuleComp_lt = 45, 
    RuleComp_gte = 46, RuleComp_gt = 47, RuleComp_notin = 48, RuleComp_in = 49, 
    RuleSum = 50, RuleTerm = 51, RuleFactor = 52, RulePower = 53, RulePrimary = 54, 
    RuleSlices = 55, RuleSlice = 56, RuleAtom = 57, RuleArguments = 58, 
    RuleArg_expression = 59, RuleKwargs = 60, RuleStarred_expression = 61, 
    RuleKwarg_or_starred = 62, RuleKwarg_or_double_starred = 63, RuleAs_targets = 64, 
    RuleAs_target_list = 65, RuleAs_target_tuple = 66, RuleAs_target = 67, 
    RuleAs_atom = 68, RuleSingle_target = 69, RuleSingle_subscript_attribute_target = 70, 
    RuleT_primary = 71, RuleT_lookahead = 72, RuleTargets = 73, RuleTarget = 74, 
    RuleDel_targets = 75, RuleDel_target = 76, RuleStrings = 77, RuleList = 78, 
    RuleTuple = 79, RuleSet = 80, RuleDict = 81, RuleDouble_starred_kvpairs = 82, 
    RuleDouble_starred_kvpair = 83, RuleKvpair = 84, RuleFor_if_clauses = 85, 
    RuleFor_if_clause = 86, RuleListcomp = 87, RuleSetcomp = 88, RuleDictcomp = 89
  };

  explicit PythonParser(antlr4::TokenStream *input);

  PythonParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~PythonParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class FileContext;
  class StatementsContext;
  class StatementContext;
  class Simple_stmtContext;
  class Compound_stmtContext;
  class AssignmentContext;
  class AugassignContext;
  class Return_stmtContext;
  class Raise_stmtContext;
  class Pass_stmtContext;
  class Del_stmtContext;
  class Break_stmtContext;
  class Continue_stmtContext;
  class Global_stmtContext;
  class Nonlocal_stmtContext;
  class Function_defContext;
  class LambdefContext;
  class If_stmtContext;
  class Elif_stmtContext;
  class Else_blockContext;
  class For_stmtContext;
  class While_stmtContext;
  class Class_defContext;
  class Try_stmtContext;
  class Except_blockContext;
  class Finally_blockContext;
  class Match_stmtContext;
  class Subject_exprContext;
  class Case_blockContext;
  class PatternContext;
  class Attr_patternContext;
  class BlockContext;
  class Function_paramsContext;
  class ExpressionsContext;
  class ExpressionContext;
  class Assignment_expressionContext;
  class Named_expressionContext;
  class DisjunctionContext;
  class ConjunctionContext;
  class InversionContext;
  class ComparisonContext;
  class Comp_opContext;
  class Comp_eqContext;
  class Comp_noteqContext;
  class Comp_lteContext;
  class Comp_ltContext;
  class Comp_gteContext;
  class Comp_gtContext;
  class Comp_notinContext;
  class Comp_inContext;
  class SumContext;
  class TermContext;
  class FactorContext;
  class PowerContext;
  class PrimaryContext;
  class SlicesContext;
  class SliceContext;
  class AtomContext;
  class ArgumentsContext;
  class Arg_expressionContext;
  class KwargsContext;
  class Starred_expressionContext;
  class Kwarg_or_starredContext;
  class Kwarg_or_double_starredContext;
  class As_targetsContext;
  class As_target_listContext;
  class As_target_tupleContext;
  class As_targetContext;
  class As_atomContext;
  class Single_targetContext;
  class Single_subscript_attribute_targetContext;
  class T_primaryContext;
  class T_lookaheadContext;
  class TargetsContext;
  class TargetContext;
  class Del_targetsContext;
  class Del_targetContext;
  class StringsContext;
  class ListContext;
  class TupleContext;
  class SetContext;
  class DictContext;
  class Double_starred_kvpairsContext;
  class Double_starred_kvpairContext;
  class KvpairContext;
  class For_if_clausesContext;
  class For_if_clauseContext;
  class ListcompContext;
  class SetcompContext;
  class DictcompContext; 

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ENDMARKER();
    StatementsContext *statements();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FileContext* file();

  class  StatementsContext : public antlr4::ParserRuleContext {
  public:
    StatementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatementsContext* statements();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Compound_stmtContext *compound_stmt();
    Simple_stmtContext *simple_stmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatementContext* statement();

  class  Simple_stmtContext : public antlr4::ParserRuleContext {
  public:
    Simple_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NEWLINE();
    AssignmentContext *assignment();
    ExpressionsContext *expressions();
    Return_stmtContext *return_stmt();
    Raise_stmtContext *raise_stmt();
    Pass_stmtContext *pass_stmt();
    Del_stmtContext *del_stmt();
    Break_stmtContext *break_stmt();
    Continue_stmtContext *continue_stmt();
    Global_stmtContext *global_stmt();
    Nonlocal_stmtContext *nonlocal_stmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Simple_stmtContext* simple_stmt();

  class  Compound_stmtContext : public antlr4::ParserRuleContext {
  public:
    Compound_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Function_defContext *function_def();
    If_stmtContext *if_stmt();
    Class_defContext *class_def();
    For_stmtContext *for_stmt();
    While_stmtContext *while_stmt();
    Match_stmtContext *match_stmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Compound_stmtContext* compound_stmt();

  class  AssignmentContext : public antlr4::ParserRuleContext {
  public:
    AssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionsContext *expressions();
    std::vector<As_targetsContext *> as_targets();
    As_targetsContext* as_targets(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EQUALS();
    antlr4::tree::TerminalNode* EQUALS(size_t i);
    Single_targetContext *single_target();
    AugassignContext *augassign();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AssignmentContext* assignment();

  class  AugassignContext : public antlr4::ParserRuleContext {
  public:
    AugassignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PLUSEQUAL();
    antlr4::tree::TerminalNode *MINUSEQUAL();
    antlr4::tree::TerminalNode *STAREQUAL();
    antlr4::tree::TerminalNode *SLASHEQUAL();
    antlr4::tree::TerminalNode *PERCENTEQUAL();
    antlr4::tree::TerminalNode *DOUBLESTAREQUAL();
    antlr4::tree::TerminalNode *DOUBLESLASHEQUAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AugassignContext* augassign();

  class  Return_stmtContext : public antlr4::ParserRuleContext {
  public:
    Return_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RETURN();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Return_stmtContext* return_stmt();

  class  Raise_stmtContext : public antlr4::ParserRuleContext {
  public:
    Raise_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RAISE();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Raise_stmtContext* raise_stmt();

  class  Pass_stmtContext : public antlr4::ParserRuleContext {
  public:
    Pass_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PASS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Pass_stmtContext* pass_stmt();

  class  Del_stmtContext : public antlr4::ParserRuleContext {
  public:
    Del_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEL();
    Del_targetsContext *del_targets();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Del_stmtContext* del_stmt();

  class  Break_stmtContext : public antlr4::ParserRuleContext {
  public:
    Break_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BREAK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Break_stmtContext* break_stmt();

  class  Continue_stmtContext : public antlr4::ParserRuleContext {
  public:
    Continue_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONTINUE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Continue_stmtContext* continue_stmt();

  class  Global_stmtContext : public antlr4::ParserRuleContext {
  public:
    Global_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GLOBAL();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Global_stmtContext* global_stmt();

  class  Nonlocal_stmtContext : public antlr4::ParserRuleContext {
  public:
    Nonlocal_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NONLOCAL();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Nonlocal_stmtContext* nonlocal_stmt();

  class  Function_defContext : public antlr4::ParserRuleContext {
  public:
    Function_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEF();
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *PAR_LEFT();
    antlr4::tree::TerminalNode *PAR_RIGHT();
    antlr4::tree::TerminalNode *COLON();
    BlockContext *block();
    Function_paramsContext *function_params();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Function_defContext* function_def();

  class  LambdefContext : public antlr4::ParserRuleContext {
  public:
    LambdefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LAMBDA();
    antlr4::tree::TerminalNode *COLON();
    ExpressionContext *expression();
    Function_paramsContext *function_params();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LambdefContext* lambdef();

  class  If_stmtContext : public antlr4::ParserRuleContext {
  public:
    If_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    Named_expressionContext *named_expression();
    antlr4::tree::TerminalNode *COLON();
    BlockContext *block();
    Elif_stmtContext *elif_stmt();
    Else_blockContext *else_block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  If_stmtContext* if_stmt();

  class  Elif_stmtContext : public antlr4::ParserRuleContext {
  public:
    Elif_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ELSE();
    Named_expressionContext *named_expression();
    antlr4::tree::TerminalNode *COLON();
    BlockContext *block();
    Elif_stmtContext *elif_stmt();
    Else_blockContext *else_block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Elif_stmtContext* elif_stmt();

  class  Else_blockContext : public antlr4::ParserRuleContext {
  public:
    Else_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ELSE();
    antlr4::tree::TerminalNode *COLON();
    BlockContext *block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Else_blockContext* else_block();

  class  For_stmtContext : public antlr4::ParserRuleContext {
  public:
    For_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    TargetsContext *targets();
    antlr4::tree::TerminalNode *IN();
    ExpressionsContext *expressions();
    antlr4::tree::TerminalNode *COLON();
    BlockContext *block();
    Else_blockContext *else_block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  For_stmtContext* for_stmt();

  class  While_stmtContext : public antlr4::ParserRuleContext {
  public:
    While_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    Named_expressionContext *named_expression();
    antlr4::tree::TerminalNode *COLON();
    BlockContext *block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  While_stmtContext* while_stmt();

  class  Class_defContext : public antlr4::ParserRuleContext {
  public:
    Class_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CLASS();
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *COLON();
    BlockContext *block();
    antlr4::tree::TerminalNode *PAR_LEFT();
    antlr4::tree::TerminalNode *PAR_RIGHT();
    ArgumentsContext *arguments();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Class_defContext* class_def();

  class  Try_stmtContext : public antlr4::ParserRuleContext {
  public:
    Try_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Try_stmtContext() = default;
    void copyFrom(Try_stmtContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Try_except_else_finally_blockContext : public Try_stmtContext {
  public:
    Try_except_else_finally_blockContext(Try_stmtContext *ctx);

    antlr4::tree::TerminalNode *TRY();
    antlr4::tree::TerminalNode *COLON();
    BlockContext *block();
    std::vector<Except_blockContext *> except_block();
    Except_blockContext* except_block(size_t i);
    Else_blockContext *else_block();
    Finally_blockContext *finally_block();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Try_finally_blockContext : public Try_stmtContext {
  public:
    Try_finally_blockContext(Try_stmtContext *ctx);

    antlr4::tree::TerminalNode *TRY();
    antlr4::tree::TerminalNode *COLON();
    BlockContext *block();
    Finally_blockContext *finally_block();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  Try_stmtContext* try_stmt();

  class  Except_blockContext : public antlr4::ParserRuleContext {
  public:
    Except_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXCEPT();
    antlr4::tree::TerminalNode *COLON();
    BlockContext *block();
    ExpressionContext *expression();
    ExpressionsContext *expressions();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Except_blockContext* except_block();

  class  Finally_blockContext : public antlr4::ParserRuleContext {
  public:
    Finally_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FINALLY();
    antlr4::tree::TerminalNode *COLON();
    BlockContext *block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Finally_blockContext* finally_block();

  class  Match_stmtContext : public antlr4::ParserRuleContext {
  public:
    Match_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MATCH();
    Subject_exprContext *subject_expr();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *NEWLINE();
    antlr4::tree::TerminalNode *INDENT();
    antlr4::tree::TerminalNode *DEDENT();
    std::vector<Case_blockContext *> case_block();
    Case_blockContext* case_block(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Match_stmtContext* match_stmt();

  class  Subject_exprContext : public antlr4::ParserRuleContext {
  public:
    Subject_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Named_expressionContext *> named_expression();
    Named_expressionContext* named_expression(size_t i);
    antlr4::tree::TerminalNode *COMMA();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Subject_exprContext* subject_expr();

  class  Case_blockContext : public antlr4::ParserRuleContext {
  public:
    Case_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Case_blockContext() = default;
    void copyFrom(Case_blockContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Match_case_defaultContext : public Case_blockContext {
  public:
    Match_case_defaultContext(Case_blockContext *ctx);

    antlr4::tree::TerminalNode *CASE();
    antlr4::tree::TerminalNode *UNDERSCORE();
    antlr4::tree::TerminalNode *COLON();
    BlockContext *block();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Match_caseContext : public Case_blockContext {
  public:
    Match_caseContext(Case_blockContext *ctx);

    antlr4::tree::TerminalNode *CASE();
    PatternContext *pattern();
    antlr4::tree::TerminalNode *COLON();
    BlockContext *block();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  Case_blockContext* case_block();

  class  PatternContext : public antlr4::ParserRuleContext {
  public:
    PatternContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    Attr_patternContext *attr_pattern();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PatternContext* pattern();

  class  Attr_patternContext : public antlr4::ParserRuleContext {
  public:
    Attr_patternContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Attr_patternContext* attr_pattern();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NEWLINE();
    antlr4::tree::TerminalNode *INDENT();
    StatementsContext *statements();
    antlr4::tree::TerminalNode *DEDENT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BlockContext* block();

  class  Function_paramsContext : public antlr4::ParserRuleContext {
  public:
    Function_paramsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Function_paramsContext* function_params();

  class  ExpressionsContext : public antlr4::ParserRuleContext {
  public:
    ExpressionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExpressionsContext* expressions();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<DisjunctionContext *> disjunction();
    DisjunctionContext* disjunction(size_t i);
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *ELSE();
    ExpressionContext *expression();
    LambdefContext *lambdef();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExpressionContext* expression();

  class  Assignment_expressionContext : public antlr4::ParserRuleContext {
  public:
    Assignment_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *WALRUS();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Assignment_expressionContext* assignment_expression();

  class  Named_expressionContext : public antlr4::ParserRuleContext {
  public:
    Named_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Assignment_expressionContext *assignment_expression();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Named_expressionContext* named_expression();

  class  DisjunctionContext : public antlr4::ParserRuleContext {
  public:
    DisjunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ConjunctionContext *> conjunction();
    ConjunctionContext* conjunction(size_t i);
    std::vector<antlr4::tree::TerminalNode *> OR();
    antlr4::tree::TerminalNode* OR(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DisjunctionContext* disjunction();

  class  ConjunctionContext : public antlr4::ParserRuleContext {
  public:
    ConjunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<InversionContext *> inversion();
    InversionContext* inversion(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AND();
    antlr4::tree::TerminalNode* AND(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ConjunctionContext* conjunction();

  class  InversionContext : public antlr4::ParserRuleContext {
  public:
    InversionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOT();
    InversionContext *inversion();
    ComparisonContext *comparison();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  InversionContext* inversion();

  class  ComparisonContext : public antlr4::ParserRuleContext {
  public:
    ComparisonContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SumContext *sum();
    std::vector<Comp_opContext *> comp_op();
    Comp_opContext* comp_op(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ComparisonContext* comparison();

  class  Comp_opContext : public antlr4::ParserRuleContext {
  public:
    Comp_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Comp_eqContext *comp_eq();
    Comp_noteqContext *comp_noteq();
    Comp_lteContext *comp_lte();
    Comp_ltContext *comp_lt();
    Comp_gteContext *comp_gte();
    Comp_gtContext *comp_gt();
    Comp_notinContext *comp_notin();
    Comp_inContext *comp_in();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Comp_opContext* comp_op();

  class  Comp_eqContext : public antlr4::ParserRuleContext {
  public:
    Comp_eqContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQEQUAL();
    SumContext *sum();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Comp_eqContext* comp_eq();

  class  Comp_noteqContext : public antlr4::ParserRuleContext {
  public:
    Comp_noteqContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOTEQUAL();
    SumContext *sum();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Comp_noteqContext* comp_noteq();

  class  Comp_lteContext : public antlr4::ParserRuleContext {
  public:
    Comp_lteContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LESSEQUAL();
    SumContext *sum();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Comp_lteContext* comp_lte();

  class  Comp_ltContext : public antlr4::ParserRuleContext {
  public:
    Comp_ltContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LESS();
    SumContext *sum();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Comp_ltContext* comp_lt();

  class  Comp_gteContext : public antlr4::ParserRuleContext {
  public:
    Comp_gteContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GREATEREQUAL();
    SumContext *sum();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Comp_gteContext* comp_gte();

  class  Comp_gtContext : public antlr4::ParserRuleContext {
  public:
    Comp_gtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GREATER();
    SumContext *sum();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Comp_gtContext* comp_gt();

  class  Comp_notinContext : public antlr4::ParserRuleContext {
  public:
    Comp_notinContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *IN();
    SumContext *sum();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Comp_notinContext* comp_notin();

  class  Comp_inContext : public antlr4::ParserRuleContext {
  public:
    Comp_inContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IN();
    SumContext *sum();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Comp_inContext* comp_in();

  class  SumContext : public antlr4::ParserRuleContext {
  public:
    SumContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TermContext *term();
    SumContext *sum();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SumContext* sum();
  SumContext* sum(int precedence);
  class  TermContext : public antlr4::ParserRuleContext {
  public:
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FactorContext *factor();
    TermContext *term();
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *SLASH();
    antlr4::tree::TerminalNode *DOUBLESLASH();
    antlr4::tree::TerminalNode *PERCENT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TermContext* term();
  TermContext* term(int precedence);
  class  FactorContext : public antlr4::ParserRuleContext {
  public:
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PLUS();
    FactorContext *factor();
    antlr4::tree::TerminalNode *MINUS();
    PowerContext *power();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FactorContext* factor();

  class  PowerContext : public antlr4::ParserRuleContext {
  public:
    PowerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrimaryContext *primary();
    antlr4::tree::TerminalNode *DOUBLESTAR();
    FactorContext *factor();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PowerContext* power();

  class  PrimaryContext : public antlr4::ParserRuleContext {
  public:
    PrimaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PrimaryContext() = default;
    void copyFrom(PrimaryContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Function_call_primContext : public PrimaryContext {
  public:
    Function_call_primContext(PrimaryContext *ctx);

    PrimaryContext *primary();
    antlr4::tree::TerminalNode *PAR_LEFT();
    antlr4::tree::TerminalNode *PAR_RIGHT();
    ArgumentsContext *arguments();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Slice_primContext : public PrimaryContext {
  public:
    Slice_primContext(PrimaryContext *ctx);

    PrimaryContext *primary();
    antlr4::tree::TerminalNode *BRACKET_LEFT();
    SlicesContext *slices();
    antlr4::tree::TerminalNode *BRACKET_RIGHT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Field_primContext : public PrimaryContext {
  public:
    Field_primContext(PrimaryContext *ctx);

    PrimaryContext *primary();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *NAME();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Atom_primContext : public PrimaryContext {
  public:
    Atom_primContext(PrimaryContext *ctx);

    AtomContext *atom();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  PrimaryContext* primary();
  PrimaryContext* primary(int precedence);
  class  SlicesContext : public antlr4::ParserRuleContext {
  public:
    SlicesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SliceContext *> slice();
    SliceContext* slice(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SlicesContext* slices();

  class  SliceContext : public antlr4::ParserRuleContext {
  public:
    SliceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    Named_expressionContext *named_expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SliceContext* slice();

  class  AtomContext : public antlr4::ParserRuleContext {
  public:
    AtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *FALSE();
    antlr4::tree::TerminalNode *NONE();
    StringsContext *strings();
    antlr4::tree::TerminalNode *NUMBER();
    TupleContext *tuple();
    ListContext *list();
    ListcompContext *listcomp();
    DictContext *dict();
    DictcompContext *dictcomp();
    SetContext *set();
    SetcompContext *setcomp();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AtomContext* atom();

  class  ArgumentsContext : public antlr4::ParserRuleContext {
  public:
    ArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Arg_expressionContext *> arg_expression();
    Arg_expressionContext* arg_expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ArgumentsContext* arguments();

  class  Arg_expressionContext : public antlr4::ParserRuleContext {
  public:
    Arg_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Starred_expressionContext *starred_expression();
    Assignment_expressionContext *assignment_expression();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Arg_expressionContext* arg_expression();

  class  KwargsContext : public antlr4::ParserRuleContext {
  public:
    KwargsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Kwarg_or_starredContext *> kwarg_or_starred();
    Kwarg_or_starredContext* kwarg_or_starred(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<Kwarg_or_double_starredContext *> kwarg_or_double_starred();
    Kwarg_or_double_starredContext* kwarg_or_double_starred(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  KwargsContext* kwargs();

  class  Starred_expressionContext : public antlr4::ParserRuleContext {
  public:
    Starred_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STAR();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Starred_expressionContext* starred_expression();

  class  Kwarg_or_starredContext : public antlr4::ParserRuleContext {
  public:
    Kwarg_or_starredContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *EQUALS();
    ExpressionContext *expression();
    Starred_expressionContext *starred_expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Kwarg_or_starredContext* kwarg_or_starred();

  class  Kwarg_or_double_starredContext : public antlr4::ParserRuleContext {
  public:
    Kwarg_or_double_starredContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *EQUALS();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *DOUBLESTAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Kwarg_or_double_starredContext* kwarg_or_double_starred();

  class  As_targetsContext : public antlr4::ParserRuleContext {
  public:
    As_targetsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<As_targetContext *> as_target();
    As_targetContext* as_target(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  As_targetsContext* as_targets();

  class  As_target_listContext : public antlr4::ParserRuleContext {
  public:
    As_target_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<As_targetContext *> as_target();
    As_targetContext* as_target(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  As_target_listContext* as_target_list();

  class  As_target_tupleContext : public antlr4::ParserRuleContext {
  public:
    As_target_tupleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<As_targetContext *> as_target();
    As_targetContext* as_target(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  As_target_tupleContext* as_target_tuple();

  class  As_targetContext : public antlr4::ParserRuleContext {
  public:
    As_targetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    T_primaryContext *t_primary();
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *BRACE_LEFT();
    SlicesContext *slices();
    antlr4::tree::TerminalNode *BRACE_RIGHT();
    As_atomContext *as_atom();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  As_targetContext* as_target();

  class  As_atomContext : public antlr4::ParserRuleContext {
  public:
    As_atomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *PAR_LEFT();
    As_targetContext *as_target();
    antlr4::tree::TerminalNode *PAR_RIGHT();
    As_target_tupleContext *as_target_tuple();
    antlr4::tree::TerminalNode *BRACKET_LEFT();
    antlr4::tree::TerminalNode *BRACE_RIGHT();
    As_target_listContext *as_target_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  As_atomContext* as_atom();

  class  Single_targetContext : public antlr4::ParserRuleContext {
  public:
    Single_targetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Single_subscript_attribute_targetContext *single_subscript_attribute_target();
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *PAR_LEFT();
    Single_targetContext *single_target();
    antlr4::tree::TerminalNode *PAR_RIGHT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Single_targetContext* single_target();

  class  Single_subscript_attribute_targetContext : public antlr4::ParserRuleContext {
  public:
    Single_subscript_attribute_targetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);
    antlr4::tree::TerminalNode *BRACKET_LEFT();
    SlicesContext *slices();
    antlr4::tree::TerminalNode *BRACE_RIGHT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Single_subscript_attribute_targetContext* single_subscript_attribute_target();

  class  T_primaryContext : public antlr4::ParserRuleContext {
  public:
    T_primaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    T_primaryContext() = default;
    void copyFrom(T_primaryContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Function_call_tprimContext : public T_primaryContext {
  public:
    Function_call_tprimContext(T_primaryContext *ctx);

    PrimaryContext *primary();
    antlr4::tree::TerminalNode *PAR_LEFT();
    antlr4::tree::TerminalNode *PAR_RIGHT();
    ArgumentsContext *arguments();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Field_tprimContext : public T_primaryContext {
  public:
    Field_tprimContext(T_primaryContext *ctx);

    PrimaryContext *primary();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *NAME();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Slice_tprimContext : public T_primaryContext {
  public:
    Slice_tprimContext(T_primaryContext *ctx);

    PrimaryContext *primary();
    antlr4::tree::TerminalNode *BRACKET_LEFT();
    SlicesContext *slices();
    antlr4::tree::TerminalNode *BRACKET_RIGHT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Atom_tprimContext : public T_primaryContext {
  public:
    Atom_tprimContext(T_primaryContext *ctx);

    AtomContext *atom();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  T_primaryContext* t_primary();

  class  T_lookaheadContext : public antlr4::ParserRuleContext {
  public:
    T_lookaheadContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PAR_LEFT();
    antlr4::tree::TerminalNode *BRACKET_LEFT();
    antlr4::tree::TerminalNode *DOT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  T_lookaheadContext* t_lookahead();

  class  TargetsContext : public antlr4::ParserRuleContext {
  public:
    TargetsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TargetContext *> target();
    TargetContext* target(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TargetsContext* targets();

  class  TargetContext : public antlr4::ParserRuleContext {
  public:
    TargetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrimaryContext *primary();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *BRACKET_LEFT();
    SlicesContext *slices();
    antlr4::tree::TerminalNode *BRACKET_RIGHT();
    AtomContext *atom();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TargetContext* target();

  class  Del_targetsContext : public antlr4::ParserRuleContext {
  public:
    Del_targetsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Del_targetContext *> del_target();
    Del_targetContext* del_target(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Del_targetsContext* del_targets();

  class  Del_targetContext : public antlr4::ParserRuleContext {
  public:
    Del_targetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrimaryContext *primary();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *BRACKET_LEFT();
    SlicesContext *slices();
    antlr4::tree::TerminalNode *BRACKET_RIGHT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Del_targetContext* del_target();

  class  StringsContext : public antlr4::ParserRuleContext {
  public:
    StringsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> STRING();
    antlr4::tree::TerminalNode* STRING(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StringsContext* strings();

  class  ListContext : public antlr4::ParserRuleContext {
  public:
    ListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BRACKET_LEFT();
    antlr4::tree::TerminalNode *BRACKET_RIGHT();
    ExpressionsContext *expressions();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ListContext* list();

  class  TupleContext : public antlr4::ParserRuleContext {
  public:
    TupleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PAR_LEFT();
    antlr4::tree::TerminalNode *PAR_RIGHT();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *COMMA();
    ExpressionsContext *expressions();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TupleContext* tuple();

  class  SetContext : public antlr4::ParserRuleContext {
  public:
    SetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BRACE_LEFT();
    ExpressionsContext *expressions();
    antlr4::tree::TerminalNode *BRACE_RIGHT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SetContext* set();

  class  DictContext : public antlr4::ParserRuleContext {
  public:
    DictContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BRACE_LEFT();
    antlr4::tree::TerminalNode *BRACE_RIGHT();
    Double_starred_kvpairsContext *double_starred_kvpairs();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DictContext* dict();

  class  Double_starred_kvpairsContext : public antlr4::ParserRuleContext {
  public:
    Double_starred_kvpairsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Double_starred_kvpairContext *> double_starred_kvpair();
    Double_starred_kvpairContext* double_starred_kvpair(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Double_starred_kvpairsContext* double_starred_kvpairs();

  class  Double_starred_kvpairContext : public antlr4::ParserRuleContext {
  public:
    Double_starred_kvpairContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DOUBLESTAR();
    ExpressionContext *expression();
    KvpairContext *kvpair();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Double_starred_kvpairContext* double_starred_kvpair();

  class  KvpairContext : public antlr4::ParserRuleContext {
  public:
    KvpairContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *COLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  KvpairContext* kvpair();

  class  For_if_clausesContext : public antlr4::ParserRuleContext {
  public:
    For_if_clausesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<For_if_clauseContext *> for_if_clause();
    For_if_clauseContext* for_if_clause(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  For_if_clausesContext* for_if_clauses();

  class  For_if_clauseContext : public antlr4::ParserRuleContext {
  public:
    For_if_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    TargetsContext *targets();
    antlr4::tree::TerminalNode *IN();
    std::vector<DisjunctionContext *> disjunction();
    DisjunctionContext* disjunction(size_t i);
    std::vector<antlr4::tree::TerminalNode *> IF();
    antlr4::tree::TerminalNode* IF(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  For_if_clauseContext* for_if_clause();

  class  ListcompContext : public antlr4::ParserRuleContext {
  public:
    ListcompContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BRACKET_LEFT();
    Named_expressionContext *named_expression();
    For_if_clausesContext *for_if_clauses();
    antlr4::tree::TerminalNode *BRACKET_RIGHT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ListcompContext* listcomp();

  class  SetcompContext : public antlr4::ParserRuleContext {
  public:
    SetcompContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BRACE_LEFT();
    Named_expressionContext *named_expression();
    For_if_clausesContext *for_if_clauses();
    antlr4::tree::TerminalNode *BRACE_RIGHT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SetcompContext* setcomp();

  class  DictcompContext : public antlr4::ParserRuleContext {
  public:
    DictcompContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BRACE_LEFT();
    KvpairContext *kvpair();
    For_if_clausesContext *for_if_clauses();
    antlr4::tree::TerminalNode *BRACE_RIGHT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DictcompContext* dictcomp();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool named_expressionSempred(Named_expressionContext *_localctx, size_t predicateIndex);
  bool sumSempred(SumContext *_localctx, size_t predicateIndex);
  bool termSempred(TermContext *_localctx, size_t predicateIndex);
  bool primarySempred(PrimaryContext *_localctx, size_t predicateIndex);
  bool slicesSempred(SlicesContext *_localctx, size_t predicateIndex);
  bool arg_expressionSempred(Arg_expressionContext *_localctx, size_t predicateIndex);
  bool as_targetsSempred(As_targetsContext *_localctx, size_t predicateIndex);
  bool as_targetSempred(As_targetContext *_localctx, size_t predicateIndex);
  bool single_subscript_attribute_targetSempred(Single_subscript_attribute_targetContext *_localctx, size_t predicateIndex);
  bool targetsSempred(TargetsContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

