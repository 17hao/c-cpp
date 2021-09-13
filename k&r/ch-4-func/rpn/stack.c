#include <stdio.h>
#define MAX_VAL 100

int sp = 0;          /* stack position */
double val[MAX_VAL]; /* stack items */

void push(double m) {
    if (sp < MAX_VAL) {
        val[sp++] = m;
    } else {
        printf("error: stack full.\n");
    }
}

double pop() {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty.\n");
        return 0.0;
    }
}