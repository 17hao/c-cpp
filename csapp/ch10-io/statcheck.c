#include "csapp.h"

int main(int argc, char *argv[]) {
    struct stat s;

    stat(argv[1], &s);
    char *type;
    if (S_ISREG(s.st_mode)) {
        type = "regular";
    } else if (S_ISDIR(s.st_mode)) {
        type = "directory";
    } else {
        type = "other";
    }

    char *readok;
    if (s.st_mode & S_IRUSR) {
        readok = "yes";
    } else {
        readok = "no";
    }

    printf("type: %s, read: %s, size: %ldbytes\n", type, readok, s.st_size);
    exit(0);
}