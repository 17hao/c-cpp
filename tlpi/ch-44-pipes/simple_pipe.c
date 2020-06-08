#include <sys/wait.h>
#include "../lib/tlpi_hdr.h"
#define BUF_SIZE 10

int main(int argc, char *argv[]) {
  int pfd[2];
  char buf[BUF_SIZE];
  ssize_t num_read;

  if (argc != 2 || strcmp(argv[1], "--help") == 0) {
    printf("%s string\n", argv[0]);
    exit(-1);
  }

  if (pipe(pfd) == -1) {
    printf("pipe");
    exit(-1);
  }

  switch (fork()) {
    case -1:printf("fork");
      exit(-1);
    case 0:
      if (close(pfd[1]) == -1) {
        printf("close");
        exit(-1);
      }

      for (;;) {
        num_read = read(pfd[0], buf, BUF_SIZE);
        if (num_read == -1) {
          printf("read");
          exit(-1);
        }
        if (num_read == 0) {
          break;
        }
        if (write(STDOUT_FILENO, buf, num_read) != num_read) {
          printf("child - partial/failed write");
          exit(-1);
        }
      }

      write(STDOUT_FILENO, "\n", 1);
      if (close(pfd[0]) == -1) {
        printf("close");
        exit(-1);
      }
      exit(EXIT_SUCCESS);
    default:
      if (close(pfd[0]) == -1) {
        printf("close");
        exit(EXIT_SUCCESS);
      }

      if (write(pfd[1], argv[1], strlen(argv[1])) != strlen(argv[1])) {
        printf("write");
        exit(-1);
      }

      if (close(pfd[1]) == -1) {
        printf("close");
        exit(-1);
      }

      wait(NULL);
      exit(EXIT_SUCCESS);
  }
}