/**
 * pointers and arrays
 */

#include <stdio.h>

void func() {
  int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  // int* pa = &arr[0];
  int *pa = arr;
  printf("%d\n", *pa);
  printf("%d\n", *(pa + 1));
  printf("%d\n", *(arr + 2));
}

int my_strlen(char *s) {
  int res = 0;
  for (; *s != '\0'; s++) {
    res++;
  }
  return res;
}

int main() {
  char *s = "hello";
  printf("%d", my_strlen(s));
}
