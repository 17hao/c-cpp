/**
 * predefind function macro
 */

#include <stdio.h>

#define showList(...) puts(#__VA_ARGS__)

#define FUNCTION(name, a)   \
    int fun_##name(int x) { \
        return (a)*x;       \
    }

FUNCTION(quadruple, 4)
FUNCTION(double, 2)

#undef FUNCTION
#define FUNCTION 34
#define OUTPUT(a) puts(#a)

int main() {
    showList(test);  // note the lack of quotes
    showList("test");
    showList(1, "a");

    printf("quadrupkle(13): %d\n", fun_quadruple(13));
    printf("double(21): %d\n", fun_double(21));
    printf("%d\n", FUNCTION);
    OUTPUT(doller);
}