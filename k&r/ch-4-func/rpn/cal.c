#include <stdio.h>

#include "rpn.h"

double calculate(char *s) {
    double temp;
    for (; *s != '\0'; s++) {
        switch (*s) {
            case '0' ... '9':
                push((double)(*s - '0') - (double)('0' - '0'));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                temp = pop();
                push(pop() - temp);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                temp = pop();
                push(pop() / temp);
                break;
            case ' ':
                break;
            default:
                printf("error: unknown command: %c.\n", *s);
                break;
        }
    }
    return pop();
}

int len(char *s) {
    int res = 0;
    for (; *s != '\0'; s++) {
        res++;
    }
    return res;
}