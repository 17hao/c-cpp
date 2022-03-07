// gcc -DCOMPILETIME 07.c

#ifdef COMPILETIME
#include <stdio.h>

int main() {
    printf("hello, world!");
}
#endif