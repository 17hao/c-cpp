#include <iostream>
#include <vector>

/**
 * Pascal's triangle
 *
 * @since 2021-7-23 Friday 9:38
 */
class Solution {
public:
  std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> res;
    std::vector<int> pre;
    std::vector<int> cur;
    res.push_back({1});
    for (int i = 1; i < numRows; i++) {
      pre.clear();
      cur.clear();
      pre = res[i - 1];
      cur.push_back(1);
      for (int j = 1; j < i; j++) {
        cur.push_back(pre[j - 1] + pre[j]);
      }
      cur.push_back(1);
      res.push_back(cur);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  std::vector<std::vector<int>> res = s.generate(5);
  for (auto &v : res) {
    std::cout << "[";
    for (auto &i : v) {
      std::cout << i << " ";
    }
    std::cout << "]\n";
  }
}