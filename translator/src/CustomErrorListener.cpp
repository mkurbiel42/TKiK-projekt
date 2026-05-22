#include "CustomErrorListener.h"

#include "antlr4-runtime.h"

CustomErrorListener::CustomErrorListener(){
    error = false;
}

void CustomErrorListener::syntaxError(antlr4::Recognizer* recognizer, antlr4::Token* offendingSymbol, size_t line, size_t charPositionInLine, const std::string& msg, std::exception_ptr e){
    error = true;
}
