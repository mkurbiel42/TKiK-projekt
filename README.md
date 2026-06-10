## Projekt translatora programów w języku Python do języka JavaScript

- Autorzy:
    - Michał Kurbiel: kurbielm@student.agh.edu.pl
    - Antoni Leszczyński: antonilesz@student.agh.edu.pl

- Założenia:
    - Program napisany w jezyku C++
    - Kompilator - translator
    - Cel to translacja programu napisanego w języku Python do skryptu w języku JavaScript
        - Gramatyka zawiera większość konstrukcji dostępnych w pełnej wersji języka Python, jednak nie wszystkie one są dostępne w języku JavaScript
        - Wykrycie błędu leksykalnego przez parser (nieoczekiwany token) zgłasza błąd i nie zwraca żadnej translacji
        - Wykrycie konstrukcji nieposiadającej odpowiednika w JS lub błędnej semantycznie, pomija tę konstrukcję, zgłaszając błąd
- Użyty generator skanerów/parserów, to ANTLR4
    - W czasie działania parsera używane są funkcje wspomagające np. wykrywanie tokenów INDENT oraz DEDENT
    - Translacja odbywa się poprzez wzorzec Visitor

- Lista konstrukcji języka Python wspierana przez program i tłumaczona do JS:
    - Przypisywanie wartości do zmiennych, pól obiektów, pod indeksy tablicy
    - Przypisywanie rozszerzone z wykorzystaniem operatorów +=, -=, *=, /=, %=, **=, //=
    - Działania matematyczne: +, -, *, /, %, //, **
    - Porównania: ==, !=, <=, <, >=, >, IN, NOT IN
    - Rozszerzone indeksowanie (konstrukcje typu [x:y], [x\:y\:z], [:], [x, y])
    - Array comprehension (na listach, tuplach oraz słownikach)
    - Rozpakowywanie list oraz słowników (operatory *list oraz **dict)
    - Definicja funkcji (w tym użycie słów kluczowych global oraz nonlocal)
    - Definicja klas
    - Funkcje anonimowe (lambda)
    - Pętle for i while
    - Instrukcje warunkowe if...elif...else
    - Konstrukcje obsługi błędów: raise oraz try...except...finally
    - Uproszczone konstrukcje match case
    - Komentarze liniowe
    - Wybrane funkcje wbudowane:
    - abs
    - bool
    - int
    - str
    - list
    - set
    - map
    - filter
    - enumerate
    - sum
    - len
    - max
    - min
    - reversed
    - round

- Gotowa wersja aplikacji z interfejsem graficznym (dla systemu Windows) znajduje się w folderze [./App-windows/](./App-windows/)
    - Aplikacja uruchamiana przez plik wykonywalny ___qt_app.exe___
    - Lewa strona służy pisaniu programu wejściowego, na prawej zwrócony zostanie wynik translacji
    - _File -> open_ - otwarcie pliku _.py_ - określenie wejścia dla translatora
    - _File -> save_ - zapis wynikiu translacji do pliku _.js_
    - _Translate (symbol strzałki)_ - tłumaczenie kodu wejściowego - tekst w polu przeznaczonym na wyjście jest w całości nadpisywany 
- Przykładowy kod wejściowy znajdujący się w pliku [./Examples/testfile.py](./Examples/testfile.py)
    ```py
    i=1
    j=2
    k=3
    def get(i):
        g=i+1
        add(14,15)
        def inside(j):
            nonlocal g
            return g/2
        return 1
        
    def add(i, j):
        return i + j
        
    class MyClass:
        i = 12345
        
        def f(self):
            return 'hello world'
        
    try:
        print(x)
    except NameError:
        print("Variable x is not defined")
        
    for i in range(6):
        print(i)
        
    day = 4
    match day:
        case 6:
            print("Today is Saturday")
        case 7:
            print("Today is Sunday")
        case _:
            print("Looking forward to the Weekend")
        
    i = 1
        
    # funkcje wbudowane:
    print(abs(-1))
    print(bool(10))
    print(list(enumerate(['a', 'b', 'c'])))
    print(list(enumerate(['a', 'b', 'c'], 4)))
    print(list(filter(lambda x: x>10, [1, 5, 15, 2, 35, 10])))
    print(int(10.3))
    print(len([1, 3, 2, 4, 1]))
    print(list(range(10)))
    print(list(range(3, 15)))
    print(list(range(3, 15, 3)))
    print(list(range(15, 3, -3)))
    print(list(map(lambda x: x*10, [1, 3, 2, 9, 4])))
    print(max(1, 3, 2))
    print(max([2, 4, 0]))
    print(min(1, 3, 2))
    print(min([2, 4, 0]))
    print(list(reversed([1, 2, 3])))
    print(round(4.5678))
    print(round(4.5678, 2))
    print(set([1, 2, 3, 2, 5, 3]))
    print(str(10))
    print(sum([1, 2, 3]))
    print(sum([1, 2, 3], 2))
        
    raise Exception(1)
    ```
- Rezultat translacji tego przykładowego kodu:
    ```js
    let i = 1
    let j = 2
    let k = 3
    function get(i){
        let g = i + 1
        add(14, 15)
        function inside(j){
            return g / 2
        }
        return 1
    }
    function add(i, j){
        return i + j
    }
    class MyClass{
        i = 12345
        f(){
            return "hello world"
        }
    }
    try{
        console.log(x)
    }catch{
        console.log("Variable x is not defined")
    }
    for(let i=0; i<6; i++){
        console.log(i)
    }
    let day = 4
    switch(day){
        case 6:
            console.log("Today is Saturday")
            break
        case 7:
            console.log("Today is Sunday")
            break
        default:
            console.log("Looking forward to the Weekend")
            break
    }
    i = 1
    // funkcje wbudowane
    console.log(Math.abs(-1))
    console.log(Boolean(10))
    console.log([...["a", "b", "c"].entries()])
    console.log([...["a", "b", "c"].entries().map(e=>{e[0]+=4;return e;})])
    console.log([...[1, 5, 15, 2, 35, 10].filter((x) => x > 10)])
    console.log(parseInt(10.3))
    console.log([1, 3, 2, 4, 1].length)
    console.log([...[...Array(Math.ceil((Math.abs(10-0))/Math.abs(1))).keys()].map(a => a*1+0)])
    console.log([...[...Array(Math.ceil((Math.abs(15-3))/Math.abs(1))).keys()].map(a => a*1+3)])
    console.log([...[...Array(Math.ceil((Math.abs(15-3))/Math.abs(3))).keys()].map(a => a*3+3)])
    console.log([...[...Array(Math.ceil((Math.abs(3-15))/Math.abs(-3))).keys()].map(a => a*-3+15)])
    console.log([...[1, 3, 2, 9, 4].map((x) => x * 10)])
    console.log(Math.max(1, 3, 2))
    console.log(Math.max(...[2, 4, 0]))
    console.log(Math.min(1, 3, 2))
    console.log(Math.min(...[2, 4, 0]))
    console.log([...[...[1, 2, 3]].reverse()])
    console.log(Math.round(4.5678))
    console.log(+parseFloat(4.5678).toFixed(2))
    console.log(new Set([1, 2, 3, 2, 5, 3]))
    console.log((10).toString())
    console.log([1, 2, 3].reduce((acc, currVal) => acc+currVal))
    console.log([1, 2, 3].reduce((acc, currVal) => acc+currVal, 2))
    throw new Error(1)
    ```

- Spis tokenów w formacie wejściowym ANTLR4 (fragment pliku [./grammar/PythonLexer.g4](./grammar/PythonLexer.g4)):
    ```antlr4
    NEWLINE: (SPACES | ( '\r'? '\n' | '\r' | '\f') SPACES?);
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
    AS: 'as';
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
    
    COMMENT: '#' ~('\n'|'\r'|'\f')*;
    
    fragment INTEGER:   [1-9][0-9]* | '0';
    fragment FLOAT:     INTEGER '.' [0-9]+;
    fragment SPACES: [ \t]+;
    ```
- Gramatyka języka w formacie wejściowym ANTLR4 (fragment pliku [./grammar/PythonParser.g4](./grammar/PythonParser.g4)):
    ```antlr4
    // starting rule
    file: NEWLINE* statements? ENDMARKER;

    // general statements
    statements: statement+;
    statement: comment_stmt | compound_stmt | simple_stmt;
    simple_stmt: (assignment | expressions | return_stmt | raise_stmt | pass_stmt | del_stmt | break_stmt | continue_stmt | global_stmt | nonlocal_stmt) NEWLINE;
    compound_stmt: function_def | if_stmt | class_def | for_stmt | try_stmt | while_stmt | match_stmt;

    comment_stmt: COMMENT NEWLINE;
    // simple statements
    assignment: (as_targets EQUALS)+ expressions    # simple_assignment
        | single_target augassign expressions       # aug_assignment
        ;
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
    function_def: DEF NAME PAR_LEFT function_params? PAR_RIGHT COLON block;

    // lambda function def
    lambdef: LAMBDA function_params? COLON expression;

    // if stmt
    if_stmt: IF named_expression COLON block (elif_stmt | else_block?);
    elif_stmt: ELIF named_expression COLON block (elif_stmt | else_block?);
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

    except_block: EXCEPT (expression | expressions)? COLON block #except_block_normal
    | EXCEPT expression AS NAME COLON block   #except_as_block
    ;
    finally_block: FINALLY COLON block;

    // match case stmt
    match_stmt: MATCH subject_expr COLON NEWLINE INDENT case_block+ DEDENT;
    subject_expr: named_expression COMMA named_expression? | named_expression;
    case_block: CASE pattern COLON block    #match_case
        | CASE UNDERSCORE COLON block              #match_case_default
        ;
    pattern: primary;

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
    atom: NAME | TRUE | FALSE | NONE | strings | NUMBER | tuple | group | list | listcomp | dict | dictcomp | set | setcomp;

    group: PAR_LEFT expression PAR_RIGHT;

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
    as_target: primary DOT NAME {_input->LA(1) != PAR_LEFT && _input->LA(1) != BRACKET_LEFT && _input->LA(1) != DOT}?
        | primary BRACKET_LEFT slices BRACKET_RIGHT {_input->LA(1) != PAR_LEFT && _input->LA(1) != BRACKET_LEFT && _input->LA(1) != DOT}?
        | as_atom;
    as_atom: NAME                                   # as_atom_name
        | PAR_LEFT as_target PAR_RIGHT              # as_atom_tuple
        | PAR_LEFT as_target_tuple? PAR_RIGHT       # as_atom_tuple_tuple
        | BRACKET_LEFT as_target_list? BRACKET_RIGHT# as_atom_list
        ;

    single_target: single_subscript_attribute_target | NAME | PAR_LEFT single_target PAR_RIGHT;
    single_subscript_attribute_target: t_primary DOT NAME {_input->LA(1) != PAR_LEFT && _input->LA(1) != BRACKET_LEFT && _input->LA(1) != DOT}?
        | t_primary BRACKET_LEFT slices BRACKET_RIGHT {_input->LA(1) != PAR_LEFT && _input->LA(1) != BRACKET_LEFT && _input->LA(1) != DOT}?;


    t_primary: t_primary DOT NAME {_input->LA(1) != PAR_LEFT && _input->LA(1) != BRACKET_LEFT && _input->LA(1) != DOT}?                          #field_tprim
        | t_primary PAR_LEFT arguments? PAR_RIGHT {_input->LA(1) != PAR_LEFT && _input->LA(1) != BRACKET_LEFT && _input->LA(1) != DOT}?        #function_call_tprim
        | t_primary BRACKET_LEFT slices BRACKET_RIGHT {_input->LA(1) != PAR_LEFT && _input->LA(1) != BRACKET_LEFT && _input->LA(1) != DOT}?    #slice_tprim
        | atom  {_input->LA(1) != PAR_LEFT && _input->LA(1) != BRACKET_LEFT && _input->LA(1) != DOT}?                                        #atom_tprim
        ;

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
    ```