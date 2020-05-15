cmake_minimum_required(VERSION 3.13)
project(c-program)

set(CMAKE_C_STANDARD 99)

add_executable(c-program
        k&r/ch-1/1-2.c
        k&r/ch-4-func/rpn/cal.c
        k&r/ch-4-func/rpn/main.c
        k&r/ch-4-func/rpn/rpn.h
        k&r/ch-4-func/rpn/stack.c k&r/ch-1/1-1.c k&r/ch-6-struc/6-1.c k&r/ch-6-struc/6-2.c k&r/ch-6-struc/6-3.c k&r/ch-6-struc/6-4.c)