#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]);

#define BUF_SIZE 4096
#define OUTPUT_MODE 0700

int main(int argc, char *argv[]) {
  int in_fd, out_fd, rd_count, wt_count;
  char buffer[BUF_SIZE];

  if (argc < 3) exit(1);

  in_fd = open(argv[1], O_RDONLY);
  if (in_fd < 0) exit(2);
  out_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, OUTPUT_MODE);
  if (out_fd < 0) exit(3);

  while (1) {
    rd_count = read(in_fd, buffer, BUF_SIZE);
    if (rd_count <= 0) break;
    wt_count = write(out_fd, buffer, rd_count);
    if (wt_count <= 0) exit(4);
  }

  close(in_fd);
  close(out_fd);
  if (rd_count == 0)
    exit(0);
  else
    exit(5);
}