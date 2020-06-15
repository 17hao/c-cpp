#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int idata = 1; /* Allocate in data segment */

int main() {
  int istack = 2; /* Allocate in stack segment */
  pid_t child_pid;

  switch (
      child_pid =
          fork()) { /* Both child and parent processes will execute form here */
    case -1:
      printf("fork error\n");
      exit(-1);
    case 0:
      idata *= 3;
      istack *= 3;
      break;
    default:
      sleep(3);
      break;
  }

  printf("PID=%ld %s idata=%d istack=%d\n", (long)getpid(),
         (child_pid == 0) ? "child" : "parent", idata, istack);

  exit(EXIT_SUCCESS);
}