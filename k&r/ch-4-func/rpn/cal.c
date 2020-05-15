#include <stdio.h>
#include "rpn.h"

double calculate(char *s) {
    double temp;
    int len = sizeof(s);
    for (int i = 0; i < len; i++) {
        char c = s[i];
        switch (c) {
            case '0' ... '9':
                push(c - '0');
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
            default:
                printf("error: unknown command: %d.\n", (c - '0'));
                break;
        }
        s++;
    }
    return pop();
}