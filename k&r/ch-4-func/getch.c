#include <stdio.h>

#define BUFF_SIZE 100

char buf[BUFF_SIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

/**
 * get a (possibly pushed-back) character
 */
int my_getchar() {
    int res = getchar();
    // printf("getchar(): %d\n", res);
    return res;
    // return bufp > 0 ? buf[--bufp] : getchar();
}

/**
 * push character back to input
 */
void my_ungetchar(char c) {
    if (bufp > BUFF_SIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[++bufp] = c;
    }
}