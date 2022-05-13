#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main() {
  int fd = open("./copyfile.c", O_RDONLY);
  printf("file description: %d\n", fd);

  char buffer[BUFFER_SIZE];
  int count = 0;
  while (1) {
    count = read(fd, buffer, BUFFER_SIZE);
    printf("read %d bytes.\n", count);
    if (count <= 0)
      break;
  }
}