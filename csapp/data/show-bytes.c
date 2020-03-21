#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len) {
    for (int i = 0; i < len; i++) {
        printf("%.2x", start[i]);
        printf("\n");
    }
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_bytes_test(int val) {
    int ival = val;
    float fval = (float) val;
    show_int(ival);
    show_float(fval);
    printf("\n");
    char *c = "ABCDEF";
    show_bytes(c, strlen(c));
}