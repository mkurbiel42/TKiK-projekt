#include <list>
#include <PythonParserBaseListener.h>
#include <PythonParserListener.h>

#include "Scope.h"
//
// Created by root on 5/7/26.
//
class PythonCustomParserListener : public PythonParserBaseListener
{
    public:
    std::deque<Scope> scopes = {Scope()};
    std::list<std::string> errors = {};
    std::string translated;
    bool logging = true;

    // expression processing
    std::string processExpressions(PythonParser::ExpressionsContext *ctx);
    std::string processExpression(PythonParser::ExpressionContext *ctx);
    std::string processDisjunction(PythonParser::DisjunctionContext *ctx);
    std::string processConjunction(PythonParser::ConjunctionContext *ctx);
    std::string processInversion(PythonParser::InversionContext *ctx);
    std::string processComparison(PythonParser::ComparisonContext *ctx);
    std::string processCompOp(PythonParser::Comp_opContext *ctx);
    std::string processSum(PythonParser::SumContext *ctx);

    // statements processing
    void enterSimple_assignment(PythonParser::Simple_assignmentContext *ctx) override;
    void enterAug_assignment(PythonParser::Aug_assignmentContext *ctx) override;

    void exitFile(PythonParser::FileContext *ctx) override;
};