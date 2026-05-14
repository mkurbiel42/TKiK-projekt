//
// Created by komp on 14.05.2026.
//

#include "PythonCustomParserVisitor.h"

using namespace std;

std::any PythonCustomParserVisitor::visitSimple_stmt(PythonParser::Simple_stmtContext *ctx) {
    // if (ctx->ass)
}

std::any PythonCustomParserVisitor::visitSimple_assignment(PythonParser::Simple_assignmentContext *ctx) {
    string alreadyDeclared;
    string notDeclared = "let ";

    if (ctx->expressions()->expression().size() != 1) {
        cout << "Multiple values assignment is not supported by JavaScript" << endl;
        return "";
    }

    for (auto d : ctx->as_targets()) {
        for (auto &t : d->as_target()) {
            bool alreadyPresentInScope = false;
            for (auto &s: scopes) {
                if (s.names.contains(t->getText()) || s.nonLocals.contains(t->getText()) || s.globals.contains(t->getText())) {
                    alreadyPresentInScope = true;
                }
            }

            if (t->BRACKET_LEFT() || t->NAME() || alreadyPresentInScope) {
                if (!alreadyDeclared.empty())
                    alreadyDeclared.append(", ");
                alreadyDeclared.append(t->getText());
            }else {
                if (notDeclared != "let ")
                    notDeclared.append(", ");
                notDeclared.append(t->getText());
                scopes.back().names.insert(t->getText());
            }
        }
    }

    if (!translated.empty()) {
        translated.append("\n");
    }

    auto exprResult = any_cast<string>(visitExpression(ctx->expressions()->expression()[0]));

    string result;

    if (!alreadyDeclared.empty()) {
        alreadyDeclared.append(" = ").append(exprResult);
        result += alreadyDeclared;

    }

    if (notDeclared != "let ") {
        notDeclared.append(" = ").append(exprResult);
    }

    if (logging) {
        cout << "Deklarowane wczesniej: " << alreadyDeclared << endl;
        cout << "Deklarowane teraz: " << notDeclared << endl;
    }


    return result;
}

std::any PythonCustomParserVisitor::visitAug_assignment(PythonParser::Aug_assignmentContext *ctx) {
    string result;

    auto target = ctx->single_target();
    bool alreadyPresentInScope = false;

    for (auto &s: scopes) {
        if (s.names.contains(target->getText()) || s.nonLocals.contains(target->getText()) || s.globals.contains(target->getText())) {
            alreadyPresentInScope = true;
        }
    }
    if (!alreadyPresentInScope) {
        cout << "Can't augassign to an uninitialized variable" << endl;
        return "";
    }

    if (ctx->augassign()->DOUBLESLASHEQUAL()) {
        result.append(target->getText())
            .append(" = ~~(")
            .append(target->getText())
            .append("/")
            .append(any_cast<string>(visitExpressions(ctx->expressions())))
            .append(")");
    }else {
        result.append(target->getText())
        .append(" ")
        .append(ctx->augassign()->getText())
        .append(" ")
        .append(any_cast<string>(visitExpressions(ctx->expressions())));
    }

    if (!translated.empty())
        translated.append("\n");

    translated.append(result).append("\n");

    return result;
}



any PythonCustomParserVisitor::visitExpressions(PythonParser::ExpressionsContext *ctx) {
    string result;

    for (const auto &e : ctx->expression()) {
        if (!result.empty())
            result.append(", ");

        result.append(any_cast<string>(visitExpression(e)));
    }

    return result;
}

any PythonCustomParserVisitor::visitExpression(PythonParser::ExpressionContext *ctx) {
    if (ctx->lambdef()) {
        auto lambdef = ctx->lambdef();
        string result = "(";
        if (lambdef->function_params())
            result.append(lambdef->function_params()->getText());
        result.append(") => ");
        result.append(any_cast<string>(visitExpression(lambdef->expression())));

        return result;
    }

    if (ctx->IF()) {
        auto disj1 = ctx->disjunction()[0];
        auto disj2 = ctx->disjunction()[1];
        auto disj1Processed = any_cast<string>(visitDisjunction(disj1));
        auto disj2Processed = any_cast<string>(visitDisjunction(disj2));
        auto exprProcessed = any_cast<string>(visitExpression(ctx->expression()));

        string result = disj2Processed.append(" ? ").append(disj1Processed).append(" : ").append(exprProcessed);
    }

    string result = any_cast<string>(visitDisjunction(ctx->disjunction()[0]));

    return result;
}

std::any PythonCustomParserVisitor::visitDisjunction(PythonParser::DisjunctionContext *ctx) {
    string result;

    // if (ctx->conjunction().size() != 1)
    //     result += "(";

    for (auto &c : ctx->conjunction()) {
        if (result != "(" && !result.empty())
            result.append(" || ");
        result.append(any_cast<string>(visitConjunction(c)));
    }

    // if (ctx->conjunction().size() != 1)
    //     result += ")";

    return result;
}

std::any PythonCustomParserVisitor::visitConjunction(PythonParser::ConjunctionContext *ctx) {
    string result;

    if (ctx->inversion().size() != 1)
        result += "(";

    for (auto &i : ctx->inversion()) {
        if (result != "(" && !result.empty())
            result.append(" && ");
        result.append(any_cast<string>(visitInversion(i)));
    }

    if (ctx->inversion().size() != 1)
        result += ")";

    return result;
}

std::any PythonCustomParserVisitor::visitInversion(PythonParser::InversionContext *ctx) {

    if (ctx->inversion()) {
        string result = "(!" + any_cast<string>(visitInversion(ctx->inversion())) + ")";
        return result;
    }

    string result = any_cast<string>(visitComparison(ctx->comparison()));
    return result;
}

std::any PythonCustomParserVisitor::visitComparison(PythonParser::ComparisonContext *ctx) {
    string result;

    string sumResult = any_cast<string>(visitSum(ctx->sum()));

    for (auto &c : ctx->comp_op()) {
        if (!result.empty())
            result += " ";

        string compOpResult = any_cast<string>(visitComp_op(c));

        if (c->comp_in() || c->comp_notin())
            result += compOpResult + sumResult + ")";
        else
            result += sumResult + compOpResult;
    }

    if (!result.empty())
        result += " ";

    return sumResult + result;
}

std::any PythonCustomParserVisitor::visitComp_op(PythonParser::Comp_opContext *ctx) {
    string result;
    if (ctx->comp_eq()) {
        result += " == ";
        result += any_cast<string>(visitSum(ctx->comp_eq()->sum()));
    }

    if (ctx->comp_noteq()) {
        result += " != ";
        result += any_cast<string>(visitSum(ctx->comp_noteq()->sum()));
    }

    if (ctx->comp_gt()) {
        result += " > ";
        result += any_cast<string>(visitSum(ctx->comp_gt()->sum()));
    }

    if (ctx->comp_gte()) {
        result += " >= ";
        result += any_cast<string>(visitSum(ctx->comp_gte()->sum()));
    }

    if (ctx->comp_lt()) {
        result += " < ";
        result += any_cast<string>(visitSum(ctx->comp_lt()->sum()));
    }

    if (ctx->comp_lte()) {
        result += " <= ";
        result += any_cast<string>(visitSum(ctx->comp_lte()->sum()));
    }

    if (ctx->comp_in()) {
        result += any_cast<string>(visitSum(ctx->comp_in()->sum()));
        result += ".includes(";
    }

    if (ctx->comp_notin()) {
        result += "!";
        result += any_cast<string>(visitSum(ctx->comp_in()->sum()));
        result += " .includes(";
    }



    return result;
}

std::any PythonCustomParserVisitor::visitSum(PythonParser::SumContext *ctx) {
    string result = ctx->getText();
    return result;
}

// std::any PythonCustomParserVisitor::visitFile(PythonParser::FileContext *ctx) {
//     visitChildren(ctx);
//
//     if (logging) {
//         cout << "================" << endl;
//         cout << "Przetlumaczone:" << endl << translated << endl;
//         cout << "================" << endl;
//     }
//
//     return translated;
// }
