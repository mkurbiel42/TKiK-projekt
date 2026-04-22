cmake_minimum_required(VERSION 3.15)
project(Proj LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

set(WITH_DEMO OFF CACHE BOOL "" FORCE)
set(WITH_STATIC_CRT ON CACHE BOOL "" FORCE)

# add_subdirectory(antlr4)
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib/cmake)

find_package(antlr4-runtime REQUIRED)

add_library(parser STATIC
  generated/TLexer.cpp
  generated/TParser.cpp
  generated/TParserBaseVisitor.cpp
  generated/TParserBaseListener.cpp
)

target_include_directories(parser
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/generated
)

target_link_libraries(parser
  PUBLIC antlr4_static
)

target_compile_definitions(parser
  PUBLIC ANTLR4CPP_STATIC
)

add_executable(gram
  src/main.cpp
)

target_link_libraries(gram
  PRIVATE
    parser
)

target_compile_definitions(gram
  PRIVATE ANTLR4CPP_STATIC
)