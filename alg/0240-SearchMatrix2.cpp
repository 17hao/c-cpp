#include <iostream>
#include <vector>

/**
 * Searching for a value in an m x n matrix.
 *
 * Integers in each row are sorted ascending from left to right.
 * Integers in each column are sorted ascending from top to bottom.
 *
 * @since 2021-9-17 Friday 16:00
 */
class Solution {
public:
  bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
    int rows = matrix.size();
    int columns = matrix[0].size();
    int r = 0, c = columns - 1;
    while (r < rows && c >= 0) {
      if (matrix[r][c] > target) {
        c--;
      } else if (matrix[r][c] < target) {
        r++;
      } else {
        return true;
      }
    }
    return false;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  std::vector<std::vector<int>> matrix{
      {0, 4, 7, 11, 15}, {1, 5, 8, 12, 19}, {2, 6, 9, 16, 22}, {3, 13, 14, 17, 24}, {4, 21, 23, 26, 30}};

  std::cout << s.searchMatrix(matrix, 1) << "\n";
  std::cout << s.searchMatrix(matrix, 4) << "\n";
  std::cout << s.searchMatrix(matrix, 10) << "\n";
}
