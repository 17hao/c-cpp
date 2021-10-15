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
    vector<int> _spiralOrder(vector<vector<int>>& matrix) {
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

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int rows = matrix.size();
        int cols = matrix[0].size();
        doSpiralOrder(res, matrix, 0, 0, rows - 1, cols - 1);
        return res;
    }

    void doSpiralOrder(vector<int>& res, vector<vector<int>>& matrix, int upperR, int upperC,
                       int lowerR, int lowerC) {
        if (upperR > lowerR || upperC > lowerC) {
            return;
        }
        if (upperR == lowerR) {
            for (int i = upperC; i <= lowerC; i++) {
                res.push_back(matrix[upperR][i]);
            }
            return;
        }
        if (upperC == lowerC) {
            for (int i = upperR; i <= lowerR; i++) {
                res.push_back(matrix[i][upperC]);
            }
            return;
        }
        for (int i = upperC; i < lowerC; i++) {
            res.push_back(matrix[upperR][i]);
        }
        for (int i = upperR; i < lowerR; i++) {
            res.push_back(matrix[i][lowerC]);
        }
        for (int i = lowerC; i > upperC; i--) {
            res.push_back(matrix[lowerR][i]);
        }
        for (int i = lowerR; i > upperR; i--) {
            res.push_back(matrix[i][upperC]);
        }
        doSpiralOrder(res, matrix, upperR + 1, upperC + 1, lowerR - 1, lowerC - 1);
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    vector<vector<vector<int>>> matrixs;
    matrixs.push_back(
        {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}});
    matrixs.push_back({{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}});
    matrixs.push_back({{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}});
    matrixs.push_back({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    matrixs.push_back({{1, 2}, {3, 4}});
    matrixs.push_back({{1, 2}});
    matrixs.push_back({{1, 2, 3}});
    matrixs.push_back({{1, 2}, {3, 4}, {5, 6}});
    matrixs.push_back({{1}, {2}, {3}});
    for (auto matrix : matrixs) {
        vector<int> res = s.spiralOrder(matrix);
        for (int i : res) {
            cout << i << " ";
        }
        cout << "\n";
    }
}
