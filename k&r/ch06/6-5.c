#include "6-5.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}

/**
 * Add a node with word, at or below root
 */
struct tnode *addtree(struct tnode *root, char *word) {
  int cond;

  if (root == NULL) {
    root = talloc();
    root->word = word;
    root->count = 1;
    root->left = root->right = NULL;
  } else if (cond = strcmp(word, root->word) == 0) {
    root->count++;
  } else if (cond < 0) {
    addtree(root->left, word);
  } else {
    addtree(root->right, word);
  }
  return root;
}

struct tnode *talloc() {
  return (struct tnode *)malloc(sizeof(struct tnode));
}

void treeprint(struct tnode *root) {
  if (root != NULL) {
    treeprint(root->left);
    printf("%d ", root->word);
    treeprint(root->right);
  }
}