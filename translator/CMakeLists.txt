cmake_minimum_required(VERSION 3.15)
project(translator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

if (UNIX)
    list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/antlr4-unix/lib64/cmake)
else()
    list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/antlr4-win/lib/cmake)
endif()

set(WITH_DEMO OFF CACHE BOOL "" FORCE)
set(WITH_STATIC_CRT ON CACHE BOOL "" FORCE)

find_package(antlr4-runtime REQUIRED)

add_library(translator STATIC
        src/PythonLexer.cpp
        src/PythonParser.cpp
        src/PythonLexerBase.cpp
        src/Scope.cpp
        src/Scope.h
        src/PythonCustomParserVisitor.cpp
        src/PythonCustomParserVisitor.h
        src/CustomErrorListener.h
        src/CustomErrorListener.cpp
        src/Translator.cpp
        src/main.cpp
)


target_include_directories(translator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(translator
        PUBLIC antlr4_static
)

target_compile_definitions(translator
        PUBLIC ANTLR4CPP_STATIC
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/examples/testfile.py DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/examples)

target_compile_definitions(translator
        PRIVATE ANTLR4CPP_STATIC
)

target_compile_features(
        translator PRIVATE cxx_std_17
)

add_executable(
        gram src/main.cpp
)

target_link_libraries(
        gram PRIVATE translator
)