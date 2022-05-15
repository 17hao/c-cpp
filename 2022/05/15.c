#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  // char astr[] = "1234";
  // printf("len(%s)=%lu\n", astr, strlen(astr));

  char str[100] = "";
  // str[0] = 'a';
  // str[1] = 'b';
  str[10] = 'c';
  printf("%s\n", str);
  int nums[] = {1, 2};
}