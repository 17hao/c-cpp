#include <stdio.h>
#include "main.h"

int main() {
    int val = 12345; // 0x00003039
    show_bytes_test(val);
    int m = 1;
    int n = 2;
    inplace_swap(&m, &n);
    printf("m = %d n = %d", m, n);
}