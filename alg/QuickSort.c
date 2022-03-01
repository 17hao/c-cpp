#include <stdio.h>
#include <stdlib.h>

void swap(int* arr, int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void partition(int* arr, int start, int end) {
	if (start >= end) {
		return;
	}
	int small = start - 1, big = end;
	int pivotIndex = end - ((end - start) >> 2);
	int pivot = arr[pivotIndex];
	swap(arr, pivotIndex, end);
	int cur = start;
	while (cur < big) {
		if (arr[cur] < pivot) {
			swap(arr, cur++, ++small);
		} else if (arr[cur] > pivot) {
			swap(arr, cur, --big);
		} else {
			cur++;
		}
	}
	printf("[%d] = %d\n", cur, arr[cur]);
	swap(arr, end, cur);
	partition(arr, start, small);
	partition(arr, cur + 1 , end);
}

void sort(int* arr, int len) {
	partition(arr, 0, len - 1);
}

int main() {
	//int arr[5] = {6,5,2,4,1};
	//int* arr = (int *) malloc(sizeof(int) * 7);
	//arr = (int[]){6,5,2,2,2,4,1};
	int arr[7] = {6,5,2,2,2,4,1};
	sort(arr, 7);
	for (int i = 0; i < 7; i++) {
		printf("%d", arr[i]);
	}
	return 0;
}
