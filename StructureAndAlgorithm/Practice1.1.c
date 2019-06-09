//
// Created by 17hao on 2019-04-16.
//

#include "Practice1.1.h"

void quickSort(int left, int right, int arr[]) {
    if (right < left) {
        return;
    }
    swap(left, (left + right) / 2, arr); /* 选取中间元素移到数组头部 */
    int cur = left; /* 指向数组当前位置 */
    for (int i = left + 1; i <= right; i++) { /* 遍历整个数组，将小于基准数的放到左边，剩下的就是大于部分 */
        if (arr[i] < arr[left]) {
            swap(i, ++cur, arr);
        }
    }
    swap(left, cur, arr); /* 将基准数放到合适位置 */
    quickSort(left, cur - 1, arr); /* 对基准数左右两边持续partition */
    quickSort(cur + 1, right, arr);
}

int kThLargest(int k, int *arr) {
    int tmp[k];
    int length = sizeof(arr) / sizeof(int);
    for (int i = 0; i < k; i++) {
        tmp[i] = arr[i];
    }
    quickSort(0, length, arr);
}



