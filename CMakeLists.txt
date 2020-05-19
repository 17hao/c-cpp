cmake_minimum_required(VERSION 3.13)
project(c-program)
set(CMAKE_C_STANDARD 99)

file(GLOB_RECURSE kr_source k&r/*.c k&r/*.h)
file(GLOB_RECURSE tlpi_source tlpi/*.c tlpi/*.h)
#add_subdirectory(k&r)
#add_subdirectory(tlpi)
#
add_executable(c-program
        ${kr_source}
        ${tlpi_source}
        )