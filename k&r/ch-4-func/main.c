#include <stdio.h>

#include "calc.h"

double calculate(char* s);

/**
 * reverse Polish notation
 *
 * (1 - 2) * (3 + 4) = -7
 * 1 2 - 3 4 + * = -7
 */
main() {
    char *s = "1 2 - 3 4 + *";
    // char* s = "2 1 - 3 4 + *";
    double res = calculate(s);
    printf("result is: %.2f\n", res);
}

double calculate(char* s) {
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