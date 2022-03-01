#include <cstdlib>
#include <ctime>
#include <iostream>

/**
 * shell sort
 * 
 * time complexity: 
 * space complecity: 
 * stable: false
 *
 * @since 2021-10-18 Monday 14:54
 */
class C {
   public:
    void shellSort(int *arr, int len) {
        doSortByInsertion(arr, len, len / 2);
        // doSortByExchange(arr, len, len / 2);
    }

   private:
    /**
     * It can be seen as a generalization of sorting by exchange(bubble sort)
     */
    void doSortByExchange(int *arr, int len, int gap) {
        for (; gap > 0; gap /= 2) {
            for (int i = 0; i < len / gap; i += 1) {
                for (int j = 0; j < len - 1 - i * gap; j += gap) {
                    if (arr[j] > arr[j + gap]) {
                        swap(arr, j, j + gap);
                    }
                }
            }
        }
    }

    /**
     * It can be seen as a generalization of sorting by insertion(insertion sort).
     */
    void doSortByInsertion(int *arr, int len, int gap) {
        for (; gap > 0; gap /= 2) {
            for (int i = gap; i < len; i += gap) {
                for (int j = i; j >= gap; j -= gap) {
                    if (arr[j] < arr[j - gap]) {
                        swap(arr, j, j - gap);
                    }
                }
            }
        }
    }

    void swap(int *arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
};

int main(int argc, char const *argv[]) {
    C c;
    int seed = (unsigned int)std::time(0);
    std::srand(seed);
    int len = std::rand() / ((RAND_MAX + 1u) / 20);
    int arr[len];
    for (int i = 0; i < len; i++) {
        int n = std::rand() / ((RAND_MAX + 1u) / 19);
        std::cout << n << " ";
        arr[i] = n;
    }
    std::cout << "\n";
    c.shellSort(arr, len);
    for (int i = 0; i < len; i++) {
        std::cout << arr[i] << " ";
    }
}