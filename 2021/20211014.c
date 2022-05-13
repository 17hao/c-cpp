#include <stdio.h>

int main(int argc, char const *argv[]) {
  unsigned int ui = 0x7fffffffu;
  int i = 0x7fffffff; // max signed int

  printf("unsigned int: %u\n", ui + 1u);
  printf("unsigned int in hex: %#x\n", ui + 1u);
  printf("int: %d\n", i + 1);

  printf("%d\n", (i + 1) / 10);
  printf("%d\n", (i + 1u) / 10);
}
