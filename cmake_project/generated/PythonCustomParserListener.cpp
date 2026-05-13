//
// Created by root on 5/7/26.
//

#include "PythonCustomParserListener.h"

using namespace std;

void PythonCustomParserListener::enterAssignment(PythonParser::AssignmentContext *ctx) {
    string alreadyDeclared;
    string notDeclared = "let ";

    for (auto d : ctx->as_targets()) {
        for (auto &t : d->as_target()) {
            bool alreadyPresentInScope = false;
            for (auto &s:scopes) {
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

    cout << "Deklarowane wczesniej: " << alreadyDeclared << endl;

    cout << "Deklarowane teraz: " << notDeclared << endl;
}
