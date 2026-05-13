//
// Created by komp on 13.05.2026.
//

#ifndef SCOPE_H
#define SCOPE_H
#include <set>
#include <string>


class Scope {
public:
    std::set<std::string> names;
    std::set<std::string> globals;
    std::set<std::string> nonLocals;

    Scope() {
        names = {};
        globals = {};
        nonLocals = {};
    };
};



#endif //SCOPE_H
