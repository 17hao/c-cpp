#include <stdio.h>

// determine the version of C standard used by the compiler
int main() {
  printf("%d\n", __STDC__);
  printf("%ld\n", __STDC_VERSION__);
}