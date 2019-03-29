cmake_minimum_required(VERSION 3.13)
project(ProgramInC C)

set(CMAKE_C_STANDARD 99)

add_executable(ProgramInC csapp/data/main.c csapp/data/show-bytes.c csapp/data/swap.c)