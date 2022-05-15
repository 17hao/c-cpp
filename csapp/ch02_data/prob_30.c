#include <stdio.h>

// Determin whether x y can be added without overflow.
// Return 1 if x y can be added without causing overflow 0 otherwise.
// 't' means two's-complement
int tadd_ok(int x, int y) {
  if (x > 0 && y > 0 && x + y <= 0) {
    return 0;
  }
  if (x < 0 && y < 0 && x + y >= 0) {
    return 0;
  }
  return 1;
}

int main(int argc, char **argv) {
  printf("%d\n", tadd_ok(1, 1));
  printf("%d\n", tadd_ok(1073741824, 1073741824));
  printf("%d\n", tadd_ok(2147483647, 1));
  printf("%d\n", tadd_ok(-2147483648, -1));
  printf("%d\n", tadd_ok(-2147483648, 1));
}