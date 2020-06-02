#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// ./a.out
// ./a.out > a printf Hello,world twice
int main() {
  printf("Hello,world\n");
  write(STDOUT_FILENO, "sqh\n", 4);

  if (fork() == -1) {
    exit(-1);
  }

  exit(EXIT_SUCCESS);
}