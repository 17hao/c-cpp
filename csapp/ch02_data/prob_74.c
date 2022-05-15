#include <stdio.h>

int tadd_ok(int x, int y) {
  if (x > 0 && y > 0 && x + y <= 0) {
    return 0;
  }
  if (x < 0 && y < 0 && x + y >= 0) {
    return 0;
  }
  return 1;
}

// Determin whether arguments can be subtracted without overflow.
// Return 1 if x y can be subtracted without overflow 0 otherwise.
int tsub_ok(int x, int y) {
  // return tadd_ok(x, -y); // this code is buggy
  
}

int main(int argc, char **argv) {
  int i = -2147483648;
  printf("-((int)-2147483648)=%d\n", -i);
  printf("%d\n", tsub_ok(1, -2147483648));
  printf("%d\n", tsub_ok(-1, -2147483648));
}