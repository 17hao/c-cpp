#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * ctrl-c interrupts a process(SIGINT)
 * ctrl-z suspends a process(SIGSTP)
 * ctrl-\ (SIGQUIT)
 *
 * use `jobs` to show background processes
 * fg %x
 */

void sig_handler(int sig) {
  printf("\nOuch!\n");
}

int main() {
  if (signal(SIGINT, sig_handler) == SIG_ERR) {
    printf("\nsignal");
    exit(-1);
  }

  for (int i = 0;; i++) {
    printf("%d\n", i);
    sleep(3);
  }
}