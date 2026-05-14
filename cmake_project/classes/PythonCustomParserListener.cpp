//
// Created by root on 5/7/26.
//

#include "PythonCustomParserListener.h"

using namespace std;

string PythonCustomParserListener::processExpressions(PythonParser::ExpressionsContext *ctx) {
    string result;

    for (const auto &e : ctx->expression()) {
        if (!result.empty())
            result.append(", ");

        result.append(processExpression(e));
    }

    return result;
}

std::string PythonCustomParserListener::processExpression(PythonParser::ExpressionContext *ctx) {
    if (ctx->lambdef()) {
        auto lambdef = ctx->lambdef();
        string result = "(";
        if (lambdef->function_params())
            result.append(lambdef->function_params()->getText());
        result.append(") => ");
        result.append(processExpression(lambdef->expression()));

        return result;
    }

    if (ctx->IF()) {
        auto disj1 = ctx->disjunction()[0];
        auto disj2 = ctx->disjunction()[1];
        string disj1Processed = processDisjunction(disj1);
        string disj2Processed = processDisjunction(disj2);
        string exprProcessed = processExpression(ctx->expression());

        return disj2Processed.append(" ? ").append(disj1Processed).append(" : ").append(exprProcessed);
    }

    return processDisjunction(ctx->disjunction()[0]);
}

std::string PythonCustomParserListener::processDisjunction(PythonParser::DisjunctionContext *ctx) {
    string result;

    // if (ctx->conjunction().size() != 1)
    //     result += "(";

    for (auto &c : ctx->conjunction()) {
        if (result != "(" && !result.empty())
            result.append(" || ");
        result.append(processConjunction(c));
    }

    // if (ctx->conjunction().size() != 1)
    //     result += ")";

    return result;
}

std::string PythonCustomParserListener::processConjunction(PythonParser::ConjunctionContext *ctx) {
    string result;

    if (ctx->inversion().size() != 1)
        result += "(";

    for (auto &i : ctx->inversion()) {
        if (result != "(" && !result.empty())
            result.append(" && ");
        result.append(processInversion(i));
    }

    if (ctx->inversion().size() != 1)
        result += ")";

    return result;
}

std::string PythonCustomParserListener::processInversion(PythonParser::InversionContext *ctx) {
    if (ctx->inversion())
        return "(!" + processInversion(ctx->inversion()) + ")";

    return processComparison(ctx->comparison());
}

std::string PythonCustomParserListener::processComparison(PythonParser::ComparisonContext *ctx) {
    string result;
    for (auto &c : ctx->comp_op()) {
        if (!result.empty())
            result += " ";
        result += processCompOp(c);
    }

    if (!result.empty())
        result += " ";

    return result + processSum(ctx->sum());
}

std::string PythonCustomParserListener::processCompOp(PythonParser::Comp_opContext *ctx) {
    string result;
    if (ctx->comp_eq()) {
        result += " == ";
        result += processSum(ctx->comp_eq()->sum());
    }

    if (ctx->comp_noteq()) {
        result += " != ";
        result += processSum(ctx->comp_noteq()->sum());
    }

    if (ctx->comp_gt()) {
        result += " > ";
        result += processSum(ctx->comp_gt()->sum());
    }

    if (ctx->comp_gte()) {
        result += " >= ";
        result += processSum(ctx->comp_gte()->sum());
    }

    if (ctx->comp_lt()) {
        result += " < ";
        result += processSum(ctx->comp_lt()->sum());
    }

    if (ctx->comp_lte()) {
        result += " <= ";
        result += processSum(ctx->comp_lte()->sum());
    }

    return result;
}

std::string PythonCustomParserListener::processSum(PythonParser::SumContext *ctx) {
    return ctx->getText();
}




void PythonCustomParserListener::enterSimple_assignment(PythonParser::Simple_assignmentContext *ctx)
{
    string alreadyDeclared;
    string notDeclared = "let ";

    if (ctx->expressions()->expression().size() != 1){
        cout << "Multiple values assignment is not supported by JavaScript" << endl;
        return;
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

    if (!alreadyDeclared.empty()) {
        alreadyDeclared.append(" = ").append(processExpression(ctx->expressions()->expression()[0]));
        translated.append(alreadyDeclared).append(";\n");
    }

    if (notDeclared != "let ") {
        notDeclared.append(" = ").append(processExpression(ctx->expressions()->expression()[0]));
        translated.append(notDeclared).append(";\n");
    }

    if (logging) {
        cout << "Deklarowane wczesniej: " << alreadyDeclared << endl;
        cout << "Deklarowane teraz: " << notDeclared << endl;
    }
}

void PythonCustomParserListener::enterAug_assignment(PythonParser::Aug_assignmentContext *ctx) {
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
        return;
    }

    if (ctx->augassign()->DOUBLESLASHEQUAL()) {
        result.append(target->getText())
            .append(" = ~~(")
            .append(target->getText())
            .append("/")
            .append(processExpressions(ctx->expressions()))
            .append(")");
    }else {
        result.append(target->getText())
        .append(" ")
        .append(ctx->augassign()->getText())
        .append(" ")
        .append(processExpressions(ctx->expressions()));
    }

    if (!translated.empty())
        translated.append("\n");

    translated.append(result).append("\n");
}


void PythonCustomParserListener::exitFile(PythonParser::FileContext *ctx) {
    if (logging) {
        cout << "================" << endl;
        cout << "Przetlumaczone:" << endl << translated << endl;
        cout << "================" << endl;
    }

}
