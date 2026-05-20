//
// Created by komp on 14.05.2026.
//

#include "PythonCustomParserVisitor.h"

using namespace std;

std::any PythonCustomParserVisitor::visitFile(PythonParser::FileContext *ctx) {
    if (!ctx->statements())
        return "";

    for (auto &s : ctx->statements()->statement()) {
        string sRes = any_cast<string>(visit(s));
        translated += sRes;
        cout << sRes;
    }

    return translated;
}


std::any PythonCustomParserVisitor::visitStatements(PythonParser::StatementsContext *ctx) {
    string result;

    for (auto &s : ctx->statement()) {
        result += any_cast<string>(visit(s));
    }

    return result;
}


std::any PythonCustomParserVisitor::visitStatement(PythonParser::StatementContext *ctx) {
    auto res = any_cast<string>(visit(ctx->children[0]));
    string tabs;

    for (int i=0; i<indentCount * indentDepth; i++)
        tabs += " ";

    return tabs + res + "\n";
}

std::any PythonCustomParserVisitor::visitBlock(PythonParser::BlockContext *ctx) {
    indentDepth += 1;
    string statementsResult = any_cast<string>(visit(ctx->statements()));
    indentDepth -= 1;

    return "{\n" + statementsResult + "}";
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

            if (!t->as_atom() || alreadyPresentInScope) {
                if (!alreadyDeclared.empty())
                    alreadyDeclared.append(", ");
                alreadyDeclared.append(any_cast<string>(visit(t)));
            }else {
                if (notDeclared != "let ")
                    notDeclared.append(", ");
                notDeclared.append(any_cast<string>(visit(t)));
                scopes.back().names.insert(t->getText());
            }
        }
    }

    auto exprResult = any_cast<string>(visitExpression(ctx->expressions()->expression()[0]));

    string result;

    if (!alreadyDeclared.empty()) {
        alreadyDeclared.append(" = ").append(exprResult);
        result += alreadyDeclared;
    }

    if (notDeclared != "let ") {
        if (!alreadyDeclared.empty())
            result += "\n";
        notDeclared.append(" = ").append(exprResult);
        result += notDeclared;
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
    if (ctx->lambdef())
        return visitLambdef(ctx->lambdef());

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

std::any PythonCustomParserVisitor::visitLambdef(PythonParser::LambdefContext *ctx) {
    string result = "(";
    if (ctx->function_params())
        result.append(any_cast<string>(visit(ctx->function_params())));
    result.append(") => ");
    result.append(any_cast<string>(visitExpression(ctx->expression())));

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

    if (ctx->NAME() && (ctx->NAME()->getText().contains("Error") || ctx->NAME()->getText().contains("Exception")))
        return "new Error";

    if (ctx->NAME() || ctx->NUMBER())
        return ctx->getText();

    if (ctx->TRUE() || ctx->FALSE()) {
        string text = ctx->getText();
        ranges::transform(text, text.begin(), [](unsigned char c){ return std::tolower(c); });
        return text;
    }

    return visit(ctx->children[0]);
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
    string targetResult = any_cast<string>(visit(target));

    string filters;
    string firstDisjunctionResult = any_cast<string>(visitDisjunction(ctx->disjunction()[0]));

    for (int i=0; i<ctx->IF().size(); i++) {
        filters += ".filter(" + targetResult + " => " + any_cast<string>(visitDisjunction(ctx->disjunction()[i+1])) + ")";
    }

    return firstDisjunctionResult + filters;
}

std::any PythonCustomParserVisitor::visitFor_if_clauses(PythonParser::For_if_clausesContext *ctx) {
    // if (ctx->for_if_clause().size() > 1) {
    //     cout << "Multiple for if clauses in array comprehension statements are not supported";
    //     return "";
    // }

    string forIfClausesResult;

    for (auto &fic : ctx->for_if_clause()) {
        forIfClausesResult += any_cast<string>(visitFor_if_clause(fic));
        string forIfClauseTarget = fic->targets()[0].target()[0]->getText();

        if (fic != ctx->for_if_clause().back())
            forIfClausesResult += ".flatMap(" + forIfClauseTarget + " => ";
        else
            forIfClausesResult += ".map(" + forIfClauseTarget + " => ";
    }

    return forIfClausesResult;
}

std::any PythonCustomParserVisitor::visitList(PythonParser::ListContext *ctx) {
    return "[" + any_cast<string>(visitExpressions(ctx->expressions())) + "]";
}

std::any PythonCustomParserVisitor::visitDict(PythonParser::DictContext *ctx) {
    string doubleStarredKVPairsResult = any_cast<string>(visit(ctx->double_starred_kvpairs()));

    return "{" + doubleStarredKVPairsResult + "}";
}

std::any PythonCustomParserVisitor::visitDouble_starred_kvpairs(PythonParser::Double_starred_kvpairsContext *ctx) {
    string result;
    for (auto &p : ctx->double_starred_kvpair()) {
        if (!result.empty())
            result += ", ";

        result += any_cast<string>(visit(p));
    }

    return "{" + result + "}";
}

std::any PythonCustomParserVisitor::visitDouble_starred_kvpair(PythonParser::Double_starred_kvpairContext *ctx) {
    if (ctx->kvpair())
        return visit(ctx->kvpair());

    string expressionResult = any_cast<string>(visit(ctx->expression()));

    return "..." + expressionResult;
}

std::any PythonCustomParserVisitor::visitKvpair(PythonParser::KvpairContext *ctx) {
    string keyResult = any_cast<string>(ctx->expression()[0]);
    string valResult = any_cast<string>(ctx->expression()[1]);

    return keyResult + ": " + valResult;
}

std::any PythonCustomParserVisitor::visitListcomp(PythonParser::ListcompContext *ctx) {
    string forIfClauseResult = any_cast<string>(visitFor_if_clauses(ctx->for_if_clauses()));

    auto expressionResult = any_cast<string>(visitNamed_expression(ctx->named_expression()));
    string result = forIfClauseResult + expressionResult;
    for (int i=0; i<ctx->for_if_clauses()->for_if_clause().size(); i++)
        result += ")";

    return result;
}

std::any PythonCustomParserVisitor::visitSetcomp(PythonParser::SetcompContext *ctx) {
    string listComp = "new Set(";
    listComp += any_cast<string>(visitListcomp(reinterpret_cast<PythonParser::ListcompContext*>(ctx)));
    listComp += ")";

    return listComp;
}

std::any PythonCustomParserVisitor::visitDictcomp(PythonParser::DictcompContext *ctx) {
    string forIfClauseResult = any_cast<string>(visitFor_if_clauses(ctx->for_if_clauses()));

    string keyResult = any_cast<string>(visitExpression(ctx->kvpair()->expression()[0]));
    string valueResult = any_cast<string>(visitExpression(ctx->kvpair()->expression()[1]));

    string result = "Object.fromEntries(";
    result += forIfClauseResult + "[" + keyResult + ", " + valueResult + "])";


    for (int i=0; i<ctx->for_if_clauses()->for_if_clause().size(); i++)
        result += ")";

    return result;
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
    // if (ctx->slice().size() == 1 && ctx->expression().empty())
    //     return visitSlice(ctx->slice()[0]);

    string result;

    for (auto &c : ctx->children) {
        if (dynamic_cast<PythonParser::SliceContext*>(c))
            result += any_cast<string>(visit(c));
        else if (dynamic_cast<PythonParser::ExpressionContext*>(c))
            result += "[" + any_cast<string>(visit(c)) + "]";
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

    if (ctx->children.front()->getText() == ":") {
        thirdArg = secondArg;
        secondArg = firstArg;
        firstArg = "0";
    }

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

std::any PythonCustomParserVisitor::visitAtom_tprim(PythonParser::Atom_tprimContext *ctx) {
    if (ctx->atom()->TRUE() || ctx->atom()->FALSE() || ctx->atom()->NONE() || ctx->atom()->strings() || ctx->atom()->NUMBER()) {
        cout << "Can't augassign to '" << ctx->atom()->getText() << "'" << endl;
        return "";
    }

    if (!ctx->atom()->NAME())
        return visitAtom(ctx->atom());

    string atomName = ctx->atom()->NAME()->getText();

    for (auto &s : scopes) {
        if (s.names.contains(atomName) || s.globals.contains(atomName) || s.nonLocals.contains(atomName))
            return visitAtom(ctx->atom());
    }

    cout << "Can't augassign to an undeclared variable" << endl;
    return "";
}

std::any PythonCustomParserVisitor::visitField_tprim(PythonParser::Field_tprimContext *ctx) {
    string tPrimResult = any_cast<string>(visit(ctx->t_primary()));

    return tPrimResult + "." + ctx->NAME()->getText();
}

std::any PythonCustomParserVisitor::visitSlice_tprim(PythonParser::Slice_tprimContext *ctx) {
    string tPrimResult = any_cast<string>(visit(ctx->t_primary()));
    string slicesResult = any_cast<string>(visitSlices(ctx->slices()));

    return tPrimResult + slicesResult;
}

std::any PythonCustomParserVisitor::visitFunction_call_tprim(PythonParser::Function_call_tprimContext *ctx) {
    string tPrimResult = any_cast<string>(visit(ctx->t_primary()));
    if (!ctx->arguments())
        return tPrimResult + "()";

    string argsResult = any_cast<string>(visit(ctx->arguments()));
    return tPrimResult + "(" + argsResult + ")";
}

std::any PythonCustomParserVisitor::visitArguments(PythonParser::ArgumentsContext *ctx) {
    string result;

    for (auto &a : ctx->arg_expression()) {
        if (!result.empty())
            result += ", ";

        result += any_cast<string>(visit(a));
    }

    return result;
}

std::any PythonCustomParserVisitor::visitFunction_params(PythonParser::Function_paramsContext *ctx) {
    string result;
    for (auto &p : ctx->NAME()) {
        if (p->getText() == "self")
            continue;
        if (!result.empty())
            result += ", ";
        result += p->getText();
    }

    return result;
}


std::any PythonCustomParserVisitor::visitArg_expression(PythonParser::Arg_expressionContext *ctx) {
    return visit(ctx->children[0]);
}

std::any PythonCustomParserVisitor::visitStarred_expression(PythonParser::Starred_expressionContext *ctx) {
    string expressionResult = any_cast<string>(visitExpression(ctx->expression()));

    return "..." + expressionResult;
}

std::any PythonCustomParserVisitor::visitSingle_subscript_attribute_target(PythonParser::Single_subscript_attribute_targetContext *ctx) {
    string tPrimResult = any_cast<string>(visit(ctx->t_primary()));

    if (!ctx->slices())
        return tPrimResult + "." + ctx->NAME()->getText();

    string slicesResult = any_cast<string>(visitSlices(ctx->slices()));
    return tPrimResult + slicesResult;
}

std::any PythonCustomParserVisitor::visitSingle_target(PythonParser::Single_targetContext *ctx) {
    if (ctx->NAME())
        return ctx->NAME()->getText();

    if (ctx->single_target())
        return "(" + any_cast<string>(visitSingle_target(ctx->single_target())) + ")";

    return visitSingle_subscript_attribute_target(ctx->single_subscript_attribute_target());
}

std::any PythonCustomParserVisitor::visitAs_target(PythonParser::As_targetContext *ctx) {
    if (ctx->as_atom())
        return visit(ctx->as_atom());

    string primaryResult = any_cast<string>(visit(ctx->primary()));

    if (!ctx->slices())
        return primaryResult + "." + ctx->NAME()->getText();

    string slicesResult = any_cast<string>(visit(ctx->slices()));
    return primaryResult + slicesResult;
}


std::any PythonCustomParserVisitor::visitAs_atom_name(PythonParser::As_atom_nameContext *ctx) {
    return ctx->NAME()->getText();
}

std::any PythonCustomParserVisitor::visitAs_atom_tuple(PythonParser::As_atom_tupleContext *ctx) {
    string asTargetResult = any_cast<string>(visit(ctx->as_target()));

    return "[" + asTargetResult + "]";
}

std::any PythonCustomParserVisitor::visitAs_atom_tuple_tuple(PythonParser::As_atom_tuple_tupleContext *ctx) {
    string asTargetTupleResult;

    if (ctx->as_target_tuple())
        asTargetTupleResult = any_cast<string>(visit(ctx->as_target_tuple()));

    return "[" + asTargetTupleResult + "]";
}

std::any PythonCustomParserVisitor::visitAs_target_list(PythonParser::As_target_listContext *ctx) {
    string result;
    for (auto &t : ctx->as_target()) {
        if (!result.empty())
            result += ", ";

        result += any_cast<string>(visit(t));
    }

    return "[" + result + "]";
}

std::any PythonCustomParserVisitor::visitAs_target_tuple(PythonParser::As_target_tupleContext *ctx) {
    string result;
    for (auto &t : ctx->as_target()) {
        if (!result.empty())
            result += ", ";

        result += any_cast<string>(visit(t));
    }

    return "[" + result + "]";
}

std::any PythonCustomParserVisitor::visitAs_atom_list(PythonParser::As_atom_listContext *ctx) {
    string asTargetListResult;
    if (ctx->as_target_list())
        asTargetListResult = any_cast<string>(visit(ctx->as_target_list()));

    return "[" + asTargetListResult + "]";
}

std::any PythonCustomParserVisitor::visitAs_targets(PythonParser::As_targetsContext *ctx) {
    string result;

    for (auto &t : ctx->as_target()) {
        if (!result.empty())
            result += ", ";

        result += any_cast<string>(visit(t));
    }

    return result;
}

std::any PythonCustomParserVisitor::visitTarget(PythonParser::TargetContext *ctx) {
    if (ctx->atom())
        return visit(ctx->atom());

    string primaryResult = any_cast<string>(visit(ctx->primary()));

    if (!ctx->slices())
        return primaryResult + "." + ctx->NAME()->getText();

    string slicesResult = any_cast<string>(visit(ctx->slices()));

    return primaryResult + slicesResult;
}

std::any PythonCustomParserVisitor::visitTargets(PythonParser::TargetsContext *ctx) {
    string result;

    for (auto &t : ctx->target()) {
        if (!result.empty())
            result += ", ";

        result += any_cast<string>(visit(t));
    }

    return result;
}

std::any PythonCustomParserVisitor::visitDel_target(PythonParser::Del_targetContext *ctx) {
    if (ctx->NAME())
        return ctx->NAME()->getText();

    string primaryResult = any_cast<string>(visit(ctx->primary()));

    if (!ctx->slices())
        return primaryResult + "." + ctx->NAME()->getText();

    string slicesResult = any_cast<string>(visit(ctx->slices()));

    return primaryResult + slicesResult;
}

std::any PythonCustomParserVisitor::visitDel_targets(PythonParser::Del_targetsContext *ctx) {
    string result;

    for (auto &t : ctx->del_target()) {
        if (!result.empty())
            result += ", ";

        result += any_cast<string>(visit(t));
    }

    return result;
}

std::any PythonCustomParserVisitor::visitRaise_stmt(PythonParser::Raise_stmtContext *ctx) {
    if (!ctx->expression())
        return "throw " + noneReplacement;

    string expressionResult = any_cast<string>(visit(ctx->expression()));
    if (!expressionResult.starts_with("Error")) {
        cout << "Cannot raise " << ctx->expression()-> getText() << "as an exception" << endl;
        return "";
    }

    return "throw " + expressionResult;
}

std::any PythonCustomParserVisitor::visitExcept_block_normal(PythonParser::Except_block_normalContext *ctx) {
    if (ctx->expressions() && ctx->expressions()->expression().empty()) {
        cout << "Multiple exceptions in one except block are not supported" << endl;
        return "";
    }

    string blockResult = any_cast<string>(visitBlock(ctx->block()));

    // if (!ctx->expression() && !ctx->expressions())
    //     return "catch";

    return "catch" + blockResult;
}

std::any PythonCustomParserVisitor::visitExcept_as_block(PythonParser::Except_as_blockContext *ctx) {
    string blockResult = any_cast<string>(visitBlock(ctx->block()));
    return "catch(" + ctx->NAME()->getText() + ")" + blockResult;
}

std::any PythonCustomParserVisitor::visitFinally_block(PythonParser::Finally_blockContext *ctx) {
    string blockResult = any_cast<string>(visitBlock(ctx->block()));
    return "finally" + blockResult;
}

std::any PythonCustomParserVisitor::visitTry_finally_block(PythonParser::Try_finally_blockContext *ctx) {
    string blockResult = any_cast<string>(visitBlock(ctx->block()));
    string finallyBlockResult = any_cast<string>(visitFinally_block(ctx->finally_block()));

    return "try" + blockResult + finallyBlockResult;
}

std::any PythonCustomParserVisitor::visitTry_except_else_finally_block(PythonParser::Try_except_else_finally_blockContext *ctx) {
    if (ctx->except_block().size() > 1) {
        cout << "Multiple except blocks are not supported by JavaScript";
        return "";
    }

    if (ctx->else_block()) {
        cout << "Else block in try...catch statement is not supported by JavaScript";
        return "";
    }

    string blockResult = any_cast<string>(visitBlock(ctx->block()));
    string exceptBlockResult = any_cast<string>(visit(ctx->except_block()[0]));

    string result = "try" + blockResult + exceptBlockResult;

    if (ctx->finally_block()) {
        string finallyBlockResult = any_cast<string>(visitFinally_block(ctx->finally_block()));
        result += finallyBlockResult;
    }

    return result;
}

