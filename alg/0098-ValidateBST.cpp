#include <iostream>
#include <vector>

#include "TreeNodeCpp.h"

/**
 * Given the root of a binary tree, determine if it is a
 * valid binary search tree.
 *
 * @since 2021-9-22 Wednesday 16:25 - 16:46
 */
class Solution {
public:
  bool isValidBST(TreeNode *root) {
    std::vector<int> v;
    inorderTraversal(root, v);
    int len = v.size();
    for (int i = 1; i < len; i++) {
      if (v[i] <= v[i - 1]) {
        return false;
      }
    }
    return true;
  }

private:
  void inorderTraversal(TreeNode *root, std::vector<int> &v) {
    if (root == nullptr) {
      return;
    } else {
      inorderTraversal(root->left, v);
      v.push_back(root->val);
      inorderTraversal(root->right, v);
    }
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(3);
  // root->right = new TreeNode(10);
  root->right = new TreeNode(4);
  std::cout << s.isValidBST(root);
}
