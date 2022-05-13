#include "csapp.h"

void sigint_handler(int sig) {
  printf("\nCaught SIGINT!\n");
  exit(0);
}

int main() {
  // Install the SIGINT handler
  if (signal(SIGINT, sigint_handler) == SIG_ERR) {
    unixError("signal error");
  }

  pause(); // Wait for the receipt of a signal

  return 0;
}