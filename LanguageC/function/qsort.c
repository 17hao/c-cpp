//
// Created by 17hao on 2019-03-30.
//

/* 交换数组元素n[i]和n[j] */
void swap(int *n, int i, int j) {
    int temp = n[i];
    n[i] = n[j];
    n[j] = temp;
}

/* 快排,以递增的方式将n[left]到n[right]排序 */
void qsort(int n[], int left, int right) {
    if (left > right) /* 如果待排序数组元素数少于2啥也不干 */
        return;
    swap(n, left, (left + right) / 2); /* 选取数组中间位置的元素作为排序基准并移到数组起点 */
    int last = left; /* 表示当前指向的数组位置 */
    for (int i = left + 1; i <= right; i++) { /* 遍历数组，按第一个数为基准划分成左右两个*/
        if (n[i] < n[left])
            swap(n, i, ++last);
    }
    swap(n, left, last); /* 将基准数放到正确位置 */
    qsort(n, left, last - 1); /* 对基准数左右两边持续做partition的操作 */
    qsort(n, last + 1, right);
}
