#include <iostream>
#include <vector>

/**
 * remove all occurances of 'val' in 'nums'
 *
 * @since 2021-8-25 Wednesday 14:42
 */
class Solution {
public:
  int removeElement(std::vector<int> &nums, int val) {
    int len = nums.size();
    int point = len;
    int i = 0;
    while (i < point) {
      if (nums[i] == val) {
        swap(nums, i, --point);
      } else {
        i++;
      }
    }
    return point;
  }

private:
  void swap(std::vector<int> &nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  // std::vector<int> nums = {1, 2, 3, 1, 2, 3};  // return 4
  std::vector<int> nums = {1, 2, 3, 1, 1, 1, 1, 1, 2, 3}; // return 4
  int len = s.removeElement(nums, 1);
  for (int i = 0; i < len; i++) {
    std::cout << nums[i] << " ";
  }
}
