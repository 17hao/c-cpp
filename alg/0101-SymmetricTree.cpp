#include "TreeNodeCpp.h"

/**
 * Check whether the tree is a mirror of itself.
 *
 * @since 2021-8-13 Friday 14:27
 */
class Solution {
public:
  bool isSymmetric(struct TreeNode *root) {
    return mirror(root->left, root->right);
  }

private:
  bool mirror(struct TreeNode *left, struct TreeNode *right) {
    if (left == nullptr && right == nullptr) {
      return true;
    } else {
      if (left && right && left->val == right->val) {
        return mirror(left->left, right->right) && mirror(left->right, right->left);
      } else {
        return false;
      }
    }
  }
};