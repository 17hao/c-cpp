#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sig_handler(int sig) {
  static int count = 0;

  if (sig == SIGINT) {
    count++;
    printf("\nCaught SIGINT %d\n", count);
    return;
  }
  if (sig == SIGQUIT) {
    printf("\nCaught SIGQUIT\n");
    exit(EXIT_SUCCESS);
  }
}

int main() {
  if (signal(SIGINT, sig_handler) == SIG_ERR)
    exit(-1);
  if (signal(SIGQUIT, sig_handler) == SIG_ERR)
    exit(-1);

  for (;;)
    pause();
}