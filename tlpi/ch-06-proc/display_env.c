#include <stdio.h>

/**
 * Display the process environment list.
 */

extern char **environ;

int main() {
  char **ep;

  for (ep = environ; *ep != NULL; ep++) {
    puts(*ep);
  }

}