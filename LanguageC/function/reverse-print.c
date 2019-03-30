//
// Created by 17hao on 2019-03-30.
//

#include <stdio.h>

// 递归逆序打印数字
void reversePrintNum(int n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10) {
        reversePrintNum(n / 10);
    }
    putchar(n % 10 + '0');
}