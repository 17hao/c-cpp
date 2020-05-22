#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include "file_perms.h"
#include "../lib/tlpi_hdr.h"

#define FILE_PERM (S_IRUSR | S_IWUSR | S_IRGRP  | S_IWGRP)
#define DIR_PERM (S_IRWXU | S_IRWXG | S_IRWXO)
#define  UMASK_SETTING (S_IWGRP | S_IXGRP | S_IWOTH | S_IXOTH)

/**
 * gcc umask.c file_perms.c
 */
int main(int argc, char *argv[]) {
  int fd;
  struct stat sb;
  mode_t u;

  if (strcmp(argv[1], "-d") != 0 && (argc < 2 || argc > 3 || strcmp(argv[1], "--help") == 0 ||
      strcmp(argv[1], "-h") == 0 || argv[1][0] == '-')) {
    printf("usage: umask [-d] [file | directory]\n");
    exit(-1);
  }

  umask(UMASK_SETTING);

  char *file, *dir;

  if (argc == 2) {
    file = argv[1];
    fd = open(file, O_RDWR | O_CREAT | O_EXCL, FILE_PERM);
    if (fd == -1)
      exit(-1);
    u = umask(0);
    if (stat(file, &sb) == -1)
      exit(-1);
    printf("Requested file perms: %s\n", file_perms_str(FILE_PERM, 0));
    printf("Process perms:        %s\n", file_perms_str(u, 0));
    printf("Actual file perms:    %s\n", file_perms_str(sb.st_mode, 0));

    exit(EXIT_SUCCESS);
  }

  if (argc == 3 && strcmp(argv[1], "-d") == 0) {
    dir = argv[2];
    if (mkdir(dir, DIR_PERM) == -1)
      exit(-1);
    u = umask(0);
    if (stat(dir, &sb) == -1)
      exit(-1);
    printf("Requested dir perms:  %s\n", file_perms_str(DIR_PERM, 0));
    printf("Process perms:        %s\n", file_perms_str(u, 0));
    printf("Actual dir perms:     %s\n", file_perms_str(sb.st_mode, 0));

    exit(EXIT_SUCCESS);
  }
}