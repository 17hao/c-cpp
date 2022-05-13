#include <cstdlib>
#include <ctime>
#include <iostream>

/**
 * merge sort
 *
 * @since 2021-10-15 Friday
 */
class C {
public:
  void mergeSort(int *arr, int len) {
    doSort(arr, 0, len - 1);
  }

private:
  void doSort(int *arr, int start, int end) {
    if (start < end) {
      int mid = start + ((end - start) / 2);
      doSort(arr, start, mid);
      doSort(arr, mid + 1, end);
      merge(arr, start, mid, end);
    }
  }

  void merge(int *arr, int left, int mid, int right) {
    int l1 = mid - left + 1, l2 = right - mid;
    int leftArr[l1], rightArr[l2];
    for (int i = left, j = 0; i <= mid; i++, j++) {
      leftArr[j] = arr[i];
    }
    for (int i = mid + 1, j = 0; i <= right; i++, j++) {
      rightArr[j] = arr[i];
    }
    int i = 0, j = 0, biase = 0;
    while (i < l1 && j < l2) {
      if (leftArr[i] <= rightArr[j]) {
        arr[left + biase] = leftArr[i++];
      } else {
        arr[left + biase] = rightArr[j++];
      }
      biase++;
    }
    while (i < l1) {
      arr[left + biase] = leftArr[i++];
      biase++;
    }
    while (j < l2) {
      arr[left + biase] = rightArr[j++];
      biase++;
    }
  }
};

int main(int argc, char const *argv[]) {
  C c;
  std::srand(std::time(nullptr));
  int len = std::rand() / ((RAND_MAX + 1u) / 10);
  int arr[len];
  for (int i = 0; i < len; i++) {
    arr[i] = std::rand() / ((RAND_MAX + 1u) / 19);
  }
  c.mergeSort(arr, len);
  for (int i = 0; i < len; i++) {
    std::cout << arr[i] << " ";
  }
}
