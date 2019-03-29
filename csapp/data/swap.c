//
// Created by 17hao on 2019-03-29.
//

void inplace_swap(int *x, int *y) {
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}