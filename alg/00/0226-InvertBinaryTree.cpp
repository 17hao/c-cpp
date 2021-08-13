#include <iostream>

#include "TreeNodeCpp.h"

/**
 * invert binary tree
 *
 * @since 2021-8-12 Thursday 19:19 - 19:30
 */
class Solution {
   public:
    struct TreeNode* invertTree(struct TreeNode* root) {
        doInvertTree(root);
        return root;
    }

    void printTree(struct TreeNode* root) {
        if (root == nullptr) {
            return;
        } else {
            std::cout << root->val << " ";
            printTree(root->left);
            printTree(root->right);
        }
    }
   
   private:
    void doInvertTree(struct TreeNode* root) {
        if (root == nullptr) {
            return;
        } else {
            struct TreeNode* left = root->left;
            root->left = root->right;
            root->right = left;
            doInvertTree(root->left);
            doInvertTree(root->right);
        }
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    s.invertTree(root);
    s.printTree(root);
    return 0;
}
