grammar Python;

// tokens and helpers

tokens {
    DEDENT, INDENT, ENDMARKER
}

NAME: [a-zA-Z_][a-zA-Z0-9_]*;
NUMBER: INTEGER | FLOAT;
STRING: '"' ~[\\\r\n"]*? '"' | '\'' ~[\\\r\n']*? '\'';
NEWLINE: '\r\n' | '\n';

fragment INTEGER:   [1-9] [0-9]*;
fragment FLOAT:     [1-9] [0-9]* '.' [0-9]+;


// starting rule
file: statements? ENDMARKER;

// whitespace skips
SPACE: ' ' -> skip;

// general statements
statements: statement+;
statement: simple_stmt | compound_stmt;
simple_stmt: assignment | expressions | return_stmt | raise_stmt | pass_stmt;
compound_stmt: function_def | if_stmt | class_def | for_stmt | while_stmt | match_stmt;

// simple statements
assignment: (targets '=')+ expressions ~'=';
return_stmt: 'return' expression?;
raise_stmt: 'raise' expression?;
pass_stmt: 'pass';
del_stmt: 'del' del_targets;
break_stmt: 'break';
continue_stmt: 'continue';
global_stmt: 'global' NAME (',' NAME)*;
nonlocal_stmt: 'nonlocal' NAME (',' NAME)*;


// compound statements

//function definition
function_def: 'def' NAME '(' function_params? ')' block;

// lambda function def
lambdef: 'lambda' function_params? ':' expression;

// if stmt
if_stmt: 'if' named_expression ':' block (elif_stmt | else_block?);
elif_stmt: 'elif' named_expression ':' block (elif_stmt | else_block?);
else_block: 'else' ':' block;

// for stmt
for_stmt: 'for' targets 'in' expressions ':' block else_block?;

// while stmt
while_stmt: 'while' named_expression ':' block;

// class definition
class_def: 'class' NAME ('(' arguments? ')')? ':' block;

// try stmt
try_stmt: 'try' ':' block finally_block                         #try_finally_block
    | 'try' ':' block except_block+ else_block? finally_block?  #try_except_else_finally_block
    ;

except_block: 'except' (expression | expressions)? ':' block;
finally_block: 'finally' ':' block;

// match case stmt
match_stmt: 'match' subject_expr ':' NEWLINE INDENT case_block+ DEDENT;
subject_expr: named_expression ',' named_expression? | named_expression;
case_block: 'case' pattern ':' block    #match_case
    | 'case' '_' ':' block              #match_case_default
    ;
pattern: NAME | attr_pattern;
attr_pattern: (NAME '.')+ NAME;

// compound statements common elements
block: NEWLINE INDENT statements DEDENT;

// function type parameters
function_params: NAME (',' NAME)*;

// expressions
expressions: expression (',' expression)* ','?;
expression: disjunction 'if' disjunction 'else' expression
    | disjunction
    | lambdef;
assignment_expression: NAME ':=' expression;
named_expression:
    assignment_expression | expression ~':=';

disjunction: conjunction ('or' conjunction)*;
conjunction: inversion ('and' inversion)*;
inversion: 'not' inversion | comparison;

// comparison operators
comparison: sum comp_op+ | sum;
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
primary: primary '.' NAME           #field_prim
    | primary '(' arguments? ')'    #function_call_prim
    | primary '[' slices ']'        #slice_prim
    | atom                          #atom_prim
    ;
slices: slice ~',' | ((slice | expression) (',' (slice | expression))*) ','?;
slice: expression? ':' expression? (':' expression?)? | named_expression;
atom: NAME | 'True' | 'False' | 'None' | strings | NUMBER | tuple | list | listcomp | dict | dictcomp | set | setcomp;

// function call arguments
arguments: arg_expression (',' arg_expression)* ','?;
arg_expression: (starred_expression | (assignment_expression | expression ~':=') ~'=');

kwargs: kwarg_or_starred (',' kwarg_or_starred)* ',' kwarg_or_double_starred (',' kwarg_or_double_starred)*
    | kwarg_or_starred (',' kwarg_or_starred)*
    | kwarg_or_double_starred (',' kwarg_or_double_starred)*;
starred_expression: '*' expression;
kwarg_or_starred: NAME '=' expression | starred_expression;
kwarg_or_double_starred: NAME '=' expression | '**' expression;

// generic targets
targets: target ~',' | target (',' target)* ','?;
target: primary '.' NAME | primary '[' slices ']' | atom;

// del statement targets
del_targets: del_target (',' del_target)* ','?;
del_target: primary '.' NAME | primary '[' slices ']' | NAME;

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
listcomp: '[' named_expression for_if_clauses ']';
setcomp: '{' named_expression for_if_clauses '}';
dictcomp: '{' kvpair for_if_clauses '}';