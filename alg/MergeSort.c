/**
 * merge sort
 *
 * @since 2021-6-29 Tuesday 17:45
 */

#include <stdio.h>

void merge(int *arr, int start, int mid, int end) {
  int l1 = mid - start + 1;
  int l2 = end - mid;
  int a1[l1], a2[l2];
  for (int i = 0; i < l1; i++) {
    a1[i] = arr[start + i];
  }
  for (int i = 0; i < l2; i++) {
    a2[i] = arr[mid + 1 + i];
  }
  int cur = start, i = 0, j = 0;
  while (i < l1 && j < l2) {
    if (a1[i] < a2[j]) {
      arr[cur++] = a1[i++];
    } else {
      arr[cur++] = a2[j++];
    }
  }
  while (j < l2) {
    arr[cur++] = a2[j++];
  }
  while (i < l1) {
    arr[cur++] = a1[i++];
  }
}

void mergeSort(int *arr, int start, int end) {
  if (start < end) {
    int mid = start + ((end - start) >> 1);
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
  }
}

void sort(int *arr, int len) {
  mergeSort(arr, 0, len - 1);
}

int main(int args, char *argv[]) {
  int arr[7] = {3, 2, 4, 1, 5, 10, 1};
  sort(arr, 7);
  for (int i = 0; i < 7; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
