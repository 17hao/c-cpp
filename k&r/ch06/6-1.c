#include <stdio.h>

struct point {
  int x;
  int y;
};

struct point makepoint(int x, int y) {
  struct point temp = {x, y};
  return temp;
}

int main() {
  struct point pt = makepoint(10, 20);
  printf("%d, %d\n", pt.x, pt.y);
}