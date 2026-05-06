
// Generated from PythonParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "PythonParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by PythonParser.
 */
class  PythonParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFile(PythonParser::FileContext *ctx) = 0;
  virtual void exitFile(PythonParser::FileContext *ctx) = 0;

  virtual void enterStatements(PythonParser::StatementsContext *ctx) = 0;
  virtual void exitStatements(PythonParser::StatementsContext *ctx) = 0;

  virtual void enterStatement(PythonParser::StatementContext *ctx) = 0;
  virtual void exitStatement(PythonParser::StatementContext *ctx) = 0;

  virtual void enterSimple_stmt(PythonParser::Simple_stmtContext *ctx) = 0;
  virtual void exitSimple_stmt(PythonParser::Simple_stmtContext *ctx) = 0;

  virtual void enterCompound_stmt(PythonParser::Compound_stmtContext *ctx) = 0;
  virtual void exitCompound_stmt(PythonParser::Compound_stmtContext *ctx) = 0;

  virtual void enterAssignment(PythonParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(PythonParser::AssignmentContext *ctx) = 0;

  virtual void enterAugassign(PythonParser::AugassignContext *ctx) = 0;
  virtual void exitAugassign(PythonParser::AugassignContext *ctx) = 0;

  virtual void enterReturn_stmt(PythonParser::Return_stmtContext *ctx) = 0;
  virtual void exitReturn_stmt(PythonParser::Return_stmtContext *ctx) = 0;

  virtual void enterRaise_stmt(PythonParser::Raise_stmtContext *ctx) = 0;
  virtual void exitRaise_stmt(PythonParser::Raise_stmtContext *ctx) = 0;

  virtual void enterPass_stmt(PythonParser::Pass_stmtContext *ctx) = 0;
  virtual void exitPass_stmt(PythonParser::Pass_stmtContext *ctx) = 0;

  virtual void enterDel_stmt(PythonParser::Del_stmtContext *ctx) = 0;
  virtual void exitDel_stmt(PythonParser::Del_stmtContext *ctx) = 0;

  virtual void enterBreak_stmt(PythonParser::Break_stmtContext *ctx) = 0;
  virtual void exitBreak_stmt(PythonParser::Break_stmtContext *ctx) = 0;

  virtual void enterContinue_stmt(PythonParser::Continue_stmtContext *ctx) = 0;
  virtual void exitContinue_stmt(PythonParser::Continue_stmtContext *ctx) = 0;

  virtual void enterGlobal_stmt(PythonParser::Global_stmtContext *ctx) = 0;
  virtual void exitGlobal_stmt(PythonParser::Global_stmtContext *ctx) = 0;

  virtual void enterNonlocal_stmt(PythonParser::Nonlocal_stmtContext *ctx) = 0;
  virtual void exitNonlocal_stmt(PythonParser::Nonlocal_stmtContext *ctx) = 0;

  virtual void enterFunction_def(PythonParser::Function_defContext *ctx) = 0;
  virtual void exitFunction_def(PythonParser::Function_defContext *ctx) = 0;

  virtual void enterLambdef(PythonParser::LambdefContext *ctx) = 0;
  virtual void exitLambdef(PythonParser::LambdefContext *ctx) = 0;

  virtual void enterIf_stmt(PythonParser::If_stmtContext *ctx) = 0;
  virtual void exitIf_stmt(PythonParser::If_stmtContext *ctx) = 0;

  virtual void enterElif_stmt(PythonParser::Elif_stmtContext *ctx) = 0;
  virtual void exitElif_stmt(PythonParser::Elif_stmtContext *ctx) = 0;

  virtual void enterElse_block(PythonParser::Else_blockContext *ctx) = 0;
  virtual void exitElse_block(PythonParser::Else_blockContext *ctx) = 0;

  virtual void enterFor_stmt(PythonParser::For_stmtContext *ctx) = 0;
  virtual void exitFor_stmt(PythonParser::For_stmtContext *ctx) = 0;

  virtual void enterWhile_stmt(PythonParser::While_stmtContext *ctx) = 0;
  virtual void exitWhile_stmt(PythonParser::While_stmtContext *ctx) = 0;

  virtual void enterClass_def(PythonParser::Class_defContext *ctx) = 0;
  virtual void exitClass_def(PythonParser::Class_defContext *ctx) = 0;

  virtual void enterTry_finally_block(PythonParser::Try_finally_blockContext *ctx) = 0;
  virtual void exitTry_finally_block(PythonParser::Try_finally_blockContext *ctx) = 0;

  virtual void enterTry_except_else_finally_block(PythonParser::Try_except_else_finally_blockContext *ctx) = 0;
  virtual void exitTry_except_else_finally_block(PythonParser::Try_except_else_finally_blockContext *ctx) = 0;

  virtual void enterExcept_block(PythonParser::Except_blockContext *ctx) = 0;
  virtual void exitExcept_block(PythonParser::Except_blockContext *ctx) = 0;

  virtual void enterFinally_block(PythonParser::Finally_blockContext *ctx) = 0;
  virtual void exitFinally_block(PythonParser::Finally_blockContext *ctx) = 0;

  virtual void enterMatch_stmt(PythonParser::Match_stmtContext *ctx) = 0;
  virtual void exitMatch_stmt(PythonParser::Match_stmtContext *ctx) = 0;

  virtual void enterSubject_expr(PythonParser::Subject_exprContext *ctx) = 0;
  virtual void exitSubject_expr(PythonParser::Subject_exprContext *ctx) = 0;

  virtual void enterMatch_case(PythonParser::Match_caseContext *ctx) = 0;
  virtual void exitMatch_case(PythonParser::Match_caseContext *ctx) = 0;

  virtual void enterMatch_case_default(PythonParser::Match_case_defaultContext *ctx) = 0;
  virtual void exitMatch_case_default(PythonParser::Match_case_defaultContext *ctx) = 0;

  virtual void enterPattern(PythonParser::PatternContext *ctx) = 0;
  virtual void exitPattern(PythonParser::PatternContext *ctx) = 0;

  virtual void enterAttr_pattern(PythonParser::Attr_patternContext *ctx) = 0;
  virtual void exitAttr_pattern(PythonParser::Attr_patternContext *ctx) = 0;

  virtual void enterBlock(PythonParser::BlockContext *ctx) = 0;
  virtual void exitBlock(PythonParser::BlockContext *ctx) = 0;

  virtual void enterFunction_params(PythonParser::Function_paramsContext *ctx) = 0;
  virtual void exitFunction_params(PythonParser::Function_paramsContext *ctx) = 0;

  virtual void enterExpressions(PythonParser::ExpressionsContext *ctx) = 0;
  virtual void exitExpressions(PythonParser::ExpressionsContext *ctx) = 0;

  virtual void enterExpression(PythonParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(PythonParser::ExpressionContext *ctx) = 0;

  virtual void enterAssignment_expression(PythonParser::Assignment_expressionContext *ctx) = 0;
  virtual void exitAssignment_expression(PythonParser::Assignment_expressionContext *ctx) = 0;

  virtual void enterNamed_expression(PythonParser::Named_expressionContext *ctx) = 0;
  virtual void exitNamed_expression(PythonParser::Named_expressionContext *ctx) = 0;

  virtual void enterDisjunction(PythonParser::DisjunctionContext *ctx) = 0;
  virtual void exitDisjunction(PythonParser::DisjunctionContext *ctx) = 0;

  virtual void enterConjunction(PythonParser::ConjunctionContext *ctx) = 0;
  virtual void exitConjunction(PythonParser::ConjunctionContext *ctx) = 0;

  virtual void enterInversion(PythonParser::InversionContext *ctx) = 0;
  virtual void exitInversion(PythonParser::InversionContext *ctx) = 0;

  virtual void enterComparison(PythonParser::ComparisonContext *ctx) = 0;
  virtual void exitComparison(PythonParser::ComparisonContext *ctx) = 0;

  virtual void enterComp_op(PythonParser::Comp_opContext *ctx) = 0;
  virtual void exitComp_op(PythonParser::Comp_opContext *ctx) = 0;

  virtual void enterComp_eq(PythonParser::Comp_eqContext *ctx) = 0;
  virtual void exitComp_eq(PythonParser::Comp_eqContext *ctx) = 0;

  virtual void enterComp_noteq(PythonParser::Comp_noteqContext *ctx) = 0;
  virtual void exitComp_noteq(PythonParser::Comp_noteqContext *ctx) = 0;

  virtual void enterComp_lte(PythonParser::Comp_lteContext *ctx) = 0;
  virtual void exitComp_lte(PythonParser::Comp_lteContext *ctx) = 0;

  virtual void enterComp_lt(PythonParser::Comp_ltContext *ctx) = 0;
  virtual void exitComp_lt(PythonParser::Comp_ltContext *ctx) = 0;

  virtual void enterComp_gte(PythonParser::Comp_gteContext *ctx) = 0;
  virtual void exitComp_gte(PythonParser::Comp_gteContext *ctx) = 0;

  virtual void enterComp_gt(PythonParser::Comp_gtContext *ctx) = 0;
  virtual void exitComp_gt(PythonParser::Comp_gtContext *ctx) = 0;

  virtual void enterComp_notin(PythonParser::Comp_notinContext *ctx) = 0;
  virtual void exitComp_notin(PythonParser::Comp_notinContext *ctx) = 0;

  virtual void enterComp_in(PythonParser::Comp_inContext *ctx) = 0;
  virtual void exitComp_in(PythonParser::Comp_inContext *ctx) = 0;

  virtual void enterSum(PythonParser::SumContext *ctx) = 0;
  virtual void exitSum(PythonParser::SumContext *ctx) = 0;

  virtual void enterTerm(PythonParser::TermContext *ctx) = 0;
  virtual void exitTerm(PythonParser::TermContext *ctx) = 0;

  virtual void enterFactor(PythonParser::FactorContext *ctx) = 0;
  virtual void exitFactor(PythonParser::FactorContext *ctx) = 0;

  virtual void enterPower(PythonParser::PowerContext *ctx) = 0;
  virtual void exitPower(PythonParser::PowerContext *ctx) = 0;

  virtual void enterFunction_call_prim(PythonParser::Function_call_primContext *ctx) = 0;
  virtual void exitFunction_call_prim(PythonParser::Function_call_primContext *ctx) = 0;

  virtual void enterSlice_prim(PythonParser::Slice_primContext *ctx) = 0;
  virtual void exitSlice_prim(PythonParser::Slice_primContext *ctx) = 0;

  virtual void enterField_prim(PythonParser::Field_primContext *ctx) = 0;
  virtual void exitField_prim(PythonParser::Field_primContext *ctx) = 0;

  virtual void enterAtom_prim(PythonParser::Atom_primContext *ctx) = 0;
  virtual void exitAtom_prim(PythonParser::Atom_primContext *ctx) = 0;

  virtual void enterSlices(PythonParser::SlicesContext *ctx) = 0;
  virtual void exitSlices(PythonParser::SlicesContext *ctx) = 0;

  virtual void enterSlice(PythonParser::SliceContext *ctx) = 0;
  virtual void exitSlice(PythonParser::SliceContext *ctx) = 0;

  virtual void enterAtom(PythonParser::AtomContext *ctx) = 0;
  virtual void exitAtom(PythonParser::AtomContext *ctx) = 0;

  virtual void enterArguments(PythonParser::ArgumentsContext *ctx) = 0;
  virtual void exitArguments(PythonParser::ArgumentsContext *ctx) = 0;

  virtual void enterArg_expression(PythonParser::Arg_expressionContext *ctx) = 0;
  virtual void exitArg_expression(PythonParser::Arg_expressionContext *ctx) = 0;

  virtual void enterKwargs(PythonParser::KwargsContext *ctx) = 0;
  virtual void exitKwargs(PythonParser::KwargsContext *ctx) = 0;

  virtual void enterStarred_expression(PythonParser::Starred_expressionContext *ctx) = 0;
  virtual void exitStarred_expression(PythonParser::Starred_expressionContext *ctx) = 0;

  virtual void enterKwarg_or_starred(PythonParser::Kwarg_or_starredContext *ctx) = 0;
  virtual void exitKwarg_or_starred(PythonParser::Kwarg_or_starredContext *ctx) = 0;

  virtual void enterKwarg_or_double_starred(PythonParser::Kwarg_or_double_starredContext *ctx) = 0;
  virtual void exitKwarg_or_double_starred(PythonParser::Kwarg_or_double_starredContext *ctx) = 0;

  virtual void enterAs_targets(PythonParser::As_targetsContext *ctx) = 0;
  virtual void exitAs_targets(PythonParser::As_targetsContext *ctx) = 0;

  virtual void enterAs_target_list(PythonParser::As_target_listContext *ctx) = 0;
  virtual void exitAs_target_list(PythonParser::As_target_listContext *ctx) = 0;

  virtual void enterAs_target_tuple(PythonParser::As_target_tupleContext *ctx) = 0;
  virtual void exitAs_target_tuple(PythonParser::As_target_tupleContext *ctx) = 0;

  virtual void enterAs_target(PythonParser::As_targetContext *ctx) = 0;
  virtual void exitAs_target(PythonParser::As_targetContext *ctx) = 0;

  virtual void enterAs_atom(PythonParser::As_atomContext *ctx) = 0;
  virtual void exitAs_atom(PythonParser::As_atomContext *ctx) = 0;

  virtual void enterSingle_target(PythonParser::Single_targetContext *ctx) = 0;
  virtual void exitSingle_target(PythonParser::Single_targetContext *ctx) = 0;

  virtual void enterSingle_subscript_attribute_target(PythonParser::Single_subscript_attribute_targetContext *ctx) = 0;
  virtual void exitSingle_subscript_attribute_target(PythonParser::Single_subscript_attribute_targetContext *ctx) = 0;

  virtual void enterField_tprim(PythonParser::Field_tprimContext *ctx) = 0;
  virtual void exitField_tprim(PythonParser::Field_tprimContext *ctx) = 0;

  virtual void enterFunction_call_tprim(PythonParser::Function_call_tprimContext *ctx) = 0;
  virtual void exitFunction_call_tprim(PythonParser::Function_call_tprimContext *ctx) = 0;

  virtual void enterSlice_tprim(PythonParser::Slice_tprimContext *ctx) = 0;
  virtual void exitSlice_tprim(PythonParser::Slice_tprimContext *ctx) = 0;

  virtual void enterAtom_tprim(PythonParser::Atom_tprimContext *ctx) = 0;
  virtual void exitAtom_tprim(PythonParser::Atom_tprimContext *ctx) = 0;

  virtual void enterT_lookahead(PythonParser::T_lookaheadContext *ctx) = 0;
  virtual void exitT_lookahead(PythonParser::T_lookaheadContext *ctx) = 0;

  virtual void enterTargets(PythonParser::TargetsContext *ctx) = 0;
  virtual void exitTargets(PythonParser::TargetsContext *ctx) = 0;

  virtual void enterTarget(PythonParser::TargetContext *ctx) = 0;
  virtual void exitTarget(PythonParser::TargetContext *ctx) = 0;

  virtual void enterDel_targets(PythonParser::Del_targetsContext *ctx) = 0;
  virtual void exitDel_targets(PythonParser::Del_targetsContext *ctx) = 0;

  virtual void enterDel_target(PythonParser::Del_targetContext *ctx) = 0;
  virtual void exitDel_target(PythonParser::Del_targetContext *ctx) = 0;

  virtual void enterStrings(PythonParser::StringsContext *ctx) = 0;
  virtual void exitStrings(PythonParser::StringsContext *ctx) = 0;

  virtual void enterList(PythonParser::ListContext *ctx) = 0;
  virtual void exitList(PythonParser::ListContext *ctx) = 0;

  virtual void enterTuple(PythonParser::TupleContext *ctx) = 0;
  virtual void exitTuple(PythonParser::TupleContext *ctx) = 0;

  virtual void enterSet(PythonParser::SetContext *ctx) = 0;
  virtual void exitSet(PythonParser::SetContext *ctx) = 0;

  virtual void enterDict(PythonParser::DictContext *ctx) = 0;
  virtual void exitDict(PythonParser::DictContext *ctx) = 0;

  virtual void enterDouble_starred_kvpairs(PythonParser::Double_starred_kvpairsContext *ctx) = 0;
  virtual void exitDouble_starred_kvpairs(PythonParser::Double_starred_kvpairsContext *ctx) = 0;

  virtual void enterDouble_starred_kvpair(PythonParser::Double_starred_kvpairContext *ctx) = 0;
  virtual void exitDouble_starred_kvpair(PythonParser::Double_starred_kvpairContext *ctx) = 0;

  virtual void enterKvpair(PythonParser::KvpairContext *ctx) = 0;
  virtual void exitKvpair(PythonParser::KvpairContext *ctx) = 0;

  virtual void enterFor_if_clauses(PythonParser::For_if_clausesContext *ctx) = 0;
  virtual void exitFor_if_clauses(PythonParser::For_if_clausesContext *ctx) = 0;

  virtual void enterFor_if_clause(PythonParser::For_if_clauseContext *ctx) = 0;
  virtual void exitFor_if_clause(PythonParser::For_if_clauseContext *ctx) = 0;

  virtual void enterListcomp(PythonParser::ListcompContext *ctx) = 0;
  virtual void exitListcomp(PythonParser::ListcompContext *ctx) = 0;

  virtual void enterSetcomp(PythonParser::SetcompContext *ctx) = 0;
  virtual void exitSetcomp(PythonParser::SetcompContext *ctx) = 0;

  virtual void enterDictcomp(PythonParser::DictcompContext *ctx) = 0;
  virtual void exitDictcomp(PythonParser::DictcompContext *ctx) = 0;


};

