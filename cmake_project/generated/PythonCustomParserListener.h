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
    void enterAssignment(PythonParser::AssignmentContext *ctx) override;
};