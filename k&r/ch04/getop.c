#include <ctype.h>
#include <stdio.h>

#include "calc.h"

/**
 * get next character or numeric operand
 */
int getop(char *s) {
  int i, c;

  while ((s[0] = c = my_getchar()) == ' ' || c == '\t') {
  }
  s[1] = '\0';
  if (!isdigit(c) && c != '.') {
    return c; /* not a number */
  }
  i = 0;
  if (isdigit(c)) { /* collect integer part */
    while (isdigit(s[++i] = c = my_getchar())) {
    }
  }
  if (c == '.') { /* collect fraction part */
    while (isdigit(s[++i] = c = my_getchar())) {
    }
  }
  s[i] = '\0';
  if (c != EOF) { /* send EOF to the program with Ctrl-D */
    my_ungetchar(c);
  }
  return NUMBER;
}
