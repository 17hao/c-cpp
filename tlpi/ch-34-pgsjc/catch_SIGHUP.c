#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void handler(int sig) {
}

int main(int argc, char *argv[]) {
  pid_t child_pid;
  struct sigaction sa;

  setbuf(stdout, NULL);

  sigemptyset(&sa.sa_mask);
  sa.sa_flags = 0;
  sa.sa_handler = handler;
  if (sigaction(SIGHUP, &sa, NULL) == -1) {
    printf("sigaction\n");
    exit(-1);
  }

  child_pid = fork();
  if (child_pid == -1) {
    printf("fork\n");
    exit(-1);
  }

  if (child_pid == 0 && argc > 1) {
    if (setpgid(0, 0) == -1) { // calling process'pid is used && make the pgid the same as its pid
      printf("setpgid\n");
      exit(-1);
    }
  }

  printf("PID: %d; PPID: %d; PGID: %d; SID: %d\n", getpid(), getppid(), getpgrp(), getsid(0));

  alarm(60);

  for (;;) {
    pause();
    printf("%d: caught SIGHUP\n", getpid());
  }
}