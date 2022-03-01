#include <stdio.h>

typedef struct {
    int a[2];
    double d;
} struct_t;

double fun(int i) {
    volatile struct_t s;
    s.d = 3.14;
    s.a[i] = 0x7fffffff;
    return s.d;
}

int main(int argc, char const *argv[]) {
    printf("%f", fun(10));
}
