#include <stdio.h>

// Using only bit-level and logical operations.
// Return 1 when x y are equal and 0 otherwise.
int numcmp(int i, int j) {
  return (i ^ j) == 0 ? 1 : 0;
}

int main(int argc, char **argv) {
  printf("%d\n", numcmp(-1, -1));
  printf("%d\n", numcmp(-1, 0));
  printf("%d\n", numcmp(0, 0));
  printf("%d\n", numcmp(1, 0));
  printf("%d\n", numcmp(1, 1));
  printf("%d\n", numcmp(10000, 10000));
}