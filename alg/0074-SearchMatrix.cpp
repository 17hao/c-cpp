#include <iostream>
#include <vector>

/**
 * Searching for a value in an m x n matrix.
 *
 * Integers in each row are sorted from left to right.
 * First integer of each row is greater than the last integer of the previous row.
 *
 * @since 2021-9-17 Friday 15:45 - 16:01
 */
class Solution {
public:
  bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
    for (auto row : matrix) {
      if (binarySearch(row, target)) {
        return true;
      }
    }
    return false;
  }

private:
  bool binarySearch(std::vector<int> vector, int target) {
    int len = vector.size();
    int left = 0, right = len - 1;
    while (left <= right) {
      int mid = right - ((right - left) / 2);
      if (target < vector[mid]) {
        right = mid - 1;
      } else if (target > vector[mid]) {
        left = mid + 1;
      } else {
        return true;
      }
    }
    return false;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  std::vector<std::vector<int>> matrix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  std::cout << s.searchMatrix(matrix, 1) << "\n";
  std::cout << s.searchMatrix(matrix, 4) << "\n";
}
