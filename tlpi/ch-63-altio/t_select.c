#include <sys/select.h>
#include "../lib/tlpi_hdr.h"

int main(int argc, char *argv[]) {
  fd_set read_fds, write_fds;
  int fd, nfds = 0;
  struct timeval timeout;
  struct timeval *pto;

  if (argc < 2 || strcmp(argv[2], "--help") == 0) {
    printf("usage: %s", argv[0]);
    exit(-1);
  }

  if (strcmp(argv[1], "-") == 0) {
    pto = NULL;
  } else {
    pto = &timeout;
    timeout.tv_sec = atoi(argv[2]);
    timeout.tv_usec = 0;
  }

  FD_ZERO(&read_fds);
  FD_ZERO(&write_fds);

  int num_read;
  char buf[10];
  for (int i = 2; i < argc; i++) {
    num_read = sscanf(argv[i], "%d%2[rw]", &fd, buf);
    if (num_read != 2) {
      printf("sscanf");
      exit(-1);
    }

    if (fd >= FD_SETSIZE) {
      printf("file descriptor exceeds limit\n");
      exit(-1);
    }

    if (fd >= nfds) {
      nfds = fd + 1;
    }

    if (strchr(buf, 'r') != NULL) {
      FD_SET(fd, &read_fds);
    }
    if (strchr(buf, 'w') != NULL) {
      FD_SET(fd, &write_fds);
    }
  }

  int ready;
  ready = select(nfds, &read_fds, &write_fds, NULL, pto);

  if (ready == -1) {
    printf("select");
    exit(-1);
  }

  printf("ready = %d\n", ready);

  for (fd = 0; fd < nfds; fd++) {
    printf("%d: %s%s\n", fd, FD_ISSET(fd, &read_fds) ? "r" : "", FD_ISSET(fd, &write_fds) ? "w" : "");
  }

  if (pto != NULL) {
    printf("timeout after select() %ld.%03ld\n", (long) timeout.tv_sec, (long) timeout.tv_usec / 1000);
  }

  exit(EXIT_SUCCESS);
}
