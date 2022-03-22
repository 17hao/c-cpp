// quick sort (buggy)

#include <stdio.h>
#define LEN 8

typedef int (*cmp)(int, int);

void quickSort(int *nums, int len, cmp cmp);

void swap(int *nuns, int i, int j);

int compare(int i, int j);

int main() {
    int nums[LEN] = {2, 3, 1, 0, 10, 12, 4, 5};
    quickSort(nums, LEN, compare);
    for (int i = 0; i < LEN; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

void doQuickSort(int *nums, int start, int end, cmp cmp) {
    if (start >= end) {
        return;
    }
    int pivotIndex = start + (end - start) / 2;
    swap(nums, pivotIndex, end);
    int left = start - 1, right = end;
    int cur = start;
    while (cur < right) {
        if (cmp(nums[cur], nums[end]) < 0) {
            swap(nums, ++left, cur++);
        } else if (cmp(nums[cur], nums[end] > 0)) {
            swap(nums, --right, cur);
        } else {
            cur++;
        }
    }
    swap(nums, right, end);
    doQuickSort(nums, start, left, cmp);
    doQuickSort(nums, right + 1, end, cmp);
}

void quickSort(int *nums, int len, cmp cmp) {
    doQuickSort(nums, 0, len - 1, cmp);
}

void swap(int *nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

int compare(int i, int j) {
    return j - i;
    // return i - j;
}