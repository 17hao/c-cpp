#include <algorithm>
#include <iostream>
#include <vector>

using namespace ::std;

/**
 * leetcode 56
 *
 * @since 2021-10-8 Friday
 */
class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comparator);
        vector<vector<int>> res;
        int len = intervals.size();
        for (int i = 0; i < len; i++) {
            int curStart = intervals[i][0];
            int curEnd = intervals[i][1];
            int end = curEnd;
            while (i < len - 1 && end >= intervals[i + 1][0]) {
                end = max(end, intervals[i + 1][1]);
                i++;
            }
            res.push_back({curStart, end});
        }
        return res;
    }

   private:
    static bool comparator(vector<int> v1, vector<int> v2) {
        return v1[0] < v2[0];
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    // vector<vector<int>> intervals{{1, 4}, {4, 5}};
    vector<vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    // vector<vector<int>> intervals{{2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}};
    auto res = s.merge(intervals);
    for (auto v : res) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }
}
