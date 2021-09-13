#include <stdio.h>

#include "misc.h"

static struct point *create_p() {
    struct point p = {.x = 1, .y = 2};
    return &p;
}

int main() {
    struct point p;
    p = *create_p();
    printf("x: %d - y: %d\n", p.x, p.y);
}