#include <stdio.h>

// Determine whether arguments can be added without overflow.
// Return 1 if i j can be added without causing overflow.
int uadd_ok(unsigned i, unsigned j) {
  unsigned min = i > j ? j : i;
  return (i + j) > min ? 1 : 0;
}

int main(int argc, char **argv) {
  printf("%d\n", uadd_ok(1000, 1000));
  printf("%d\n", uadd_ok(2147483648, 2147483648));
  printf("%d\n", (unsigned)1 + (unsigned)4294967295); // 0 abelian group
}