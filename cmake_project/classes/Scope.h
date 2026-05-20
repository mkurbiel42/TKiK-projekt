//
// Created by komp on 13.05.2026.
//

#ifndef SCOPE_H
#define SCOPE_H
#include <set>
#include <string>

enum ScopeName {
    FILESCOPE,
    FUNCSCOPE,
    FORLOOPSCOPE,
    WHILELOOPSCOPE,
    IFSCOPE,
    ELIFSCOPE,
    ELSESCOPE,
    MATCHSCOPE,
    TRYSCOPE,
    EXCEPTSCOPE,
    FINALLYSCOPE,
    CLASSSCOPE,
    BLOCKSCOPE,
    FORLOOPSTATEMENTSCOPE
};

class Scope {
public:
    std::set<std::string> names;
    std::set<std::string> globals;
    std::set<std::string> nonLocals;
    ScopeName name;

    Scope() {
        names = {};
        globals = {};
        nonLocals = {};
        name = FILESCOPE;
    };

    explicit Scope(const ScopeName _name) {
        names = {};
        globals = {};
        nonLocals = {};
        name = _name;
    };
};



#endif //SCOPE_H
