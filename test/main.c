#include <stdio.h>

extern f(int n);

int main(int argc, char **argv) {
    int res = f(1);
    printf("%d\n", res);
}
