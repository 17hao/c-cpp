#include <iostream>
#include <vector>

using namespace ::std;

/**
 * Given a non-empty array of integer nums, every element appears twice except for one.
 * Find the single one.
 * 
 * You must implement a solution with a linear time complexity and use only 
 * constant extra space.
 *
 * @since 2021-10-22 Friday 14:37
 */
class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int n : nums) {
            res ^= n;
        }
        return res;
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    // vector<int> nums = {2, 2, 1};
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << s.singleNumber(nums);
}
