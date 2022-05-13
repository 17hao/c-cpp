#include <algorithm>
#include <iostream>
#include <vector>

/**
 * Given an array nums of distinct integers, return all the possible
 * permuttions.
 *
 * @since 2021-9-16 Thursday 15:14 - 15:51
 */
class Solution {
public:
  std::vector<std::vector<int>> permute(std::vector<int> &nums) {
    std::vector<int> temp;
    std::vector<std::vector<int>> res;
    doPermute(nums, temp, res);
    return res;
  }

private:
  void doPermute(std::vector<int> nums, std::vector<int> &temp, std::vector<std::vector<int>> &res) {
    int len = nums.size();
    if (temp.size() == len) {
      res.push_back(temp);
      return;
    } else {
      for (int i = 0; i < len; i++) {
        int num = nums[i];
        if (std::find(temp.begin(), temp.end(), num) == temp.end()) {
          temp.push_back(num);
          doPermute(nums, temp, res);
          temp.pop_back();
        } else {
          continue;
        }
      }
    }
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  std::vector<int> nums{1, 2, 3};
  auto res = s.permute(nums);
  for (auto vector : res) {
    std::cout << "[";
    for (int i : vector) {
      std::cout << i << " ";
    }
    std::cout << "]\n";
  }
}
