#include <algorithm>
#include <iostream>
#include <vector>

using namespace ::std;

/**
 * Given a m x n matrix, return all elements of the matrix in spiral order.
 *
 * @since 2021-10-12 Tuesday 10:52
 */
class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int circles = max(1, (min(rows, cols) + 1) / 2);
        vector<int> res;
        for (int cur = 0; cur < circles; cur++) {
            for (int i = cur; i < cols - cur; i++) {
                res.push_back(matrix[cur][i]);
            }
            if (rows % 2 == 1 && rows - (cur + 1) * 2 <= 0) {
                break;
            }
            for (int i = cur + 1; i < rows - 1 - cur; i++) {
                res.push_back(matrix[i][cols - 1 - cur]);
            }
            for (int i = cols - 1 - cur; i >= cur; i--) {
                res.push_back(matrix[rows - 1 - cur][i]);
            }
            if (cols % 2 == 1 && cols - (cur + 1) * 2 <= 0) {
                break;
            }
            for (int i = rows - 2 - cur; i > cur; i--) {
                res.push_back(matrix[i][cur]);
            }
        }
        return res;
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    // vector<vector<int>> matrix{
    //     {1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}};
    // vector<vector<int>> matrix{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    // vector<vector<int>> matrix{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    // vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // vector<vector<int>> matrix{{1, 2}, {3, 4}};
    // vector<vector<int>> matrix{{1, 2}};
    // vector<vector<int>> matrix{{1, 2, 3}};
    vector<vector<int>> matrix{{1, 2}, {3, 4}, {5, 6}};
    // vector<vector<int>> matrix{{1}, {2}, {3}};
    vector<int> res = s.spiralOrder(matrix);
    for (int i : res) {
        cout << i << " ";
    }
}
