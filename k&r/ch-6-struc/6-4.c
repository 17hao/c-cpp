#include <stdio.h>

typedef struct tn {
  int val;
  struct tn *left;
  struct tn *right;
} TreeNode;

void preOrderTraversal(TreeNode *root) {
  if (root == NULL) return;
  printf("%d -> ", root->val);
  preOrderTraversal(root->left);
  preOrderTraversal(root->right);
}

int main() {
  TreeNode root = {1};
  TreeNode n = {3};
  TreeNode m = {5};
  root.left = &n;
  root.right = &m;
  root.left->left = &m;
  preOrderTraversal(&root);
  //    printf("root's val is: %d\n", root.val);
  //    printf("root'left val is: %d\n", root.left->val);
  //    printf("root'right val is: %d\n", root.right->val);
}