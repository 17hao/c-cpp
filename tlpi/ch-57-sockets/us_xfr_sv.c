#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SV_SOCK_PATH "/tmp/us_xfr"

#define BACKLOG 5

#define BUF_SIZE 100

int main() {
  struct sockaddr_un addr;
  int sfd, cfd; /* socket fd; connection fd */
  ssize_t read_num;
  char buffer[BUF_SIZE];

  sfd = socket(AF_UNIX, SOCK_STREAM, 0);
  if (sfd == -1)
    exit(-1);

  if (remove(SV_SOCK_PATH) == -1 && errno != ENOENT) {
    printf("remove-%s", SV_SOCK_PATH);
    exit(-1);
  }

  memset(&addr, 0, sizeof(struct sockaddr_un));
  addr.sun_family = AF_UNIX;
  strncpy(addr.sun_path, SV_SOCK_PATH, sizeof(addr.sun_path) - 1);

  if (bind(sfd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) == -1)
    exit(-1);

  if (listen(sfd, BACKLOG) == -1)
    exit(-1);

  for (;;) {
    if ((cfd = accept(sfd, NULL, NULL)) == -1) {
      printf("accept\n");
      exit(-1);
    }

    while ((read_num = read(cfd, buffer, BUF_SIZE)) > 0) {
      if (write(STDOUT_FILENO, buffer, read_num) != read_num) {
        printf("partial/failed read\n");
        exit(-1);
      }
    }

    if (read_num == -1) {
      printf("read\n");
      exit(-1);
    }

    if (close(cfd) == -1) {
      printf("close\n");
      exit(-1);
    }
  }
}