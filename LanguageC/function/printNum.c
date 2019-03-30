//
// Created by 17hao on 2019-03-30.
//

#include <stdio.h>

/*
 * 递归打印数字
 * 递归栈会先取出最后调用的帧
 */
void printNum(int n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10) {
        printNum(n / 10);
    }
    putchar(n % 10 + '0');
}