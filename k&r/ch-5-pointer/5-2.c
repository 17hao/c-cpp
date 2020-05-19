#include <stdio.h>

void swap(int *x, int *y);

int main() {
  int x = 2;
  int y = 3;
  swap(&x, &y);
  printf("x-y: %d, %d\n", x, y);
}

void swap(int *x, int *y) {
  int tmp = *x;
  *x = *y;
  *y = tmp;
}