#include "csapp.h"

void unixError(char *msg) {
    fprintf(stderr, "%s %s\n", msg, strerror(errno));
    exit(0);
}

pid_t Fork() {
    pid_t pid;

    if ((pid = fork()) < 0) {
        unixError("fork error");
    }
    return pid;
}