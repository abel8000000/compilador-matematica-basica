cmake_minimum_required(VERSION 3.10)
project(CompiladorMatematica)

set(CMAKE_C_STANDARD 99)

include_directories(include)

set(SOURCES
    src/main.c
    src/tokenizer.c
    src/mathParser.c
)

add_executable(CompiladorMatematica ${SOURCES})
