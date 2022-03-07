// gcc -DCOMPILETIME 07-1.c

#ifdef COMPILETIME
#include <stdio.h>

int main() {
    printf("hello, world!\n");
}
#endif