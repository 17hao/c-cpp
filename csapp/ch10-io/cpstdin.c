// Copy standard input to standard ouput, 1 byte a time

#include "csapp.h"

int main() {
  char c;

  while (1) {
    size_t s = read(STDIN_FILENO, &c, 1);
    // size_t s = rio_readn(STDIN_FILENO, &c, 1);
    write(STDOUT_FILENO, &c, 1);
    // rio_writen(STDOUT_FILENO, &c, 1);
  }
}