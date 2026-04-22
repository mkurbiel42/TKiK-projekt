#include "TParserBaseVisitor.h"

using namespace antlrcpptest;
class TVisitor : public TParserBaseVisitor {
    public: 
    static std::string teehee;

    std::any visitReturn(TParser::ReturnContext* ctx){
        teehee.append(ctx->expr()->getText());
        std::cout<<"odwiedzon returna"<<std::endl;
        return visitChildren(ctx);
    }
};

std::string TVisitor::teehee = std::string("");