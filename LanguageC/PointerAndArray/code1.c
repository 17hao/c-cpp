//
// Created by 17hao on 2019-03-29.
//
#include <stdio.h>

void pointerArray() {
    int a[3] = {0, '1', 2};
    int *pa = &a[0]; //pa = 0
    printf("a[0]:%d\na[1]:%c\n", *pa, *pa + 1 + '0'); //字符转数字:num + '0'
}

int myStrlen(char *s) {
    int n;
    for(n = 0;*s != '\0';s++){
        n++;
    }
    return n;
}