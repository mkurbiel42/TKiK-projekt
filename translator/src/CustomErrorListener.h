//
// Created by admin on 22.05.2026.
//

#ifndef PROJECT_CUSTOMERRORLISTENER_H
#define PROJECT_CUSTOMERRORLISTENER_H
#include <list>

#include "antlr4-runtime.h"
#include "BaseErrorListener.h"

#endif //PROJECT_CUSTOMERRORLISTENER_H

class CustomErrorListener : public antlr4::BaseErrorListener{
public:
    bool error;
    std::list<std::string> errors;

    CustomErrorListener();
    void syntaxError(antlr4::Recognizer* recognizer, antlr4::Token* offendingSymbol, size_t line, size_t charPositionInLine, const std::string& msg, std::exception_ptr e) override;
};
