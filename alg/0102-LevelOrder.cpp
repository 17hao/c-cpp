#include <iostream>
#include <vector>

#include "TreeNodeCpp.h"

/**
 * Level order traversal of a binary tree
 *
 * @since 2021-8-26 Thursday 16:15
 */
class Solution {
public:
  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    std::vector<std::vector<int>> res = {};
    _levelOrder(root, res, 0);
    return res;
  }

private:
  void _levelOrder(TreeNode *root, std::vector<std::vector<int>> &res, int level) {
    if (root == nullptr) {
      return;
    } else {
      if (res.size() == level) {
        res.push_back({root->val});
      } else {
        std::vector<int> &l = res[level];
        l.push_back(root->val);
      }
      _levelOrder(root->left, res, level + 1);
      _levelOrder(root->right, res, level + 1);
    }
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  std::vector<std::vector<int>> res = s.levelOrder(root);
  for (auto v : res) {
    for (int i : v) {
      std::cout << i << " ";
    }
    std::cout << "\n";
  }
}
