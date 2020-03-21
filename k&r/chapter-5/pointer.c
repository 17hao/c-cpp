#include <stdio.h>

int main() {
    int x = 1, y = 2, z[10];
    int *ip;

    ip = &x;
    printf("pointer ip = %d\n", x);

    y = *ip;
    *ip = 0;
    printf("x, y = %d, %d\n", *ip, y);
}