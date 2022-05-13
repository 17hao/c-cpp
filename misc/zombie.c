#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid;
  int status;

  pid = fork();

  if (pid == 0) {
    printf("child pid: %d\n", getpid());
    exit(0);
  }

  sleep(10);

  pid = wait(&status);
  fprintf(stdout, "[%d] Child process %d exited with status %d\n", getpid(), pid, WEXITSTATUS(status));

  exit(0);
}