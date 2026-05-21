//
// Created by komp on 13.05.2026.
//

#include "Scope.h"

Scope::Scope() {
    names = {};
    globals = {};
    nonLocals = {};
    name = FILESCOPE;
}

Scope::Scope(const ScopeName _name) {
    {
        names = {};
        globals = {};
        nonLocals = {};
        name = _name;
    }
}
