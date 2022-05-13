/**
 * address arithmetic
 */

#define ALLOCSIZE 1000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp;             /* next free position */

/**
 * return pointer to n characters
 */
char *my_alloc(int n) {
  if (allocbuf + ALLOCSIZE - allocp >= n) {
    allocp += n;
    return allocp - n;
  } else {
    return 0;
  }
}

/**
 * free storage pointed to by p
 */
void my_free(char *p) {
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
    allocp = p;
  }
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
