/**
 * Median of 2 sorted array
 *
 * @since 2021-7-14 Wednesday
 */

#include <stdlib.h>
#include <stdio.h>

int getKth(int* nums1, int size1, int start1, int* nums2, int size2, int start2, int k) {
	if (size1 > size2) {
		return getKth(nums2, size2, start2, nums1, size1, start1, k);
	}
	if (size1 == 0) {
		return nums2[start2 + k - 1];
	}
	if (k == 1) {
		return nums1[start1] < nums2[start2] ? nums1[start1] : nums2[start2];
	}
	int index1 = start1 + (k / 2 > size1 ? size1 - 1 : k / 2 - 1);
	int index2 = start2 + (k / 2 > size2 ? size2 - 1 : k / 2 - 1);
	printf("index1=%d index2=%d\n", index1, index2);
	if (nums1[index1] > nums2[index2]) {
		return getKth(nums1, size1, start1, nums2, size2 - (index2 - start2 + 1), index2 + 1, k - (index2 - start2 + 1));
	} else {
		return getKth(nums1, size1 - (index1 - start1 + 1), index1 + 1,  nums2, size2, start2, k - (index1 - start1 + 1));
	}
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int i = (nums1Size + nums2Size + 1) / 2;
	int j = (nums1Size + nums2Size + 2) / 2;
    int num1 = getKth(nums1, nums1Size, 0, nums2, nums2Size, 0, i);
	int num2 = getKth(nums1, nums1Size, 0, nums2, nums2Size, 0, j);
	printf("i=%d j=%d num1=%d num2=%d\n", i, j, num1, num2);
	return (double) (num1 + num2) / 2;
}

int main(int argc, char* argv[]) {
	int nums1[5] = {1,2};
	//int nums2[3] = {6,7,8};
	int nums2[3] = {3,4};
	double res = findMedianSortedArrays(nums1, 2, nums2, 2);
	printf("%f", res);
}
