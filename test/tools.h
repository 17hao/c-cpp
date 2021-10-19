#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

namespace tools {
    struct array {
        int *content;
        int len;

        array(int *arr, int len) : content(arr), len(len){};
    };

    struct array *randomArray(int maxLen, int maxValue) {
        std::srand(std::time(nullptr));
        int len = std::rand() / ((RAND_MAX + 1u) / maxLen);
        int *arr = new int[len];
        for (int i = 0; i < len; i++) {
            int n = std::rand() / ((RAND_MAX + 1u) / maxValue);
            arr[i] = n;
        }
        return new array(arr, len);
    }

    std::vector<int> *randomVector(int maxLen, int maxValue) {
        std::srand(std::time(nullptr));
        static std::vector<int> res;
        int len = std::rand() / ((RAND_MAX + 1u) / maxLen);
        for (int i = 0; i < len; i++) {
            int n = std::rand() / ((RAND_MAX + 1u) / maxValue);
            res.push_back(n);
        }
        return &res;
    }

    struct array *randomArray() {
        return randomArray(30, 19);
    }

    void printArray(struct array *arr) {
        for (int i = 0; i < arr->len; i++) {
            std::cout << arr->content[i] << " ";
        }
        std::cout << "\n";
    }
}  // namespace tools