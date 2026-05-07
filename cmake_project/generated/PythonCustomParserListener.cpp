//
// Created by root on 5/7/26.
//

#include "PythonCustomParserListener.h"

void PythonCustomParserListener::enterStatement(PythonParser::StatementContext* ctx)
{
    std::cout << "entered statement: " << ctx->getText() << std::endl;
}

void PythonCustomParserListener::exitStatement(PythonParser::StatementContext* ctx)
{
    std::cout << "exited statemenet: " << ctx->getText() << std::endl;
}
