#include "csapp.h"

int main() {
  pid_t pid;
  int x = 1;

  // child process
  if ((pid = Fork()) == 0) {
    printf("child: pid=%d x=%d\n", getpid(), ++x);
    exit(0);
  }

  // parent process
  int status;
  wait(&status); // equivalent to calling waitpid(-1, &status, 0)
  printf("parent: pid=%d x=%d\n", getpid(), --x);
  exit(0);
}