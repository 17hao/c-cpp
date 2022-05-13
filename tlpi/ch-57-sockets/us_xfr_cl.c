#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SV_SOCK_PATH "/tmp/us_xfr"

#define BUF_SIZE 100

int main() {
  struct sockaddr_un addr;
  int sfd;
  ssize_t read_num;
  char buffer[BUF_SIZE];

  if ((sfd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1)
    exit(-1);

  memset(&addr, 0, sizeof(struct sockaddr_un) - 1);
  addr.sun_family = AF_UNIX;
  strncpy(addr.sun_path, SV_SOCK_PATH, sizeof(addr.sun_path) - 1);

  if (connect(sfd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un) - 1) == -1) {
    printf("connect\n");
    exit(-1);
  }

  while ((read_num = read(STDIN_FILENO, buffer, BUF_SIZE)) > 0) {
    if (write(sfd, buffer, read_num) != read_num) {
      exit(-1);
    }
  }

  if (read_num == -1)
    exit(-1);

  exit(EXIT_SUCCESS);
}