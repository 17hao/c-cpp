#include <iostream>
#include <vector>

/**
 * Given an integer array nums sorted in non-decreasing order, remove the
 * duplicates in-place such that each unique element appears only once. The
 * relative order of the elements should be kept the same.
 *
 * @since 2021-9-15 Wednesday 15:10 - 15:29
 */
class Solution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    if (nums.size() == 0) {
      return 0;
    }
    int curNum = nums[0];
    int curIndex = 1;
    int resIndex = 0;
    int len = nums.size();
    while (curIndex < len) {
      if (nums[curIndex] == curNum) {
        curIndex++;
      } else {
        curNum = nums[curIndex];
        swap(nums, curIndex++, ++resIndex);
      }
    }
    return resIndex + 1;
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
  std::vector<int> v{1, 2, 2, 3, 4, 4, 4, 5};
  int res = s.removeDuplicates(v);
  for (int i = 0; i < res; i++) {
    std::cout << v[i] << " ";
  }
  return 0;
}
