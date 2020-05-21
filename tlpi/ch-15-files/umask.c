#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "file_perms.h"
#include "../lib/tlpi_hdr.h"

#define MYFILE "myfile"
#define MYDIR "mydir"
#define FILE_PERM (S_IRUSR | S_IWUSR | S_IRGRP  | S_IWGRP)
#define DIR_PERM (S_IRWXU | S_IRWXG | S_IRWXO)
#define  UMASK_SETTING (S_IWGRP | S_IXGRP | S_IWOTH | S_IXOTH)

int main(int argc, char *argv[]) {
  int fd;
  struct stat sb;
  mode_t u;

  umask(UMASK_SETTING);

  fd = open(MYFILE, O_RDWR | O_CREAT | O_EXCL, FILE_PERM);
  if (fd == -1)
    exit(-1);
  if (mkdir(MYDIR, DIR_PERM) == -1)
    exit(-1);

  u = umask(0);

  if (stat(MYFILE, &sb) == -1)
    exit(-1);
  printf("Requested file perms: %s\n", file_perm_str(FILE_PERM, 0));
  printf("Process perms:        %s\n", file_perm_str(u, 0));
  printf("Actual file perms:    %s\n", file_perm_str(sb.st_mode, 0));

  if (stat(MYDIR, &sb) == -1)
    exit(-1);
  printf("Requested dir perms:  %s\n", file_perm_str(DIR_PERM, 0));
  printf("Process perms:        %s\n", file_perm_str(u, 0));
  printf("Actual dir perms:     %s\n", file_perm_str(sb.st_mode, 0));

  exit(EXIT_SUCCESS);
}