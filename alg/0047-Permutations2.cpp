#include <algorithm>
#include <iostream>
#include <vector>

/**
 * Given a collection of numbers, nums, that might contain duplicates, return
 * all possible permutations in any order.
 *
 * @since 2021-9-16 Thursday 16:57 - 18:10
 */
class Solution {
public:
  std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> res;
    std::vector<int> temp;
    int len = nums.size();
    std::vector<bool> used(len);
    doPermute(nums, temp, res, used);
    return res;
  }

private:
  void doPermute(std::vector<int> nums, std::vector<int> &temp, std::vector<std::vector<int>> &res,
                 std::vector<bool> &used) {
    int len = nums.size();
    if (len == temp.size()) {
      res.push_back(temp);
      return;
    } else {
      for (int i = 0; i < len; i++) {
        if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) {
          continue;
        } else {
          temp.push_back(nums[i]);
          used[i] = true;
          doPermute(nums, temp, res, used);
          temp.pop_back();
          used[i] = false;
        }
      }
    }
  }
};

void myPrint(std::vector<std::vector<int>> vectors) {
  for (auto vector : vectors) {
    std::cout << "[";
    for (int i : vector) {
      std::cout << i << " ";
    }
    std::cout << "]\n";
  }
  std::cout << "\n";
}

int main(int argc, char const *argv[]) {
  Solution s;
  std::vector<int> nums0{1, 2, 3};
  std::vector<int> nums1{1, 1, 3};
  std::vector<int> nums2{1, 3, 1};
  myPrint(s.permuteUnique(nums0));
  myPrint(s.permuteUnique(nums1));
  myPrint(s.permuteUnique(nums2));
}
