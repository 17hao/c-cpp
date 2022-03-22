#include "csapp.h"
#define N 2

int main() {
    pid_t pid;
    // parent creates N children
    for (int i = 0; i < N; i++) {
        if ((pid = Fork()) == 0) {
            exit(100 + i);
        }
    }

    // parent reaps children processes in no particular order
    int status;
    while ((pid = waitpid(-1, &status, 0)) > 0) {
        if (WIFEXITED(status)) {
            printf("child %d terminated normally with exit status=%d\n", pid, WEXITSTATUS(status));
        } else {
            printf("child %d terminated abnormally\n", pid);
        }
    }

    // the only normal termination is if there is no more children
    if (errno != ECHILD) {
        unixError("waitpid error");
    }
    exit(0);
}