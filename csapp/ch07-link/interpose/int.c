/*
  compile time
    gcc -I . -o intc int.c mymalloc.o

    -I option tells the C preprocessor to look for mallo.h in the current directory before
    looking in the usual system directories.

  link time
    gcc -Wl,--wrap,malloc -Wl,--wrap,free -o intc int.o mymalloc.o

    1. -Wl passes options to linker. Each comma is replaced with a space.
    2. --wrap f flag tells linker to resolve references to f as __wrap_f, and to resolve references to
    __real_f as f.

  run time
    LD_PRELOAD="./mymalloc.so" ./intr

    If the LD_PRELOAD environment is setted, the dynamic linker will search the LD_PRELOAD libraries
    first, when it resolves undefined references.
*/

#include <malloc.h>
#include <stdio.h>

int main() {
  int *p = malloc(32);
  free(p);
  return (0);
}