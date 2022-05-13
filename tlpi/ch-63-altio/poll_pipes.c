#include <sys/poll.h>

#include "../lib/tlpi_hdr.h"

int main(int argc, char *argv[]) {
  if (argc < 2 || strcmp(argv[1], "--help") == 0) {
    printf("%s num-pipes [num-writes]\n", argv[0]);
    exit(-1);
  }

  int num_pipes = atoi(argv[1]), num_writes = atoi(argv[2]);

  struct pollfd *poll_fd = calloc(num_pipes, sizeof(struct pollfd));

  int(*pfds)[2] = calloc(num_writes, sizeof(int[2]));

  if (poll_fd == NULL) {
    printf("calloc\n");
    exit(-1);
  }

  /* create the number of pipes specify on the command line */
  for (int j = 0; j < num_pipes; j++) {
    if (pipe(pfds[j]) == -1) {
      printf("pipe");
      exit(-1);
    }
  }

  /* perform specified number of writes to random pipes */
  srandom((int)time(NULL));
  for (int i = 0; i < num_writes; i++) {
    int rand_pipe = random() % num_pipes;
    printf("Writing to fd: %3d (read fd: %3d)\n", pfds[rand_pipe][1], pfds[rand_pipe][0]);
    if (write(pfds[rand_pipe][1], "a", 1) != -1) {
      printf("write");
      exit(-1);
    }
  }

  for (int i = 0; i < num_pipes; i++) {
    poll_fd[i].fd = pfds[i][0];
    poll_fd[i].events = POLLIN;
  }

  int ready = poll(poll_fd, num_pipes, -1);
  if (ready == -1) {
    printf("poll");
    exit(-1);
  }

  printf("poll() returned %d\n", ready);

  for (int i = 0; i < num_pipes; i++) {
    if (poll_fd[i].revents & POLLIN) {
      printf("Readable: %3d\n", poll_fd[i].fd);
    }
  }

  exit(EXIT_SUCCESS);
}