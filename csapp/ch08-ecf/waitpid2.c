#include "csapp.h"

#define N 2

int main() {
    pid_t pid[N];

    /* Parent creates N children */
    for (int i = 0; i < N; i++) {
        if ((pid[i] = Fork()) == 0) // child {
            exit(100 + i);
    }

    /* Parent reaps N children in order */
    int i = 0, status;
    pid_t retpid;
    while ((retpid = waitpid(pid[i++], &status, 0)) > 0) {
        if (WIFEXITED(status)) {
            printf("child %d terminated normally with exit status = %d\n", retpid, status);
        } else {
            printf("child %d terminated abnormaly\n", retpid);
        }
    }

    if (errno != ECHILD) {
        unixError("waitpid error");
    }
    exit(0);
}