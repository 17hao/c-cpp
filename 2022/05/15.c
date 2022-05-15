#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test(size_t len) {
  printf("%zu\n", len);
}

int main(int argc, char **argv) {
  // char astr[] = "1234";
  // printf("len(%s)=%lu\n", astr, strlen(astr));

  char str[100] = "";
  // str[0] = 'a';
  // str[1] = 'b';
  str[10] = 'c';
  printf("%s\n", str);
  int nums[] = {1, 2};

  printf("%d\n", INT_MIN);

  long int i = 1;

  printf("%zu\t%zu\n", sizeof INT_MIN, sizeof -2147483648);

  test(-1);
}