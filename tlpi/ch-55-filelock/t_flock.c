#include <sys/file.h>
#include <fcntl.h>
#include <errno.h>

#include "../lib/tlpi_hdr.h"

int main(int argc, char *argv[]) {
  if (argc < 3 || strcmp(argv[1], "--help") == 0) {
    printf("%s file lock sleep-time\n", argv[0]);
    exit(-1);
  }

  int fd, lock;
  const char *lname;

  lock = argv[2][0] == 's' ? LOCK_SH : LOCK_EX;

  fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    printf("open\n");
    exit(-1);
  }

  lname = (lock & LOCK_SH) ? "LOCK_SH" : "LOCK_EX";

  printf("PID: %d requesting %s at %s\n", getpid(), lname, cur_time("%T"));

  if (flock(fd, lock) == -1) {
    if (errno == EWOULDBLOCK) {
      printf("PID %d: already locked, bye!\n", getpid());
      exit(-1);
    }
    printf("flock");
    exit(-1);
  }

  printf("PID: %d granted %s at %s\n", getpid(), lname, cur_time("%T"));

  sleep(atoi(argv[3]));

  printf("PID %d releasing %s at %s\n", getpid(), lname, cur_time("%T"));

  if (flock(fd, LOCK_UN) == -1) {
    printf("flock");
    exit(-1);
  }

  exit(EXIT_SUCCESS);
}