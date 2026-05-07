#include <PythonParserBaseListener.h>
#include <PythonParserListener.h>
//
// Created by root on 5/7/26.
//
class PythonCustomParserListener : public PythonParserBaseListener{
    void enterStatement(PythonParser::StatementContext* ctx) override;
    void exitStatement(PythonParser::StatementContext* ctx) override;
};