//
// Created by komp on 14.05.2026.
//

#ifndef PYTHONCUSTOMPARSERVISITOR_H
#define PYTHONCUSTOMPARSERVISITOR_H

#include <list>

#include "PythonParserBaseVisitor.h"
#include "Scope.h"


class PythonCustomParserVisitor : public PythonParserBaseVisitor{
public:
    std::deque<Scope> scopes = {Scope()};
    std::list<std::string> errors = {};
    std::string translated;
    bool logging = false;
    std::string noneReplacement = "undefined";
    int indentCount = 4;
    int indentDepth = 0;

    std::any visitFile(PythonParser::FileContext *ctx) override;
    std::any visitStatements(PythonParser::StatementsContext *context) override;

    std::any visitExpressions(PythonParser::ExpressionsContext *ctx) override;
    std::any visitExpression(PythonParser::ExpressionContext *ctx) override;
    std::any visitFunction_def(PythonParser::Function_defContext *ctx) override;
    std::any visitLambdef(PythonParser::LambdefContext *ctx) override;

    std::any visitDisjunction(PythonParser::DisjunctionContext *ctx) override;
    std::any visitConjunction(PythonParser::ConjunctionContext *ctx) override;
    std::any visitInversion(PythonParser::InversionContext *ctx) override;

    std::any visitComparison(PythonParser::ComparisonContext *ctx) override;
    std::any visitComp_op(PythonParser::Comp_opContext *ctx) override;
    std::any visitSum(PythonParser::SumContext *ctx) override;

    std::any visitTerm(PythonParser::TermContext *ctx) override;
    std::any visitFactor(PythonParser::FactorContext *ctx) override;
    std::any visitPower(PythonParser::PowerContext *ctx) override;

    std::any visitField_prim(PythonParser::Field_primContext *ctx) override;
    std::any visitFunction_call_prim(PythonParser::Function_call_primContext *ctx) override;
    std::any visitSlice_prim(PythonParser::Slice_primContext *ctx) override;
    std::any visitAtom_prim(PythonParser::Atom_primContext *ctx) override;

    std::any visitAtom(PythonParser::AtomContext *ctx) override;
    std::any visitStrings(PythonParser::StringsContext *ctx) override;
    std::any visitTuple(PythonParser::TupleContext *ctx) override;
    std::any visitGroup(PythonParser::GroupContext *ctx) override;
    std::any visitSet(PythonParser::SetContext *ctx) override;
    std::any visitList(PythonParser::ListContext *ctx) override;
    std::any visitDict(PythonParser::DictContext *ctx) override;

    std::any visitDouble_starred_kvpairs(PythonParser::Double_starred_kvpairsContext *ctx) override;
    std::any visitDouble_starred_kvpair(PythonParser::Double_starred_kvpairContext *ctx) override;
    std::any visitKvpair(PythonParser::KvpairContext *ctx) override;

    std::any visitNamed_expression(PythonParser::Named_expressionContext *ctx) override;
    std::any visitAssignment_expression(PythonParser::Assignment_expressionContext *ctx) override;

    std::any visitSlices(PythonParser::SlicesContext *ctx) override;
    std::any visitSlice(PythonParser::SliceContext *ctx) override;

    std::any visitAs_targets(PythonParser::As_targetsContext *ctx) override;
    std::any visitAs_target(PythonParser::As_targetContext *ctx) override;
    std::any visitAs_target_list(PythonParser::As_target_listContext *ctx) override;
    std::any visitAs_target_tuple(PythonParser::As_target_tupleContext *ctx) override;
    std::any visitAs_atom_name(PythonParser::As_atom_nameContext *ctx) override;
    std::any visitAs_atom_tuple(PythonParser::As_atom_tupleContext *ctx) override;
    std::any visitAs_atom_tuple_tuple(PythonParser::As_atom_tuple_tupleContext *ctx) override;
    std::any visitAs_atom_list(PythonParser::As_atom_listContext *ctx) override;

    std::any visitSingle_target(PythonParser::Single_targetContext *ctx) override;
    std::any visitSingle_subscript_attribute_target(PythonParser::Single_subscript_attribute_targetContext *ctx) override;
    std::any visitField_tprim(PythonParser::Field_tprimContext *ctx) override;
    std::any visitFunction_call_tprim(PythonParser::Function_call_tprimContext *ctx) override;
    std::any visitSlice_tprim(PythonParser::Slice_tprimContext *ctx) override;
    std::any visitAtom_tprim(PythonParser::Atom_tprimContext *ctx) override;

    std::any visitTargets(PythonParser::TargetsContext *ctx) override;
    std::any visitTarget(PythonParser::TargetContext *ctx) override;
    std::any visitDel_targets(PythonParser::Del_targetsContext *ctx) override;
    std::any visitDel_target(PythonParser::Del_targetContext *ctx) override;

    std::any visitFunction_params(PythonParser::Function_paramsContext *ctx) override;
    std::any visitArguments(PythonParser::ArgumentsContext *ctx) override;
    std::any visitArg_expression(PythonParser::Arg_expressionContext *ctx) override;
    std::any visitStarred_expression(PythonParser::Starred_expressionContext *ctx) override;

    std::any visitSimple_assignment(PythonParser::Simple_assignmentContext *ctx) override;
    std::any visitAug_assignment(PythonParser::Aug_assignmentContext *ctx) override;
    std::any visitSimple_stmt(PythonParser::Simple_stmtContext *ctx) override;
    std::any visitStatement(PythonParser::StatementContext *ctx) override;

    std::any visitReturn_stmt(PythonParser::Return_stmtContext *ctx) override;
    std::any visitPass_stmt(PythonParser::Pass_stmtContext *ctx) override;
    std::any visitDel_stmt(PythonParser::Del_stmtContext *ctx) override;
    std::any visitBreak_stmt(PythonParser::Break_stmtContext *ctx) override;
    std::any visitContinue_stmt(PythonParser::Continue_stmtContext *ctx) override;
    std::any visitGlobal_stmt(PythonParser::Global_stmtContext *ctx) override;
    std::any visitNonlocal_stmt(PythonParser::Nonlocal_stmtContext *ctx) override;

    std::any visitIf_stmt(PythonParser::If_stmtContext *ctx) override;
    std::any visitElif_stmt(PythonParser::Elif_stmtContext *ctx) override;
    std::any visitElse_block(PythonParser::Else_blockContext *ctx) override;

    std::any visitFor_stmt(PythonParser::For_stmtContext *ctx) override;

    std::any visitWhile_stmt(PythonParser::While_stmtContext *ctx) override;

    std::any visitClass_def(PythonParser::Class_defContext *ctx) override;

    std::any visitMatch_stmt(PythonParser::Match_stmtContext *ctx) override;
    std::any visitSubject_expr(PythonParser::Subject_exprContext *ctx) override;
    std::any visitMatch_case(PythonParser::Match_caseContext *ctx) override;
    std::any visitMatch_case_default(PythonParser::Match_case_defaultContext *ctx) override;
    std::any visitPattern(PythonParser::PatternContext *ctx) override;

    std::any visitFor_if_clauses(PythonParser::For_if_clausesContext *ctx) override;
    std::any visitFor_if_clause(PythonParser::For_if_clauseContext *ctx) override;
    std::any visitListcomp(PythonParser::ListcompContext *ctx) override;
    std::any visitDictcomp(PythonParser::DictcompContext *ctx) override;
    std::any visitSetcomp(PythonParser::SetcompContext *ctx) override;

    std::any visitRaise_stmt(PythonParser::Raise_stmtContext *ctx) override;
    std::any visitTry_finally_block(PythonParser::Try_finally_blockContext *ctx) override;
    std::any visitTry_except_else_finally_block(PythonParser::Try_except_else_finally_blockContext *ctx) override;
    std::any visitExcept_block_normal(PythonParser::Except_block_normalContext *ctx) override;
    std::any visitExcept_as_block(PythonParser::Except_as_blockContext *ctx) override;
    std::any visitFinally_block(PythonParser::Finally_blockContext *ctx) override;

    std::any visitBlock(PythonParser::BlockContext *ctx) override;
};



#endif //PYTHONCUSTOMPARSERVISITOR_H
