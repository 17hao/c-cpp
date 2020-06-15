#include <stdio.h>

int main() {
  char *s = "1 2 + 3 4 + *";
  for (int i = 0; i < 13; i++) {
    printf("%c", s[i]);
  }
  printf("%c\n", s[1]);
  printf("%f\n", (double)(s[1] - '0'));
}