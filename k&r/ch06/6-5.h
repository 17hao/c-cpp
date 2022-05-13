/**
 * It is illegal for a structure to contain an instance of itself.
 * But
 *   struct tnode* left
 * decalares left to be a pointer to a tnode, not a tnode itself.
 */
struct tnode {
  char *word;
  int count;
  struct tnode *left;
  struct tnode *right;
};

struct tnode *talloc();

void treeprint(struct tnode *root);