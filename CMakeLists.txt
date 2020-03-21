cmake_minimum_required(VERSION 3.13)
project(c-program)

set(CMAKE_C_STANDARD 99)

add_executable(c-program
        csapp/data/show-bytes.c
        tool/swap.c
        tool/quick-sort.c
        k&r/chapter-1/power.c
        k&r/chapter-4/rpn/cal.c
        k&r/chapter-4/rpn/main.c
        k&r/chapter-4/rpn/rpn.h
        k&r/chapter-4/rpn/stack.c)