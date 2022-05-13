#include <iostream>
#include <vector>

using namespace ::std;

/**
 * Given a non-empty array of integer numbers, every element appears three times except for one.
 * Find the single one.
 *
 * You must implement a solution with linear time complexity and use only constant extra space.
 *
 * h l input h' l'
 * 0 0   0   0  0
 * 0 0   1   0  1
 *
 * 0 1   0   0  1
 * 0 1   1   1  0
 *
 * 1 0   0   1  0
 * 1 0   1   0  0
 *
 * @since 2021-10-25 Monday 16:00
 */
class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int low_bits = 0, high_bits = 0;
    for (int num : nums) {
      low_bits = ~high_bits & (low_bits ^ num);
      high_bits = ~low_bits & (high_bits ^ num);
    }
    return low_bits;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> nums = {0, 1, 0, 1, 0, 1, 99};
  cout << s.singleNumber(nums);
}
