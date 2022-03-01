#include <cstdlib>
#include <iostream>
#include <random>

/**
 * quick sort
 *
 * @since 2021-10-14 Thursday 17:07
 */
class C {
   public:
    void quickSort(int *arr, int len) {
        doSort(arr, 0, len - 1);
    }

   private:
    void doSort(int *arr, int left, int right) {
        if (left >= right) {
            return;
        }

        int pivotIndex = right - (right - left) / 2;
        int pivot = arr[pivotIndex];
        swap(arr, pivotIndex, right);

        int small = left - 1;
        int big = right;
        int i = left;
        while (i < big) {
            if (arr[i] < pivot) {
                swap(arr, ++small, i++);
            } else if (arr[i] > pivot) {
                swap(arr, --big, i);
            } else {
                i++;
            }
        }

        swap(arr, big++, right);
        doSort(arr, left, small);
        doSort(arr, big, right);
    }

    void swap(int *arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
};

int main(int argc, char *argv[]) {
    C c;
    int arr[10];
    std::srand(std::time(nullptr));
    for (int i = 0; i < 10; i++) {
        arr[i] = std::rand() / ((RAND_MAX + 1u) / 15);
    }

    c.quickSort(arr, 10);
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }
}