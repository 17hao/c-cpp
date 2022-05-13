#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * Demonstrate of lseek() and file I/O system calls.
 */
int main(int argc, char *argv[]) {
  size_t len;
  off_t offset;
  unsigned char *buf;
  ssize_t read_num, write_num;
  char *endptr;

  if (argc < 3 || strcmp(argv[1], "--help") == 0) {
    printf("%s file {r<length>|R<length>|w<string>|s<offset>}...\n", argv[0]);
    exit(-1);
  }

  int fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
  printf("fd: %d\n", fd);
  if (fd == -1)
    exit(-2);

  for (int ap = 2; ap < argc; ap++) {
    switch (argv[ap][0]) {
    case 'r': /* Display bytes at current offset as text */
    case 'R': /* Display bytes at current offset in hex */
      len = strtol(&argv[ap][1], &endptr, 10);
      buf = malloc(len);
      if (buf == NULL)
        exit(-1);

      read_num = read(fd, buf, len);

      if (read_num == -1)
        exit(-1);

      if (read_num == 0) {
        printf("%s: end-of-file\n", argv[ap]);
      } else {
        printf("%s: ", argv[ap]);
        for (int j = 0; j < read_num; j++) {
          if (argv[ap][0] == 'r') {
            printf("%c", isprint(buf[j]) ? buf[j] : '?');
          } else {
            printf("%02x ", buf[j]);
          }
        }
      }

      free(buf);
      break;
    case 'w': /* Write string at current offset */
      write_num = write(fd, &argv[ap][1], strlen(&argv[ap][1]));
      if (write_num == -1)
        exit(-1);

      printf("%s wrote %ld bytes\n", argv[ap], (long)write_num);
      break;
    case 's': /* Change file offset */
      offset = strtol(&argv[ap][1], &endptr, 10);
      if (lseek(fd, offset, SEEK_SET) == -1)
        exit(-1);
      printf("%s: seek succeeded\n", argv[ap]);
      break;
    }
  }

  if (close(fd) == -1)
    exit(-3);

  exit(EXIT_SUCCESS);
}