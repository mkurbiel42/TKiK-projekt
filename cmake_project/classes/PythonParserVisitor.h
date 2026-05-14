
// Generated from ./PythonParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "PythonParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by PythonParser.
 */
class  PythonParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by PythonParser.
   */
    virtual std::any visitFile(PythonParser::FileContext *context) = 0;

    virtual std::any visitStatements(PythonParser::StatementsContext *context) = 0;

    virtual std::any visitStatement(PythonParser::StatementContext *context) = 0;

    virtual std::any visitSimple_stmt(PythonParser::Simple_stmtContext *context) = 0;

    virtual std::any visitCompound_stmt(PythonParser::Compound_stmtContext *context) = 0;

    virtual std::any visitSimple_assignment(PythonParser::Simple_assignmentContext *context) = 0;

    virtual std::any visitAug_assignment(PythonParser::Aug_assignmentContext *context) = 0;

    virtual std::any visitAugassign(PythonParser::AugassignContext *context) = 0;

    virtual std::any visitReturn_stmt(PythonParser::Return_stmtContext *context) = 0;

    virtual std::any visitRaise_stmt(PythonParser::Raise_stmtContext *context) = 0;

    virtual std::any visitPass_stmt(PythonParser::Pass_stmtContext *context) = 0;

    virtual std::any visitDel_stmt(PythonParser::Del_stmtContext *context) = 0;

    virtual std::any visitBreak_stmt(PythonParser::Break_stmtContext *context) = 0;

    virtual std::any visitContinue_stmt(PythonParser::Continue_stmtContext *context) = 0;

    virtual std::any visitGlobal_stmt(PythonParser::Global_stmtContext *context) = 0;

    virtual std::any visitNonlocal_stmt(PythonParser::Nonlocal_stmtContext *context) = 0;

    virtual std::any visitFunction_def(PythonParser::Function_defContext *context) = 0;

    virtual std::any visitLambdef(PythonParser::LambdefContext *context) = 0;

    virtual std::any visitIf_stmt(PythonParser::If_stmtContext *context) = 0;

    virtual std::any visitElif_stmt(PythonParser::Elif_stmtContext *context) = 0;

    virtual std::any visitElse_block(PythonParser::Else_blockContext *context) = 0;

    virtual std::any visitFor_stmt(PythonParser::For_stmtContext *context) = 0;

    virtual std::any visitWhile_stmt(PythonParser::While_stmtContext *context) = 0;

    virtual std::any visitClass_def(PythonParser::Class_defContext *context) = 0;

    virtual std::any visitTry_finally_block(PythonParser::Try_finally_blockContext *context) = 0;

    virtual std::any visitTry_except_else_finally_block(PythonParser::Try_except_else_finally_blockContext *context) = 0;

    virtual std::any visitExcept_block(PythonParser::Except_blockContext *context) = 0;

    virtual std::any visitFinally_block(PythonParser::Finally_blockContext *context) = 0;

    virtual std::any visitMatch_stmt(PythonParser::Match_stmtContext *context) = 0;

    virtual std::any visitSubject_expr(PythonParser::Subject_exprContext *context) = 0;

    virtual std::any visitMatch_case(PythonParser::Match_caseContext *context) = 0;

    virtual std::any visitMatch_case_default(PythonParser::Match_case_defaultContext *context) = 0;

    virtual std::any visitPattern(PythonParser::PatternContext *context) = 0;

    virtual std::any visitAttr_pattern(PythonParser::Attr_patternContext *context) = 0;

    virtual std::any visitBlock(PythonParser::BlockContext *context) = 0;

    virtual std::any visitFunction_params(PythonParser::Function_paramsContext *context) = 0;

    virtual std::any visitExpressions(PythonParser::ExpressionsContext *context) = 0;

    virtual std::any visitExpression(PythonParser::ExpressionContext *context) = 0;

    virtual std::any visitAssignment_expression(PythonParser::Assignment_expressionContext *context) = 0;

    virtual std::any visitNamed_expression(PythonParser::Named_expressionContext *context) = 0;

    virtual std::any visitDisjunction(PythonParser::DisjunctionContext *context) = 0;

    virtual std::any visitConjunction(PythonParser::ConjunctionContext *context) = 0;

    virtual std::any visitInversion(PythonParser::InversionContext *context) = 0;

    virtual std::any visitComparison(PythonParser::ComparisonContext *context) = 0;

    virtual std::any visitComp_op(PythonParser::Comp_opContext *context) = 0;

    virtual std::any visitComp_eq(PythonParser::Comp_eqContext *context) = 0;

    virtual std::any visitComp_noteq(PythonParser::Comp_noteqContext *context) = 0;

    virtual std::any visitComp_lte(PythonParser::Comp_lteContext *context) = 0;

    virtual std::any visitComp_lt(PythonParser::Comp_ltContext *context) = 0;

    virtual std::any visitComp_gte(PythonParser::Comp_gteContext *context) = 0;

    virtual std::any visitComp_gt(PythonParser::Comp_gtContext *context) = 0;

    virtual std::any visitComp_notin(PythonParser::Comp_notinContext *context) = 0;

    virtual std::any visitComp_in(PythonParser::Comp_inContext *context) = 0;

    virtual std::any visitSum(PythonParser::SumContext *context) = 0;

    virtual std::any visitTerm(PythonParser::TermContext *context) = 0;

    virtual std::any visitFactor(PythonParser::FactorContext *context) = 0;

    virtual std::any visitPower(PythonParser::PowerContext *context) = 0;

    virtual std::any visitFunction_call_prim(PythonParser::Function_call_primContext *context) = 0;

    virtual std::any visitSlice_prim(PythonParser::Slice_primContext *context) = 0;

    virtual std::any visitField_prim(PythonParser::Field_primContext *context) = 0;

    virtual std::any visitAtom_prim(PythonParser::Atom_primContext *context) = 0;

    virtual std::any visitSlices(PythonParser::SlicesContext *context) = 0;

    virtual std::any visitSlice(PythonParser::SliceContext *context) = 0;

    virtual std::any visitAtom(PythonParser::AtomContext *context) = 0;

    virtual std::any visitGroup(PythonParser::GroupContext *context) = 0;

    virtual std::any visitArguments(PythonParser::ArgumentsContext *context) = 0;

    virtual std::any visitArg_expression(PythonParser::Arg_expressionContext *context) = 0;

    virtual std::any visitKwargs(PythonParser::KwargsContext *context) = 0;

    virtual std::any visitStarred_expression(PythonParser::Starred_expressionContext *context) = 0;

    virtual std::any visitKwarg_or_starred(PythonParser::Kwarg_or_starredContext *context) = 0;

    virtual std::any visitKwarg_or_double_starred(PythonParser::Kwarg_or_double_starredContext *context) = 0;

    virtual std::any visitAs_targets(PythonParser::As_targetsContext *context) = 0;

    virtual std::any visitAs_target_list(PythonParser::As_target_listContext *context) = 0;

    virtual std::any visitAs_target_tuple(PythonParser::As_target_tupleContext *context) = 0;

    virtual std::any visitAs_target(PythonParser::As_targetContext *context) = 0;

    virtual std::any visitAs_atom_name(PythonParser::As_atom_nameContext *context) = 0;

    virtual std::any visitAs_atom_tuple(PythonParser::As_atom_tupleContext *context) = 0;

    virtual std::any visitAs_atom_tuple_tuple(PythonParser::As_atom_tuple_tupleContext *context) = 0;

    virtual std::any visitAs_atom_list(PythonParser::As_atom_listContext *context) = 0;

    virtual std::any visitSingle_target(PythonParser::Single_targetContext *context) = 0;

    virtual std::any visitSingle_subscript_attribute_target(PythonParser::Single_subscript_attribute_targetContext *context) = 0;

    virtual std::any visitField_tprim(PythonParser::Field_tprimContext *context) = 0;

    virtual std::any visitFunction_call_tprim(PythonParser::Function_call_tprimContext *context) = 0;

    virtual std::any visitSlice_tprim(PythonParser::Slice_tprimContext *context) = 0;

    virtual std::any visitAtom_tprim(PythonParser::Atom_tprimContext *context) = 0;

    virtual std::any visitT_lookahead(PythonParser::T_lookaheadContext *context) = 0;

    virtual std::any visitTargets(PythonParser::TargetsContext *context) = 0;

    virtual std::any visitTarget(PythonParser::TargetContext *context) = 0;

    virtual std::any visitDel_targets(PythonParser::Del_targetsContext *context) = 0;

    virtual std::any visitDel_target(PythonParser::Del_targetContext *context) = 0;

    virtual std::any visitStrings(PythonParser::StringsContext *context) = 0;

    virtual std::any visitList(PythonParser::ListContext *context) = 0;

    virtual std::any visitTuple(PythonParser::TupleContext *context) = 0;

    virtual std::any visitSet(PythonParser::SetContext *context) = 0;

    virtual std::any visitDict(PythonParser::DictContext *context) = 0;

    virtual std::any visitDouble_starred_kvpairs(PythonParser::Double_starred_kvpairsContext *context) = 0;

    virtual std::any visitDouble_starred_kvpair(PythonParser::Double_starred_kvpairContext *context) = 0;

    virtual std::any visitKvpair(PythonParser::KvpairContext *context) = 0;

    virtual std::any visitFor_if_clauses(PythonParser::For_if_clausesContext *context) = 0;

    virtual std::any visitFor_if_clause(PythonParser::For_if_clauseContext *context) = 0;

    virtual std::any visitListcomp(PythonParser::ListcompContext *context) = 0;

    virtual std::any visitSetcomp(PythonParser::SetcompContext *context) = 0;

    virtual std::any visitDictcomp(PythonParser::DictcompContext *context) = 0;


};

