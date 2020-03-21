#include <stdio.h>
#include "rpn.h"

/**
 * reverse polish notation
 *
 * (1 - 2) * (3 + 4) = -7
 * 1 2 - 3 4 + * = -7
 */
int main() {
    char *s = "1 2 - 3 4 + * ";
    double res = calculate(s);
    printf("result is: %f\n", res);
}