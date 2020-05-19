#define _BSD_SOURCE /* get major() and minor() from <sys/types.h> */
#define _POSIX_C_SOURCE 1L

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../lib/tlpi_hdr.h"

static void display_file_state(const struct stat *sb) {
  printf("File type:                 ");
  switch (sb->st_mode & S_IFMT) {
    case S_IFREG:printf("regular file\n");
      break;
    case S_IFDIR:printf("directory\n");
      break;
    case S_IFBLK:printf("block device\n");
      break;
    case S_IFCHR:printf("character device\n");
      break;
    case S_IFSOCK:printf("socket\n");
      break;
    case S_IFLNK:printf("symbolic link\n");
      break;
    default:printf("unknown file type?\n");
      break;
  }

//    printf("Device contains i-node:    major=%ld minor=%ld\n",
//           (long) major(sb->st_dev), (long) minor(sb->st_dev));

  printf("I-node number:             %ld\n", (long) sb->st_ino);

//    printf("Mode:                      %lo (%s)\n",
//           (unsigned long) sb->st_mode, filePermStr(sb->st_mode, O));

  printf("Number of (hard) links:    %ld\n", (long) sb->st_nlink);

  printf("Ownership:                 UID=%ld GID=%ld\n", (long) sb->st_uid, (long) sb->st_gid);

  printf("File size:                 %lld bytes\n", (long long) sb->st_size);

  printf("Optional I/O block size:   %lld bytes\n", (long long) sb->st_blksize);

  printf("512 blocks allocated:      %lld\n", (long long) sb->st_blocks);

  printf("Last file access:          %s\n", ctime(&sb->st_atime));

  printf("Last file modified:        %s\n", ctime(&sb->st_mtime));

  printf("Last status change:        %s\n", ctime(&sb->st_ctime));
}

int main(int argc, char *argv[]) {
  struct stat sb;
  Boolean state_link;
  int fname;

  state_link = (argc > 1) && strcmp(argv[1], "-l") == 0;
  fname = state_link ? 2 : 1;

  if (state_link) {
    if (lstat(argv[fname], &sb) == -1)
      exit(-1);
  } else {
    if (stat(argv[fname], &sb) == -1)
      exit(-1);
  }

  display_file_state(&sb);

  exit(EXIT_SUCCESS);
}