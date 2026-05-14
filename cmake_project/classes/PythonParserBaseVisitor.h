
// Generated from ./PythonParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "PythonParserVisitor.h"


/**
 * This class provides an empty implementation of PythonParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  PythonParserBaseVisitor : public PythonParserVisitor {
public:

  virtual std::any visitFile(PythonParser::FileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatements(PythonParser::StatementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(PythonParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimple_stmt(PythonParser::Simple_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompound_stmt(PythonParser::Compound_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimple_assignment(PythonParser::Simple_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAug_assignment(PythonParser::Aug_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAugassign(PythonParser::AugassignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturn_stmt(PythonParser::Return_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRaise_stmt(PythonParser::Raise_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPass_stmt(PythonParser::Pass_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDel_stmt(PythonParser::Del_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBreak_stmt(PythonParser::Break_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitContinue_stmt(PythonParser::Continue_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGlobal_stmt(PythonParser::Global_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNonlocal_stmt(PythonParser::Nonlocal_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction_def(PythonParser::Function_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLambdef(PythonParser::LambdefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf_stmt(PythonParser::If_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElif_stmt(PythonParser::Elif_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElse_block(PythonParser::Else_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFor_stmt(PythonParser::For_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhile_stmt(PythonParser::While_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClass_def(PythonParser::Class_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTry_finally_block(PythonParser::Try_finally_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTry_except_else_finally_block(PythonParser::Try_except_else_finally_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExcept_block(PythonParser::Except_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFinally_block(PythonParser::Finally_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatch_stmt(PythonParser::Match_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubject_expr(PythonParser::Subject_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatch_case(PythonParser::Match_caseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatch_case_default(PythonParser::Match_case_defaultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPattern(PythonParser::PatternContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAttr_pattern(PythonParser::Attr_patternContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(PythonParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction_params(PythonParser::Function_paramsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressions(PythonParser::ExpressionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(PythonParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignment_expression(PythonParser::Assignment_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNamed_expression(PythonParser::Named_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDisjunction(PythonParser::DisjunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConjunction(PythonParser::ConjunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInversion(PythonParser::InversionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComparison(PythonParser::ComparisonContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComp_op(PythonParser::Comp_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComp_eq(PythonParser::Comp_eqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComp_noteq(PythonParser::Comp_noteqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComp_lte(PythonParser::Comp_lteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComp_lt(PythonParser::Comp_ltContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComp_gte(PythonParser::Comp_gteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComp_gt(PythonParser::Comp_gtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComp_notin(PythonParser::Comp_notinContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComp_in(PythonParser::Comp_inContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSum(PythonParser::SumContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTerm(PythonParser::TermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactor(PythonParser::FactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPower(PythonParser::PowerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction_call_prim(PythonParser::Function_call_primContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSlice_prim(PythonParser::Slice_primContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitField_prim(PythonParser::Field_primContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_prim(PythonParser::Atom_primContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSlices(PythonParser::SlicesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSlice(PythonParser::SliceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom(PythonParser::AtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGroup(PythonParser::GroupContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArguments(PythonParser::ArgumentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArg_expression(PythonParser::Arg_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKwargs(PythonParser::KwargsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStarred_expression(PythonParser::Starred_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKwarg_or_starred(PythonParser::Kwarg_or_starredContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKwarg_or_double_starred(PythonParser::Kwarg_or_double_starredContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAs_targets(PythonParser::As_targetsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAs_target_list(PythonParser::As_target_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAs_target_tuple(PythonParser::As_target_tupleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAs_target(PythonParser::As_targetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAs_atom_name(PythonParser::As_atom_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAs_atom_tuple(PythonParser::As_atom_tupleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAs_atom_tuple_tuple(PythonParser::As_atom_tuple_tupleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAs_atom_list(PythonParser::As_atom_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSingle_target(PythonParser::Single_targetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSingle_subscript_attribute_target(PythonParser::Single_subscript_attribute_targetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitField_tprim(PythonParser::Field_tprimContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction_call_tprim(PythonParser::Function_call_tprimContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSlice_tprim(PythonParser::Slice_tprimContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_tprim(PythonParser::Atom_tprimContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitT_lookahead(PythonParser::T_lookaheadContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTargets(PythonParser::TargetsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTarget(PythonParser::TargetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDel_targets(PythonParser::Del_targetsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDel_target(PythonParser::Del_targetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStrings(PythonParser::StringsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitList(PythonParser::ListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTuple(PythonParser::TupleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSet(PythonParser::SetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDict(PythonParser::DictContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDouble_starred_kvpairs(PythonParser::Double_starred_kvpairsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDouble_starred_kvpair(PythonParser::Double_starred_kvpairContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKvpair(PythonParser::KvpairContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFor_if_clauses(PythonParser::For_if_clausesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFor_if_clause(PythonParser::For_if_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitListcomp(PythonParser::ListcompContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSetcomp(PythonParser::SetcompContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDictcomp(PythonParser::DictcompContext *ctx) override {
    return visitChildren(ctx);
  }


};

