lexer grammar PythonLexer;

// tokens and temporary helpers

tokens {
    // DEDENT, INDENT, ENDMARKER, NEWLINE
    ENDMARKER
}

// temporary for testing
INDENT: BRACE_LEFT;
DEDENT: BRACE_RIGHT;
NEWLINE: '\r\n' | '\n';

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
PAR_LEFT: '(';
PAR_RIGHT: ')';
BRACKET_LEFT: '[';
BRACKET_RIGHT: ']';
BRACE_LEFT: '{';
BRACE_RIGHT: '}';
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