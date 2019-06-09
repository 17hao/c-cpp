//
// Created by 17hao on 2019-03-29.
//

void situSwap(int *x, int *y) {
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}