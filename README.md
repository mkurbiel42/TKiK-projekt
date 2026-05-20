## Projekt translatora programów w języku Python do języka JavaScript

- Autorzy:
    - Michał Kurbiel: kurbielm@student.agh.edu.pl
    - Antoni Leszczyński: antonilesz@student.agh.edu.pl

- Założenia:
    - Program napisany w jezyku C++
    - Interpreter - translator
    - Cel to translacja programu napisanego w języku Python do skryptu w języku JavaScript
        - Gramatyka zawiera większość konstrukcji dostępnych w pełnej wersji języka Python, jednak nie wszystkie one są dostępne w języku JavaScript
        - Wykrycie jakiegokolwiek błędu przez parser (nieoczekiwany token, niewspierana w JS konstrukcja itd.) kończy działanie programu i nie zwraca żadnej translacji
- Opis tokenów oraz gramatyka znajduję się w plikach [/grammar/PythonLexer.g4](/grammar/PythonLexer.g4) oraz [/grammar/PythonParser.g4](/grammar/PythonParser.g4)

- Użyty generator skanerów/parserów, to ANTLR4
    - W czasie działania parsera używane są funkcje wspomagające np. wykrywanie tokenów INDENT oraz DEDENT
    - Translacja odbywa się poprzez wzorzec Visitor

- Lista funkcji języka Python wspierana przez program i tłumaczona do JS:
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
    - Niektóre funkcje wbudowane (sprecyzowane później)
