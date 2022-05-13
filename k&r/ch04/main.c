#include <stdio.h>
#include <stdlib.h>

#include "calc.h"

#define MAXOP 100

// double calculate(char* s);

void calculate();

/**
 * reverse Polish notation
 *
 * (1 - 2) * (3 + 4) = -7
 * 1 2 - 3 4 + * = -7
 */
int main(int argc, char const *argv[]) {
  // char *s = "1 2 - 3 4 + *";
  // // char* s = "2 1 - 3 4 + *";
  // double res = calculate(s);
  // printf("result is: %.2f\n", res);
  calculate();
}

// double calculate(char* s) {
//     double temp;
//     for (; *s != '\0'; s++) {
//         switch (*s) {
//             case '0' ... '9':
//                 push((double)(*s - '0') - (double)('0' - '0'));
//                 break;
//             case '+':
//                 push(pop() + pop());
//                 break;
//             case '-':
//                 temp = pop();
//                 push(pop() - temp);
//                 break;
//             case '*':
//                 push(pop() * pop());
//                 break;
//             case '/':
//                 temp = pop();
//                 push(pop() / temp);
//                 break;
//             case ' ':
//                 break;
//             default:
//                 printf("error: unknown command: %c.\n", *s);
//                 break;
//         }
//     }
//     return pop();
// }

void calculate() {
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '*':
      push(pop() * pop());
      break;
    case '/':
      op2 = pop();
      push(pop() / op2);
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unknown command: %c.\n", *s);
      break;
    }
  }
}