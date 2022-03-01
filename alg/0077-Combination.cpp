#include <iostream>
#include <vector>

using namespace ::std;

/**
 * Given two numbers n and k, return all possible combinations of
 * k numbers out of the range [1, n].
 *
 * @since 2021-11-9 Tuesday 16:28 - 16:54
 */
class Solution {
   public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> v;
        doCombine(n, 1, k, res, v);
        return res;
    }

   private:
    void doCombine(int n, int cur, int remain, vector<vector<int>>& res, vector<int>& v) {
        if (remain == 0) {
            res.push_back(v);
            return;
        }

        for (int i = cur; i <= n; i++) {
            v.push_back(i);
            doCombine(n, i + 1, remain - 1, res, v);
            v.pop_back();
        }
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    auto res = s.combine(4, 2);
    for (auto v : res) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }
}
