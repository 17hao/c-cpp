#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == -1) {
        exit(-1);
    }

    if (pid == 0) { // child process
        printf("I'm child process - pid: %d - parent pid: %d\n", getpid(), getppid());
        sleep(5);
        printf("After sleep pid: %d - parent pid: %d\n", getpid(), getppid());
        exit(0);
    } else {
        sleep(1);
        printf("I'm parent process - pid: %d - parent pid: %d\n", getpid(), getppid());
        exit(0);
    }
}