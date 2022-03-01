/**
 * pointers and function arguments
 */

#include <stdio.h>

struct pointer {
    double x;
    double y;
};

void recover(struct pointer *p) {
    p->x = 0;
    p->y = 0;
}

// void recover(struct pointer p) {
//     p.x = 0;
//     p.x = 0;
// }

int main() {
    struct pointer p = {1, 2};
    printf("%f, %f\n", p.x, p.y);
    recover(&p);
    // recover(p);
    printf("%f, %f", p.x, p.y);
}