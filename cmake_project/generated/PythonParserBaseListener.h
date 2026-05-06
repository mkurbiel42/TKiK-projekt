
// Generated from PythonParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "PythonParserListener.h"


/**
 * This class provides an empty implementation of PythonParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  PythonParserBaseListener : public PythonParserListener {
public:

  virtual void enterFile(PythonParser::FileContext * /*ctx*/) override { }
  virtual void exitFile(PythonParser::FileContext * /*ctx*/) override { }

  virtual void enterStatements(PythonParser::StatementsContext * /*ctx*/) override { }
  virtual void exitStatements(PythonParser::StatementsContext * /*ctx*/) override { }

  virtual void enterStatement(PythonParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(PythonParser::StatementContext * /*ctx*/) override { }

  virtual void enterSimple_stmt(PythonParser::Simple_stmtContext * /*ctx*/) override { }
  virtual void exitSimple_stmt(PythonParser::Simple_stmtContext * /*ctx*/) override { }

  virtual void enterCompound_stmt(PythonParser::Compound_stmtContext * /*ctx*/) override { }
  virtual void exitCompound_stmt(PythonParser::Compound_stmtContext * /*ctx*/) override { }

  virtual void enterAssignment(PythonParser::AssignmentContext * /*ctx*/) override { }
  virtual void exitAssignment(PythonParser::AssignmentContext * /*ctx*/) override { }

  virtual void enterAugassign(PythonParser::AugassignContext * /*ctx*/) override { }
  virtual void exitAugassign(PythonParser::AugassignContext * /*ctx*/) override { }

  virtual void enterReturn_stmt(PythonParser::Return_stmtContext * /*ctx*/) override { }
  virtual void exitReturn_stmt(PythonParser::Return_stmtContext * /*ctx*/) override { }

  virtual void enterRaise_stmt(PythonParser::Raise_stmtContext * /*ctx*/) override { }
  virtual void exitRaise_stmt(PythonParser::Raise_stmtContext * /*ctx*/) override { }

  virtual void enterPass_stmt(PythonParser::Pass_stmtContext * /*ctx*/) override { }
  virtual void exitPass_stmt(PythonParser::Pass_stmtContext * /*ctx*/) override { }

  virtual void enterDel_stmt(PythonParser::Del_stmtContext * /*ctx*/) override { }
  virtual void exitDel_stmt(PythonParser::Del_stmtContext * /*ctx*/) override { }

  virtual void enterBreak_stmt(PythonParser::Break_stmtContext * /*ctx*/) override { }
  virtual void exitBreak_stmt(PythonParser::Break_stmtContext * /*ctx*/) override { }

  virtual void enterContinue_stmt(PythonParser::Continue_stmtContext * /*ctx*/) override { }
  virtual void exitContinue_stmt(PythonParser::Continue_stmtContext * /*ctx*/) override { }

  virtual void enterGlobal_stmt(PythonParser::Global_stmtContext * /*ctx*/) override { }
  virtual void exitGlobal_stmt(PythonParser::Global_stmtContext * /*ctx*/) override { }

  virtual void enterNonlocal_stmt(PythonParser::Nonlocal_stmtContext * /*ctx*/) override { }
  virtual void exitNonlocal_stmt(PythonParser::Nonlocal_stmtContext * /*ctx*/) override { }

  virtual void enterFunction_def(PythonParser::Function_defContext * /*ctx*/) override { }
  virtual void exitFunction_def(PythonParser::Function_defContext * /*ctx*/) override { }

  virtual void enterLambdef(PythonParser::LambdefContext * /*ctx*/) override { }
  virtual void exitLambdef(PythonParser::LambdefContext * /*ctx*/) override { }

  virtual void enterIf_stmt(PythonParser::If_stmtContext * /*ctx*/) override { }
  virtual void exitIf_stmt(PythonParser::If_stmtContext * /*ctx*/) override { }

  virtual void enterElif_stmt(PythonParser::Elif_stmtContext * /*ctx*/) override { }
  virtual void exitElif_stmt(PythonParser::Elif_stmtContext * /*ctx*/) override { }

  virtual void enterElse_block(PythonParser::Else_blockContext * /*ctx*/) override { }
  virtual void exitElse_block(PythonParser::Else_blockContext * /*ctx*/) override { }

  virtual void enterFor_stmt(PythonParser::For_stmtContext * /*ctx*/) override { }
  virtual void exitFor_stmt(PythonParser::For_stmtContext * /*ctx*/) override { }

  virtual void enterWhile_stmt(PythonParser::While_stmtContext * /*ctx*/) override { }
  virtual void exitWhile_stmt(PythonParser::While_stmtContext * /*ctx*/) override { }

  virtual void enterClass_def(PythonParser::Class_defContext * /*ctx*/) override { }
  virtual void exitClass_def(PythonParser::Class_defContext * /*ctx*/) override { }

  virtual void enterTry_finally_block(PythonParser::Try_finally_blockContext * /*ctx*/) override { }
  virtual void exitTry_finally_block(PythonParser::Try_finally_blockContext * /*ctx*/) override { }

  virtual void enterTry_except_else_finally_block(PythonParser::Try_except_else_finally_blockContext * /*ctx*/) override { }
  virtual void exitTry_except_else_finally_block(PythonParser::Try_except_else_finally_blockContext * /*ctx*/) override { }

  virtual void enterExcept_block(PythonParser::Except_blockContext * /*ctx*/) override { }
  virtual void exitExcept_block(PythonParser::Except_blockContext * /*ctx*/) override { }

  virtual void enterFinally_block(PythonParser::Finally_blockContext * /*ctx*/) override { }
  virtual void exitFinally_block(PythonParser::Finally_blockContext * /*ctx*/) override { }

  virtual void enterMatch_stmt(PythonParser::Match_stmtContext * /*ctx*/) override { }
  virtual void exitMatch_stmt(PythonParser::Match_stmtContext * /*ctx*/) override { }

  virtual void enterSubject_expr(PythonParser::Subject_exprContext * /*ctx*/) override { }
  virtual void exitSubject_expr(PythonParser::Subject_exprContext * /*ctx*/) override { }

  virtual void enterMatch_case(PythonParser::Match_caseContext * /*ctx*/) override { }
  virtual void exitMatch_case(PythonParser::Match_caseContext * /*ctx*/) override { }

  virtual void enterMatch_case_default(PythonParser::Match_case_defaultContext * /*ctx*/) override { }
  virtual void exitMatch_case_default(PythonParser::Match_case_defaultContext * /*ctx*/) override { }

  virtual void enterPattern(PythonParser::PatternContext * /*ctx*/) override { }
  virtual void exitPattern(PythonParser::PatternContext * /*ctx*/) override { }

  virtual void enterAttr_pattern(PythonParser::Attr_patternContext * /*ctx*/) override { }
  virtual void exitAttr_pattern(PythonParser::Attr_patternContext * /*ctx*/) override { }

  virtual void enterBlock(PythonParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(PythonParser::BlockContext * /*ctx*/) override { }

  virtual void enterFunction_params(PythonParser::Function_paramsContext * /*ctx*/) override { }
  virtual void exitFunction_params(PythonParser::Function_paramsContext * /*ctx*/) override { }

  virtual void enterExpressions(PythonParser::ExpressionsContext * /*ctx*/) override { }
  virtual void exitExpressions(PythonParser::ExpressionsContext * /*ctx*/) override { }

  virtual void enterExpression(PythonParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(PythonParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterAssignment_expression(PythonParser::Assignment_expressionContext * /*ctx*/) override { }
  virtual void exitAssignment_expression(PythonParser::Assignment_expressionContext * /*ctx*/) override { }

  virtual void enterNamed_expression(PythonParser::Named_expressionContext * /*ctx*/) override { }
  virtual void exitNamed_expression(PythonParser::Named_expressionContext * /*ctx*/) override { }

  virtual void enterDisjunction(PythonParser::DisjunctionContext * /*ctx*/) override { }
  virtual void exitDisjunction(PythonParser::DisjunctionContext * /*ctx*/) override { }

  virtual void enterConjunction(PythonParser::ConjunctionContext * /*ctx*/) override { }
  virtual void exitConjunction(PythonParser::ConjunctionContext * /*ctx*/) override { }

  virtual void enterInversion(PythonParser::InversionContext * /*ctx*/) override { }
  virtual void exitInversion(PythonParser::InversionContext * /*ctx*/) override { }

  virtual void enterComparison(PythonParser::ComparisonContext * /*ctx*/) override { }
  virtual void exitComparison(PythonParser::ComparisonContext * /*ctx*/) override { }

  virtual void enterComp_op(PythonParser::Comp_opContext * /*ctx*/) override { }
  virtual void exitComp_op(PythonParser::Comp_opContext * /*ctx*/) override { }

  virtual void enterComp_eq(PythonParser::Comp_eqContext * /*ctx*/) override { }
  virtual void exitComp_eq(PythonParser::Comp_eqContext * /*ctx*/) override { }

  virtual void enterComp_noteq(PythonParser::Comp_noteqContext * /*ctx*/) override { }
  virtual void exitComp_noteq(PythonParser::Comp_noteqContext * /*ctx*/) override { }

  virtual void enterComp_lte(PythonParser::Comp_lteContext * /*ctx*/) override { }
  virtual void exitComp_lte(PythonParser::Comp_lteContext * /*ctx*/) override { }

  virtual void enterComp_lt(PythonParser::Comp_ltContext * /*ctx*/) override { }
  virtual void exitComp_lt(PythonParser::Comp_ltContext * /*ctx*/) override { }

  virtual void enterComp_gte(PythonParser::Comp_gteContext * /*ctx*/) override { }
  virtual void exitComp_gte(PythonParser::Comp_gteContext * /*ctx*/) override { }

  virtual void enterComp_gt(PythonParser::Comp_gtContext * /*ctx*/) override { }
  virtual void exitComp_gt(PythonParser::Comp_gtContext * /*ctx*/) override { }

  virtual void enterComp_notin(PythonParser::Comp_notinContext * /*ctx*/) override { }
  virtual void exitComp_notin(PythonParser::Comp_notinContext * /*ctx*/) override { }

  virtual void enterComp_in(PythonParser::Comp_inContext * /*ctx*/) override { }
  virtual void exitComp_in(PythonParser::Comp_inContext * /*ctx*/) override { }

  virtual void enterSum(PythonParser::SumContext * /*ctx*/) override { }
  virtual void exitSum(PythonParser::SumContext * /*ctx*/) override { }

  virtual void enterTerm(PythonParser::TermContext * /*ctx*/) override { }
  virtual void exitTerm(PythonParser::TermContext * /*ctx*/) override { }

  virtual void enterFactor(PythonParser::FactorContext * /*ctx*/) override { }
  virtual void exitFactor(PythonParser::FactorContext * /*ctx*/) override { }

  virtual void enterPower(PythonParser::PowerContext * /*ctx*/) override { }
  virtual void exitPower(PythonParser::PowerContext * /*ctx*/) override { }

  virtual void enterFunction_call_prim(PythonParser::Function_call_primContext * /*ctx*/) override { }
  virtual void exitFunction_call_prim(PythonParser::Function_call_primContext * /*ctx*/) override { }

  virtual void enterSlice_prim(PythonParser::Slice_primContext * /*ctx*/) override { }
  virtual void exitSlice_prim(PythonParser::Slice_primContext * /*ctx*/) override { }

  virtual void enterField_prim(PythonParser::Field_primContext * /*ctx*/) override { }
  virtual void exitField_prim(PythonParser::Field_primContext * /*ctx*/) override { }

  virtual void enterAtom_prim(PythonParser::Atom_primContext * /*ctx*/) override { }
  virtual void exitAtom_prim(PythonParser::Atom_primContext * /*ctx*/) override { }

  virtual void enterSlices(PythonParser::SlicesContext * /*ctx*/) override { }
  virtual void exitSlices(PythonParser::SlicesContext * /*ctx*/) override { }

  virtual void enterSlice(PythonParser::SliceContext * /*ctx*/) override { }
  virtual void exitSlice(PythonParser::SliceContext * /*ctx*/) override { }

  virtual void enterAtom(PythonParser::AtomContext * /*ctx*/) override { }
  virtual void exitAtom(PythonParser::AtomContext * /*ctx*/) override { }

  virtual void enterArguments(PythonParser::ArgumentsContext * /*ctx*/) override { }
  virtual void exitArguments(PythonParser::ArgumentsContext * /*ctx*/) override { }

  virtual void enterArg_expression(PythonParser::Arg_expressionContext * /*ctx*/) override { }
  virtual void exitArg_expression(PythonParser::Arg_expressionContext * /*ctx*/) override { }

  virtual void enterKwargs(PythonParser::KwargsContext * /*ctx*/) override { }
  virtual void exitKwargs(PythonParser::KwargsContext * /*ctx*/) override { }

  virtual void enterStarred_expression(PythonParser::Starred_expressionContext * /*ctx*/) override { }
  virtual void exitStarred_expression(PythonParser::Starred_expressionContext * /*ctx*/) override { }

  virtual void enterKwarg_or_starred(PythonParser::Kwarg_or_starredContext * /*ctx*/) override { }
  virtual void exitKwarg_or_starred(PythonParser::Kwarg_or_starredContext * /*ctx*/) override { }

  virtual void enterKwarg_or_double_starred(PythonParser::Kwarg_or_double_starredContext * /*ctx*/) override { }
  virtual void exitKwarg_or_double_starred(PythonParser::Kwarg_or_double_starredContext * /*ctx*/) override { }

  virtual void enterAs_targets(PythonParser::As_targetsContext * /*ctx*/) override { }
  virtual void exitAs_targets(PythonParser::As_targetsContext * /*ctx*/) override { }

  virtual void enterAs_target_list(PythonParser::As_target_listContext * /*ctx*/) override { }
  virtual void exitAs_target_list(PythonParser::As_target_listContext * /*ctx*/) override { }

  virtual void enterAs_target_tuple(PythonParser::As_target_tupleContext * /*ctx*/) override { }
  virtual void exitAs_target_tuple(PythonParser::As_target_tupleContext * /*ctx*/) override { }

  virtual void enterAs_target(PythonParser::As_targetContext * /*ctx*/) override { }
  virtual void exitAs_target(PythonParser::As_targetContext * /*ctx*/) override { }

  virtual void enterAs_atom(PythonParser::As_atomContext * /*ctx*/) override { }
  virtual void exitAs_atom(PythonParser::As_atomContext * /*ctx*/) override { }

  virtual void enterSingle_target(PythonParser::Single_targetContext * /*ctx*/) override { }
  virtual void exitSingle_target(PythonParser::Single_targetContext * /*ctx*/) override { }

  virtual void enterSingle_subscript_attribute_target(PythonParser::Single_subscript_attribute_targetContext * /*ctx*/) override { }
  virtual void exitSingle_subscript_attribute_target(PythonParser::Single_subscript_attribute_targetContext * /*ctx*/) override { }

  virtual void enterField_tprim(PythonParser::Field_tprimContext * /*ctx*/) override { }
  virtual void exitField_tprim(PythonParser::Field_tprimContext * /*ctx*/) override { }

  virtual void enterFunction_call_tprim(PythonParser::Function_call_tprimContext * /*ctx*/) override { }
  virtual void exitFunction_call_tprim(PythonParser::Function_call_tprimContext * /*ctx*/) override { }

  virtual void enterSlice_tprim(PythonParser::Slice_tprimContext * /*ctx*/) override { }
  virtual void exitSlice_tprim(PythonParser::Slice_tprimContext * /*ctx*/) override { }

  virtual void enterAtom_tprim(PythonParser::Atom_tprimContext * /*ctx*/) override { }
  virtual void exitAtom_tprim(PythonParser::Atom_tprimContext * /*ctx*/) override { }

  virtual void enterT_lookahead(PythonParser::T_lookaheadContext * /*ctx*/) override { }
  virtual void exitT_lookahead(PythonParser::T_lookaheadContext * /*ctx*/) override { }

  virtual void enterTargets(PythonParser::TargetsContext * /*ctx*/) override { }
  virtual void exitTargets(PythonParser::TargetsContext * /*ctx*/) override { }

  virtual void enterTarget(PythonParser::TargetContext * /*ctx*/) override { }
  virtual void exitTarget(PythonParser::TargetContext * /*ctx*/) override { }

  virtual void enterDel_targets(PythonParser::Del_targetsContext * /*ctx*/) override { }
  virtual void exitDel_targets(PythonParser::Del_targetsContext * /*ctx*/) override { }

  virtual void enterDel_target(PythonParser::Del_targetContext * /*ctx*/) override { }
  virtual void exitDel_target(PythonParser::Del_targetContext * /*ctx*/) override { }

  virtual void enterStrings(PythonParser::StringsContext * /*ctx*/) override { }
  virtual void exitStrings(PythonParser::StringsContext * /*ctx*/) override { }

  virtual void enterList(PythonParser::ListContext * /*ctx*/) override { }
  virtual void exitList(PythonParser::ListContext * /*ctx*/) override { }

  virtual void enterTuple(PythonParser::TupleContext * /*ctx*/) override { }
  virtual void exitTuple(PythonParser::TupleContext * /*ctx*/) override { }

  virtual void enterSet(PythonParser::SetContext * /*ctx*/) override { }
  virtual void exitSet(PythonParser::SetContext * /*ctx*/) override { }

  virtual void enterDict(PythonParser::DictContext * /*ctx*/) override { }
  virtual void exitDict(PythonParser::DictContext * /*ctx*/) override { }

  virtual void enterDouble_starred_kvpairs(PythonParser::Double_starred_kvpairsContext * /*ctx*/) override { }
  virtual void exitDouble_starred_kvpairs(PythonParser::Double_starred_kvpairsContext * /*ctx*/) override { }

  virtual void enterDouble_starred_kvpair(PythonParser::Double_starred_kvpairContext * /*ctx*/) override { }
  virtual void exitDouble_starred_kvpair(PythonParser::Double_starred_kvpairContext * /*ctx*/) override { }

  virtual void enterKvpair(PythonParser::KvpairContext * /*ctx*/) override { }
  virtual void exitKvpair(PythonParser::KvpairContext * /*ctx*/) override { }

  virtual void enterFor_if_clauses(PythonParser::For_if_clausesContext * /*ctx*/) override { }
  virtual void exitFor_if_clauses(PythonParser::For_if_clausesContext * /*ctx*/) override { }

  virtual void enterFor_if_clause(PythonParser::For_if_clauseContext * /*ctx*/) override { }
  virtual void exitFor_if_clause(PythonParser::For_if_clauseContext * /*ctx*/) override { }

  virtual void enterListcomp(PythonParser::ListcompContext * /*ctx*/) override { }
  virtual void exitListcomp(PythonParser::ListcompContext * /*ctx*/) override { }

  virtual void enterSetcomp(PythonParser::SetcompContext * /*ctx*/) override { }
  virtual void exitSetcomp(PythonParser::SetcompContext * /*ctx*/) override { }

  virtual void enterDictcomp(PythonParser::DictcompContext * /*ctx*/) override { }
  virtual void exitDictcomp(PythonParser::DictcompContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

