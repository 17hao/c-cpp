#include <stdio.h>
#include "main.h"

int main() {
    /* 打印不同类型的每个字节 */
    int val = 12345; // 0x00003039
    show_bytes_test(val);

    /* 用指针原地交换2个数 */
    int m = 1;
    int n = 2;
    inplace_swap(&m, &n);
    printf("m = %d n = %d\n", m, n);

    /* 指针和数组的关系 */
    pointerArray();

    /* 指针和字符串的关系 */
    int len = myStrlen("string");
    printf("%d\n", len);
    char *s;
    char *t = "string";
    //myStrCpy_V1(&s, &t);
    //myStrCpy_V2(&s, &t);
    myStrCpy_V3(&s, &t);
    printf("%s\n", s);

    /* 递归打印一个数 */
    printNum(1234);

    /* 递归和简单的快排 */
    int array[] = {3, 2, 5, 4, 7, 9, 1};
    qsort(array, 0, 7);
    for (int i = 0; i < 8; i++) {
        printf("%d ", array[i]);
    }

    /* 结构 */
    struct point pt = {200, 100};
    printf("%d,%d\n", pt.x, pt.y);

    /* typedef和结构 */
    typedef char *string; /* 给char*(char类型的指针)赋予别名string */
    string str = "sqh";
    PersonalInfo pif = {10, str};
    printf("%d,%s", pif.age, pif.String);
}