/*
[ e ] -> e?
e*
s.e+ -> (e (s e)*)

star_target -> target
bitwise_or -> sum
compare_op_bitwise_or_pair -> comp_op
<comp_name>_bitwise_or -> comp_<comp_name>
star_named_expression, named_expression, star_expression -> expression
opcjonalnie:
    - dodać bitwise operatory (straszliwie upierdliwe)
    - comp_notin, comp_in
*/

grammar PythonSimpler;

// starting rule
file: statements? ENDMARKER;

// temporary:
ENDLINE: [\r\n] -> skip;
SPACE: ' ' -> skip;


// general statements
statements: statement+;
statement: simple_stmts | compound_stmt;
simple_stmts: assignment;
compound_stmt: 'compound';

assignment: (targets '=')+ expressions ~'=';

// expressions
expressions: expression (',' expression)* ','?;
expression: primary | sum | logic_expression | comparison;

logic_expression: disjunction 'if' disjunction 'else' expression
    | disjunction
    | lambdef;

disjunction: conjunction ('or' conjunction)*;
conjunction: inversion ('and' inversion)*;
inversion: 'not' inversion;

// comparison operators
comparison: sum comp_op+;
comp_op: comp_eq | comp_noteq | comp_lte | comp_lt | comp_gte | comp_gt | comp_notin | comp_in;
comp_eq: '==' sum;
comp_noteq: '!=' sum;
comp_lte: '<=' sum;
comp_lt: '<' sum;
comp_gte: '>=' sum;
comp_gt: '>' sum;
comp_notin: 'not' 'in' sum;
comp_in: 'in' sum;

// arithmetic operators
sum: sum '+' term | sum '-' term | term;
term: term '*' factor | term '/' factor | term '//' factor | term '%' factor | factor;
factor: '+' factor | '-' factor | power;
power: primary '**' factor | primary;

// primary elements
primary: primary '.' NAME 
    | primary '(' arguments? ')'
    | primary '[' slices ']'
    | atom;
slices: slice ~',' | ((slice | expression) (',' (slice | expression))*) ','?;
slice: expression? ':' expression? (':' expression?)?;
atom: NAME | 'True' | 'False' | 'None' | strings | NUMBER | tuple | list | listcomp | dict | dictcomp | set | setcomp;

// function call arguments
arguments: args ','?;
args: expression (','(starred_expression | (expression ~'=')))*?;
kwargs: kwarg_or_starred (',' kwarg_or_starred)* ',' kwarg_or_double_starred (',' kwarg_or_double_starred)*
    | kwarg_or_starred (',' kwarg_or_starred)*
    | kwarg_or_double_starred (',' kwarg_or_double_starred)*;
starred_expression: '*' expression;
kwarg_or_starred: NAME '=' expression | starred_expression;
kwarg_or_double_starred: NAME '=' expression | '**' expression;

// assignment target
as_targets: as_target ~',' | as_target (',' as_target)* ','?;
as_target: t_primary '.'

// generic targets
targets: target ~',' | target (',' target)* ','?;
target: t_primary '.' NAME | t_primary '[' slices ']' | atom;
t_primary: t_primary '.' NAME 
    | t_primary '[' slices ']' 
    | t_primary '(' arguments? ')' 
    | atom;

// literals
strings: STRING+;
list: '[' expressions? ']';
tuple: '(' (expression ',' expressions?)? ')';
set: '{' expressions '}';

// dicts
dict: '{' double_starred_kvpairs? '}';
double_starred_kvpairs: double_starred_kvpair (',' double_starred_kvpair)* ','?;
double_starred_kvpair: '**' expression | kvpair;
kvpair: expression ':' expression;

// comprehension
for_if_clauses: for_if_clause+;
for_if_clause: 'for' targets 'in' disjunction ('if' disjunction)*;
listcomp: '[' expression for_if_clauses ']';
setcomp: '{' expression for_if_clauses '}';
dictcomp: '{' kvpair for_if_clauses '}';

lambdef: '$$$TODO$$$';



// tokens

ENDMARKER: '$END$';
NAME: [a-zA-Z_][a-zA-Z0-9_]*;
NUMBER: INTEGER | FLOAT;
STRING: '"' ~[\\\r\n"]*? '"' | '\'' ~[\\\r\n']*? '\'';
NEWLINE: '\r\n' | '\n';
INDENT: '\t';
DEDENT: '$DEDENT$';

fragment INTEGER:   [1-9] [0-9]*;
fragment FLOAT:     [1-9] [0-9]* '.' [0-9]+;