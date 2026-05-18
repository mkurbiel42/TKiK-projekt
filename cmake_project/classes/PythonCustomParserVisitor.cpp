//
// Created by komp on 14.05.2026.
//

#include "PythonCustomParserVisitor.h"

using namespace std;

std::any PythonCustomParserVisitor::visitStatement(PythonParser::StatementContext *ctx) {
    auto res = any_cast<string>(visit(ctx->children[0]));
    translated += res += "\n";
    return res;
}

std::any PythonCustomParserVisitor::visitSimple_stmt(PythonParser::Simple_stmtContext *ctx) {
    any anyRes = visit(ctx->children[0]);
    auto res = any_cast<string>(anyRes);
    return res;
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

    // if (!translated.empty()) {
    //     translated.append("\n");
    // }

    auto exprResult = any_cast<string>(visitExpression(ctx->expressions()->expression()[0]));

    string result;

    if (!alreadyDeclared.empty()) {
        alreadyDeclared.append(" = ").append(exprResult);
        result += alreadyDeclared += "\n";
    }

    if (notDeclared != "let ") {
        notDeclared.append(" = ").append(exprResult);
        result += notDeclared += "\n";
    }

    if (logging) {
        cout << "Deklarowane wczesniej: " << alreadyDeclared << endl;
        cout << "Deklarowane teraz: " << notDeclared << endl;
    }

    // translated.append(result);
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

    // if (!translated.empty())
    //     translated.append("\n");
    //
    // translated.append(result).append("\n");

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
        string disj1Processed = any_cast<string>(visitDisjunction(disj1));
        string disj2Processed = any_cast<string>(visitDisjunction(disj2));
        string exprProcessed = any_cast<string>(visitExpression(ctx->expression()));

        return disj2Processed.append(" ? ").append(disj1Processed).append(" : ").append(exprProcessed);
    }

    return any_cast<string>(visitDisjunction(ctx->disjunction()[0]));
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
    string compOpsResult;

    for (auto &c : ctx->comp_op()) {
        if (c == ctx->comp_op().front() && !c->comp_in() && ! c->comp_notin()) {
            result = sumResult;
        }

        if (!result.empty() && result != sumResult)
            result += " ";

        string compOpResult = any_cast<string>(visitComp_op(c));

        if (c->comp_in() || c->comp_notin())
            result += compOpResult + sumResult + ")";
        else
            result += compOpResult;
    }

    if (result.empty())
        result = sumResult;

    return result;
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
        result += any_cast<string>(visitSum(ctx->comp_notin()->sum()));
        result += ".includes(";
    }

    return result;
}

std::any PythonCustomParserVisitor::visitSum(PythonParser::SumContext *ctx) {
    string sumResult;
    string termResult;

    termResult = any_cast<string>(visitTerm(ctx->term()));

    if (!ctx->sum())
        return termResult;

    sumResult = any_cast<string>(visitSum(ctx->sum()));


    return sumResult + " " + ctx->children[1]->getText() + " " + termResult;
}

std::any PythonCustomParserVisitor::visitTerm(PythonParser::TermContext *ctx) {
    string factorResult;
    string termResult;

    factorResult = any_cast<string>(visitFactor(ctx->factor()));

    if (!ctx->term())
        return factorResult;

    termResult = any_cast<string>(visitTerm(ctx->term()));

    if (ctx->DOUBLESLASH()) {
        return "~~(" + termResult + " / " + factorResult + ")";
    }else {
        return termResult + " " + ctx->children[1]->getText() + " " + factorResult;
    }
}

std::any PythonCustomParserVisitor::visitFactor(PythonParser::FactorContext *ctx) {
    if (ctx->power())
        return any_cast<string>(visitPower(ctx->power()));
    else
        return ctx->children[0]->getText() + any_cast<string>(visitFactor(ctx->factor()));
}

std::any PythonCustomParserVisitor::visitPower(PythonParser::PowerContext *ctx) {
    string primaryResult;

    // primaryResult = any_cast<string>(visitChildren(ctx->primary()));

    primaryResult = any_cast<string>(visit(ctx->primary()));
    if (!ctx->factor())
        return primaryResult;

    string factorResult = any_cast<string>(visitFactor(ctx->factor()));
    return primaryResult + " ** " + factorResult;
}

std::any PythonCustomParserVisitor::visitField_prim(PythonParser::Field_primContext *ctx) {
    return ctx->getText();
}

std::any PythonCustomParserVisitor::visitFunction_call_prim(PythonParser::Function_call_primContext *ctx) {
    return ctx->getText();
}

std::any PythonCustomParserVisitor::visitSlice_prim(PythonParser::Slice_primContext *ctx) {
    string primaryResult = any_cast<string>(visit(ctx->primary()));
    string slicesResult = any_cast<string>(visitSlices(ctx->slices()));
    return primaryResult + slicesResult;
}

std::any PythonCustomParserVisitor::visitAtom_prim(PythonParser::Atom_primContext *ctx) {
    return any_cast<string>(visitAtom(ctx->atom()));
}

std::any PythonCustomParserVisitor::visitAtom(PythonParser::AtomContext *ctx) {
    if (ctx->NONE())
        return noneReplacement;

    if (ctx->strings())
        return visitStrings(ctx->strings());

    if (ctx->tuple())
        return visitTuple(ctx->tuple());

    if (ctx->set())
        return visitSet(ctx->set());

    if (ctx->listcomp())
        return visitListcomp(ctx->listcomp());

    if (ctx->setcomp())
        return visitSetcomp(ctx->setcomp());

    if (ctx->dictcomp())
        return visitDictcomp(ctx->dictcomp());

    return ctx->getText();
}

std::any PythonCustomParserVisitor::visitStrings(PythonParser::StringsContext *ctx) {
    string res = "\"";
    for (auto &s : ctx->STRING()) {
        string temp = s->getText();
        temp = temp.substr(1, temp.size() - 2);
        res += temp;
    }
    res += "\"";
    return res;
}

std::any PythonCustomParserVisitor::visitTuple(PythonParser::TupleContext *ctx) {
    string result = "[";
    result += any_cast<string>(visitExpression(ctx->expression()));

    if (ctx->expressions())
        result += any_cast<string>(visitExpressions(ctx->expressions()));

    result += "]";
    return result;
}

std::any PythonCustomParserVisitor::visitGroup(PythonParser::GroupContext *ctx) {
    return "(" + any_cast<string>(visitExpression(ctx->expression())) + ")";
}

std::any PythonCustomParserVisitor::visitSet(PythonParser::SetContext *ctx) {
    return "new Set([" + any_cast<string>(visitExpressions(ctx->expressions())) + "])";
}

std::any PythonCustomParserVisitor::visitFor_if_clause(PythonParser::For_if_clauseContext *ctx) {
    if (ctx->targets()->target().size() != 1) {
        cout << "Multiple targets for if clauses are not supported";
        return "";
    }

    auto target = ctx->targets()[0].target()[0];
    string targetResult = target->getText();

    // if (target->atom())
    //     targetResult = target->atom()->getText();
    // else {
    //     auto primary = target->primary();
    //     while (true) {
    //         if (auto atom_c = dynamic_cast<PythonParser::Atom_primContext*>(primary)) {
    //             targetResult = atom_c->getText();
    //             break;
    //         }
    //
    //         if (auto c = dynamic_cast<PythonParser::Field_primContext*>(primary))
    //             primary = c->primary();
    //         else if (auto c2 = dynamic_cast<PythonParser::Function_call_primContext*>(primary))
    //             primary = c2->primary();
    //         else if (auto c3 = dynamic_cast<PythonParser::Slice_primContext*>(primary))
    //             primary = c3->primary();
    //     }
    // }


    string filters;

    for (int i=0; i<ctx->IF().size(); i++) {
        filters += ".filter(" + targetResult + " => " + any_cast<string>(visitDisjunction(ctx->disjunction()[i+1])) + ")";
    }

    return filters;
}

std::any PythonCustomParserVisitor::visitFor_if_clauses(PythonParser::For_if_clausesContext *ctx) {
    if (ctx->for_if_clause().size() > 1) {
        cout << "Multiple for if clauses in array comprehension statements are not supported";
        return "";
    }

    string forIfClausesResult;

    for (auto &fic : ctx->for_if_clause()) {
        forIfClausesResult += any_cast<string>(visitFor_if_clause(fic));
    }

    string firstDisjunctionResult = any_cast<string>(visitDisjunction(ctx->for_if_clause()[0]->disjunction()[0]));

    return firstDisjunctionResult + forIfClausesResult;
}


std::any PythonCustomParserVisitor::visitListcomp(PythonParser::ListcompContext *ctx) {
    string forIfClauseResult = any_cast<string>(visitFor_if_clauses(ctx->for_if_clauses()));

    auto target = ctx->for_if_clauses()[0].for_if_clause()[0]->targets()[0].target()[0];
    string targetResult = target->getText();

    return forIfClauseResult + ".map(" + targetResult + " => " + any_cast<string>(visitNamed_expression(ctx->named_expression())) + ")";
}

std::any PythonCustomParserVisitor::visitSetcomp(PythonParser::SetcompContext *ctx) {
    string listComp = "new Set(";
    listComp += any_cast<string>(visitListcomp(reinterpret_cast<PythonParser::ListcompContext*>(ctx)));
    listComp += ")";

    return listComp;
}

std::any PythonCustomParserVisitor::visitDictcomp(PythonParser::DictcompContext *ctx) {
    string forIfClauseResult = any_cast<string>(visitFor_if_clauses(ctx->for_if_clauses()));

    auto target = ctx->for_if_clauses()[0].for_if_clause()[0]->targets()[0].target()[0];
    string targetResult = target->getText();
    string keyResult = any_cast<string>(visitExpression(ctx->kvpair()->expression()[0]));
    string valueResult = any_cast<string>(visitExpression(ctx->kvpair()->expression()[1]));

    return "Object.fromEntries(" + forIfClauseResult + ".map(" + targetResult + " => [" + targetResult + ", " + valueResult + "]))";
    // return forIfClauseResult + ".map(" + targetResult + " => " + any_cast<string>(visitNamed_expression(ctx->named_expression())) + ")" + ".reduce((acc, curr) => {acc[curr[0]] = curr[1]; return acc;}, {})";
}


std::any PythonCustomParserVisitor::visitNamed_expression(PythonParser::Named_expressionContext *ctx) {
    if (ctx->expression())
        return visitExpression(ctx->expression());

    return visitAssignment_expression(ctx->assignment_expression());
}

std::any PythonCustomParserVisitor::visitAssignment_expression(PythonParser::Assignment_expressionContext *ctx) {
    cout << "Assignment expressions are not supported by JavaScript (especially in strict mode)";
    return "";
}

std::any PythonCustomParserVisitor::visitSlices(PythonParser::SlicesContext *ctx) {
    if (ctx->slice().size() == 1 && ctx->expression().size() == 0)
        return visitSlice(ctx->slice()[0]);

    string result;

    for (auto &s : ctx->slice()) {
        if (!result.empty())
            result += "][";
        result += any_cast<string>(visitSlice(s));
    }

    for (auto &e : ctx->expression()) {
        if (!result.empty())
            result += "][";
        result += any_cast<string>(visitExpression(e));
    }

    return result;
}

std::any PythonCustomParserVisitor::visitSlice(PythonParser::SliceContext *ctx) {
    if (ctx->named_expression())
        return "[" + any_cast<string>(visitNamed_expression(ctx->named_expression())) + "]";

    string firstArg, secondArg, thirdArg;
    if (ctx->expression().size() >= 1)
        firstArg = any_cast<string>(visitExpression(ctx->expression()[0]));
    if (ctx->expression().size() >= 2)
        secondArg = any_cast<string>(visitExpression(ctx->expression()[1]));
    if (ctx->expression().size() >= 3)
        thirdArg = any_cast<string>(visitExpression(ctx->expression()[2]));

    string result = ".slice(";
    if (!firstArg.empty())
        result += firstArg;
    if (!secondArg.empty())
        result += ", " + secondArg;
    result += ")";

    if (!thirdArg.empty()) {
        result += ".filter((_, idx) => idx % " + thirdArg + " == 0)";
    }

    return result;
}


