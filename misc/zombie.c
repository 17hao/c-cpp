#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
  pid_t pid;
  int status;

  pid = fork();

  if (pid == 0) {
    printf("child pid: %d\n", getpid());
    exit(0);
  }

  sleep(5);

  pid = wait(&status);
  fprintf(stderr, "[%d] Child process %d exited with status %d\n", getpid(), pid, WEXITSTATUS(status));

  exit(0);
}