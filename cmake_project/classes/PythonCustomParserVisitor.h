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
    bool logging = true;

    std::any visitExpressions(PythonParser::ExpressionsContext *ctx) override;
    std::any visitExpression(PythonParser::ExpressionContext *ctx) override;
    std::any visitDisjunction(PythonParser::DisjunctionContext *ctx) override;
    std::any visitConjunction(PythonParser::ConjunctionContext *ctx) override;
    std::any visitInversion(PythonParser::InversionContext *ctx) override;
    std::any visitComparison(PythonParser::ComparisonContext *ctx) override;
    std::any visitComp_op(PythonParser::Comp_opContext *ctx) override;
    std::any visitSum(PythonParser::SumContext *ctx) override;

    std::any visitSimple_assignment(PythonParser::Simple_assignmentContext *ctx) override;
    std::any visitAug_assignment(PythonParser::Aug_assignmentContext *ctx) override;
    std::any visitSimple_stmt(PythonParser::Simple_stmtContext *ctx) override;

    // std::any visitFile(PythonParser::FileContext *ctx) override;
};



#endif //PYTHONCUSTOMPARSERVISITOR_H
