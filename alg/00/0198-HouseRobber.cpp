#include <algorithm>
#include <iostream>
#include <vector>

using namespace ::std;

/**
 * leetcode 198 house robber
 *
 *
 *
 * @since 2021-10-28 Thursday 17:00
 */
class Solution {
   public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        // return rob(nums, nums.size() - 1);
        // return rob(nums, nums.size() - 1, memo);
        return robIterative(nums);
    }

   private:
    int rob(vector<int>& nums, int i) {
        if (i < 0) {
            return 0;
        }
        return max(rob(nums, i - 2) + nums[i], rob(nums, i - 1));
    }

    int rob(vector<int>& nums, int i, vector<int>& memo) {
        if (i < 0) {
            return 0;
        }
        if (memo[i] >= 0) {
            return memo[i];
        }
        int res = max(rob(nums, i - 2, memo) + nums[i], rob(nums, i - 1));
        memo[i] = res;
        return res;
    }

    int robIterative(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int len = nums.size();
        vector<int> memo(len);
        memo[0] = nums[0];
        memo[1] = max(nums[0], nums[1]);
        for (int i = 2; i < len; i++) {
            int val = nums[i];
            memo[i] = max(memo[i - 2] + val, memo[i - 1]);
        }
        return memo[len - 1];
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    // vector<int> nums{1, 2, 3, 1};
    // vector<int> nums{2, 7, 9, 3, 1};
    // vector<int> nums{2, 1, 1, 2};
    vector<int> nums{2, 1};
    cout << s.rob(nums);
}
