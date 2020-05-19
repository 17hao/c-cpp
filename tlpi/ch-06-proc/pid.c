#include <unistd.h>
#include <stdio.h>

int main() {
  int pid = getpid();
  printf("pid: %d\n", pid);

  int ppid = getppid();
  printf("parent pid: %d\n", ppid);
}