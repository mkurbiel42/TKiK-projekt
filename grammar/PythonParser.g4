parser grammar PythonParser;

options { tokenVocab=PythonLexer; }

// starting rule
file: statements? ENDMARKER;

// general statements
statements: statement+;
statement: compound_stmt | simple_stmt;
simple_stmt: (assignment | expressions | return_stmt | raise_stmt | pass_stmt | del_stmt | break_stmt | continue_stmt | global_stmt | nonlocal_stmt) NEWLINE;
compound_stmt: function_def | if_stmt | class_def | for_stmt | while_stmt | match_stmt;

// simple statements
assignment: (as_targets EQUALS)+ expressions
    | single_target augassign expressions;
augassign: PLUSEQUAL
    | MINUSEQUAL
    | STAREQUAL
    | SLASHEQUAL
    | PERCENTEQUAL
    | DOUBLESTAREQUAL
    | DOUBLESLASHEQUAL;
return_stmt: RETURN expression?;
raise_stmt: RAISE expression?;
pass_stmt: PASS;
del_stmt: DEL del_targets;
break_stmt: BREAK;
continue_stmt: CONTINUE;
global_stmt: GLOBAL NAME (COMMA NAME)*;
nonlocal_stmt: NONLOCAL NAME (COMMA NAME)*;


// compound statements

//function definition
function_def: 'def' NAME PAR_LEFT function_params? PAR_RIGHT COLON block;

// lambda function def
lambdef: LAMBDA function_params? COLON expression;

// if stmt
if_stmt: IF named_expression COLON block (elif_stmt | else_block?);
elif_stmt: ELSE named_expression COLON block (elif_stmt | else_block?);
else_block: ELSE COLON block;

// for stmt
for_stmt: FOR targets IN expressions COLON block else_block?;

// while stmt
while_stmt: WHILE named_expression COLON block;

// class definition
class_def: CLASS NAME (PAR_LEFT arguments? PAR_RIGHT)? COLON block;

// try stmt
try_stmt: TRY COLON block finally_block                         #try_finally_block
    | TRY COLON block except_block+ else_block? finally_block?  #try_except_else_finally_block
    ;

except_block: EXCEPT (expression | expressions)? COLON block;
finally_block: FINALLY COLON block;

// match case stmt
match_stmt: MATCH subject_expr COLON NEWLINE INDENT case_block+ DEDENT;
subject_expr: named_expression COMMA named_expression? | named_expression;
case_block: CASE pattern COLON block    #match_case
    | CASE UNDERSCORE COLON block              #match_case_default
    ;
pattern: NAME | attr_pattern;
attr_pattern: (NAME DOT)+ NAME;

// compound statements common elements
block: NEWLINE INDENT statements DEDENT;

// function type parameters
function_params: NAME (COMMA NAME)*;

// expressions
expressions: expression (COMMA expression)* COMMA?;
expression: disjunction IF disjunction ELSE expression
    | disjunction
    | lambdef;
assignment_expression: NAME WALRUS expression;
named_expression:
    assignment_expression | expression {_input->LA(1) != WALRUS}?;

disjunction: conjunction (OR conjunction)*;
conjunction: inversion (AND inversion)*;
inversion: NOT inversion | comparison;

// comparison operators
comparison: sum comp_op+ | sum;
comp_op: comp_eq | comp_noteq | comp_lte | comp_lt | comp_gte | comp_gt | comp_notin | comp_in;
comp_eq: EQEQUAL sum;
comp_noteq: NOTEQUAL sum;
comp_lte: LESSEQUAL sum;
comp_lt: LESS sum;
comp_gte: GREATEREQUAL sum;
comp_gt: GREATER sum;
comp_notin: NOT IN sum;
comp_in: IN sum;

// arithmetic operators
sum: sum PLUS term | sum MINUS term | term;
term: term STAR factor | term SLASH factor | term DOUBLESLASH factor | term PERCENT factor | factor;
factor: PLUS factor | MINUS factor | power;
power: primary DOUBLESTAR factor | primary;

// primary elements
primary: primary DOT NAME           #field_prim
    | primary PAR_LEFT arguments? PAR_RIGHT    #function_call_prim
    | primary BRACKET_LEFT slices BRACKET_RIGHT        #slice_prim
    | atom                          #atom_prim
    ;
slices: slice {_input->LA(1) != COMMA}? | ((slice | expression) (COMMA (slice | expression))*) COMMA?;
slice: expression? COLON expression? (COLON expression?)? | named_expression;
atom: NAME | TRUE | FALSE | NONE | strings | NUMBER | tuple | list | listcomp | dict | dictcomp | set | setcomp;

// function call arguments
arguments: arg_expression (COMMA arg_expression)* COMMA?;
arg_expression: (starred_expression | (assignment_expression | expression {_input->LA(1) != WALRUS}?) {_input->LA(1) != EQUALS}?);

kwargs: kwarg_or_starred (COMMA kwarg_or_starred)* COMMA kwarg_or_double_starred (COMMA kwarg_or_double_starred)*
    | kwarg_or_starred (COMMA kwarg_or_starred)*
    | kwarg_or_double_starred (COMMA kwarg_or_double_starred)*;
starred_expression: STAR expression;
kwarg_or_starred: NAME EQUALS expression | starred_expression;
kwarg_or_double_starred: NAME EQUALS expression | DOUBLESTAR expression;

// assignment targets
as_targets: as_target {_input->LA(1) != COMMA}? | as_target (COMMA as_target)* COMMA?;
as_target_list: as_target (COMMA as_target)* COMMA?;
as_target_tuple: as_target (COMMA as_target)+ COMMA? | as_target COMMA;
as_target: t_primary COMMA NAME {_input->LA(1) != PAR_LEFT && _input->LA(1) != BRACKET_LEFT && _input->LA(1) != DOT}?
    | t_primary BRACE_LEFT slices BRACE_RIGHT {_input->LA(1) != PAR_LEFT && _input->LA(1) != BRACKET_LEFT && _input->LA(1) != DOT}?
    | as_atom;
as_atom: NAME 
    | PAR_LEFT as_target PAR_RIGHT 
    | PAR_LEFT as_target_tuple? PAR_RIGHT
    | BRACKET_LEFT as_target_list? BRACE_RIGHT
    ;

single_target: single_subscript_attribute_target | NAME | PAR_LEFT single_target PAR_RIGHT;
single_subscript_attribute_target: NAME (DOT NAME)* {_input->LA(1) != PAR_LEFT && _input->LA(1) != BRACKET_LEFT && _input->LA(1) != DOT}?
    | NAME (DOT NAME)* BRACKET_LEFT slices BRACE_RIGHT {_input->LA(1) != PAR_LEFT && _input->LA(1) != BRACKET_LEFT && _input->LA(1) != DOT}?;


t_primary: primary DOT NAME                           #field_tprim
    | primary PAR_LEFT arguments? PAR_RIGHT         #function_call_tprim
    | primary BRACKET_LEFT slices BRACKET_RIGHT     #slice_tprim
    | atom                                          #atom_tprim
    ;
t_lookahead: PAR_LEFT | BRACKET_LEFT | DOT;

// generic targets
targets: target {_input->LA(1) != COMMA}? | target (COMMA target)* COMMA?;
target: primary DOT NAME | primary BRACKET_LEFT slices BRACKET_RIGHT | atom;

// del statement targets
del_targets: del_target (COMMA del_target)* COMMA?;
del_target: primary DOT NAME | primary BRACKET_LEFT slices BRACKET_RIGHT | NAME;

// literals
strings: STRING+;
list: BRACKET_LEFT expressions? BRACKET_RIGHT;
tuple: PAR_LEFT (expression COMMA expressions?)? PAR_RIGHT;
set: BRACE_LEFT expressions BRACE_RIGHT;

// dicts
dict: BRACE_LEFT double_starred_kvpairs? BRACE_RIGHT;
double_starred_kvpairs: double_starred_kvpair (COMMA double_starred_kvpair)* COMMA?;
double_starred_kvpair: DOUBLESTAR expression | kvpair;
kvpair: expression COLON expression;

// comprehension
for_if_clauses: for_if_clause+;
for_if_clause: FOR targets IN disjunction (IF disjunction)*;
listcomp: BRACKET_LEFT named_expression for_if_clauses BRACKET_RIGHT;
setcomp: BRACE_LEFT named_expression for_if_clauses BRACE_RIGHT;
dictcomp: BRACE_LEFT kvpair for_if_clauses BRACE_RIGHT;