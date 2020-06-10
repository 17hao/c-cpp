#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../lib/tlpi_hdr.h"

/**
 * cat file
 */
int main(int argc, char *argv[]) {
  char *addr;
  int fd;
  struct stat sb;

  if (argc < 2 || strcmp(argv[1], "--help") == 0) {
    printf("%s file\n", argv[0]);
    exit(-1);
  }

  fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    printf("open");
    exit(-1);
  }

  if (fstat(fd, &sb) == -1) {
    printf("fstat");
    exit(-1);
  }

  addr = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
  if (addr == MAP_FAILED) {
    printf("mmap");
    exit(-1);
  }

  if ((write(STDOUT_FILENO, addr, sb.st_size)) != sb.st_size) {
    printf("write");
    exit(-1);
  }

  exit(EXIT_SUCCESS);
}