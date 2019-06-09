cmake_minimum_required(VERSION 3.13)
project(ProgramInC C)

set(CMAKE_C_STANDARD 99)

add_executable(ProgramInC main.c csapp/data/show-bytes.c csapp/data/swap.c LanguageC/PointerAndArray/code1.c LanguageC/PointerAndArray/code2.c LinkAndLoad/SimpleSection.c LanguageC/function/printNum.c LanguageC/function/qsort.c LanguageC/structure/basicKnowledge.c LanguageC/structure/typeDef.c StructureAndAlgorithm/Practice1.1.c tool/swap.c StructureAndAlgorithm/Practice1.1.h tool.h tool/quickSort.c)
#add_executable(ProgramInC )