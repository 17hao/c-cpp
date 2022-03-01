#include "tools.h"

/**
 * heap sort
 * 
 * Heap sort can be thought of as an improved selection sort: like selection sort,
 * heapsort divides its input into a sorted and an unsorted region, and it iteratively
 * shrink the unsorted region by extracting the largest element from it and inserting it
 * into the sorted region.
 * 
 * time complexity: O(nlogn)
 * space complexity: O(1)
 * stable: false
 * @since 2021-10-19 Tuesday 14:32
 */
class C {
   public:
    void heapSort(int *arr, int len) {
        heapify(arr, len);
        int end = len - 1;
        while (end >= 0) {
            swap(&arr[0], &arr[end]);
            end--;
            siftDown(arr, 0, end);
        }
    }

   private:
    void heapify(int *arr, int len) {
        int start = len - 1;
        while (start >= 0) {
            siftDown(arr, start, len - 1);
            start--;
        }
    }

    void siftDown(int *arr, int start, int end) {
        int root = start;
        while (root * 2 + 1 <= end) {
            int leftChild = root * 2 + 1;
            int swapIndex = root;
            if (arr[root] < arr[leftChild]) {
                swapIndex = leftChild;
            }
            if (leftChild + 1 <= end && arr[swapIndex] < arr[leftChild + 1]) {
                swapIndex = leftChild + 1;
            }
            if (swapIndex == root) {
                return;
            } else {
                swap(&arr[swapIndex], &arr[root]);
            }
            root = swapIndex;
        }
    }

    void swap(int *i, int *j) {
        int tmp = *i;
        *i = *j;
        *j = tmp;
    }
};

int main(int argc, char const *argv[]) {
    C c;
    struct tools::array *my_arr = tools::randomArray();
    c.heapSort(my_arr->content, my_arr->len);
    tools::printArray(my_arr);
}
