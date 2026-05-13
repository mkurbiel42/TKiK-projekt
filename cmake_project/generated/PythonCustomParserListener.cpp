//
// Created by root on 5/7/26.
//

#include "PythonCustomParserListener.h"

void PythonCustomParserListener::enterAssignment(PythonParser::AssignmentContext *ctx) {
    std::string alreadyDeclared;
    std::string notDeclared;

    for (auto d : ctx->as_targets()) {
        for (auto t : d->as_target()) {
            if (t->as_atom())
        }
    }
}
