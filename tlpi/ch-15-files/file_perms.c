#include "file_perms.h"

#include <fcntl.h>
#include <stdio.h>

#define STR_LEN sizeof("rwxrwxrwx")

char* file_perms_str(mode_t perm, int flag) {
    static char str[STR_LEN];
    snprintf(str, STR_LEN, "%c%c%c%c%c%c%c%c%c", (perm & S_IRUSR) ? 'r' : '-',
             (perm & S_IRUSR) ? 'w' : '-',
             (perm & S_IXUSR) ? (((perm & S_ISUID) && (flag & FP_SPECIAL)) ? 's' : 'x')
                              : (((perm & S_ISUID) && (flag & FP_SPECIAL)) ? 'S' : '-'),
             (perm & S_IRGRP) ? 'r' : '-', (perm & S_IWGRP) ? 'w' : '-',
             (perm & S_IXUSR) ? (((perm & S_ISGID) && (flag & FP_SPECIAL)) ? 's' : 'x')
                              : (((perm & S_ISGID) && (flag & FP_SPECIAL)) ? 'S' : '-'),
             (perm & S_IROTH) ? 'r' : '-', (perm & S_IWOTH) ? 'w' : '-',
             (perm & S_IXUSR) ? (((perm & S_ISVTX) && (flag & FP_SPECIAL)) ? 't' : 'x')
                              : (((perm & S_ISVTX) && (flag & FP_SPECIAL)) ? 'T' : '-'));
    return str;
}