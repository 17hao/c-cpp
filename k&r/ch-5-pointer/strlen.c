#include <stdio.h>

int my_strlen(char *s) {
  int i = 0;
  for (; *s != '\0'; s++) {
    i++;
  }
  return i;
}

int main() {
  char *s = "hello";
  int len = my_strlen(s);
  printf("length of string is: %d\n", len);
}