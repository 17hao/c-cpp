#include <stdio.h>

int main() {
    printf("%lu\n", sizeof(int));

    char *s = "hello";
    printf("%lu\n", sizeof(s));
}