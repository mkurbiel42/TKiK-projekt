lexer grammar PythonLexer;

options{
    superClass = PythonLexerBase;
}

@header{#include "PythonLexerBase.h"}

// tokens and temporary helpers

tokens {
    DEDENT, INDENT, ENDMARKER
}

// temporary for testing
// INDENT: BRACE_LEFT;
// DEDENT: BRACE_RIGHT;
// NEWLINE: '\r\n' | '\n';

NEWLINE: ({this->atStartOfInput()}? SPACES | ( '\r'? '\n' | '\r' | '\f') SPACES?) {this->onNewLine();};

EQUALS: '=';
RETURN: 'return';
RAISE: 'raise';
PASS: 'pass';
DEL: 'del';
BREAK: 'break';
CONTINUE: 'continue';
GLOBAL: 'global';
NONLOCAL: 'nonlocal';
COMMA: ',';
DEF: 'def';
PAR_LEFT: '(' {this->openBrace();};
PAR_RIGHT: ')' {this->closeBrace();};
BRACKET_LEFT: '[' {this->openBrace();};
BRACKET_RIGHT: ']' {this->closeBrace();};
BRACE_LEFT: '{' {this->openBrace();};
BRACE_RIGHT: '}' {this->closeBrace();};
LAMBDA: 'lambda';
COLON: ':';
IF: 'if';
ELIF: 'elif';
ELSE: 'else';
FOR: 'for';
IN: 'in';
WHILE: 'while';
CLASS: 'class';
TRY: 'try';
EXCEPT: 'except';
FINALLY: 'finally';
MATCH: 'match';
CASE: 'case';
UNDERSCORE: '_';
DOT: '.';
WALRUS: ':=';
OR: 'or';
AND: 'and';
NOT: 'not';
PLUS: '+';
MINUS: '-';
STAR: '*';
SLASH: '/';
EQEQUAL: '==';
NOTEQUAL: '!=';
LESS: '<';
GREATER: '>';
LESSEQUAL: '<=';
GREATEREQUAL: '>=';
DOUBLESLASH: '//';
PERCENT: '%';
DOUBLESTAR: '**';
TRUE: 'True';
FALSE: 'False';
NONE: 'None';
PLUSEQUAL: '+=';
MINUSEQUAL: '-=';
STAREQUAL: '*=';
SLASHEQUAL: '/=';
PERCENTEQUAL: '%=';
DOUBLESTAREQUAL: '**=';
DOUBLESLASHEQUAL: '//=';

NAME: [a-zA-Z_][a-zA-Z0-9_]*;
NUMBER: INTEGER | FLOAT;
STRING: '"' ~[\\\r\n"]*? '"' | '\'' ~[\\\r\n']*? '\'';
WHITESPACESKIP: [\t ] -> skip;

fragment INTEGER:   [1-9] [0-9]*;
fragment FLOAT:     [1-9] [0-9]* '.' [0-9]+;
fragment SPACES: [ \t]+;