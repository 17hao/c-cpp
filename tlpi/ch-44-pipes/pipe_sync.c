#include "../lib/tlpi_hdr.h"
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  time_t t;
  int pfd[2];

  if (argc < 2 || strcmp(argv[1], "--help") == 0) {
    printf("%s sleep-time...\n", argv[0]);
    exit(EXIT_SUCCESS);
  }

  setbuf(stdout, NULL);

  if (pipe(pfd) == -1) {
    printf("pipe");
    exit(-1);
  }

  printf("%s Parent started\n", cur_time("%T"));

  for (int i = 0; i < argc; i++) {
    switch (fork()) {
      case -1:printf("fork()");
        exit(-1);
      case 0:
        if (close(pfd[0]) == -1) {
          printf("close");
          exit(-1);
        }

        sleep(atoi(argv[i]));
        printf("%s Child %d (PID=%d) closing pipe\n", cur_time("%T"), i, getpid());

        if (close(pfd[1]) == -1) {
          printf("close");
          exit(-1);
        }
        exit(EXIT_SUCCESS);
      default:break;
    }
  }

  /* Parent comes here */
  if (close(pfd[1]) == -1) { /* write end is unused */
    printf("close");
    exit(-1);
  }

  int dummy;
  if (read(pfd[0], &dummy, 1) != 0) {
    printf("read");
    exit(-1);
  }

  printf("%s Parent ready to go\n", cur_time("%T"));

  exit(EXIT_SUCCESS);
}