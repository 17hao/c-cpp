#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

char* get_cur_time(const char *format) {
    char buf[100];
    time_t t;
    struct tm *tm;
    t = time(NULL);
    tm = localtime(&t);
    strftime(buf, 100, format, tm);
    return buf;
}

int main(int argc, char *argv[]) {
    int dead_num = 0;
    pid_t child_pid;

    if (argc < 2 || strcmp(argv[1], "--help") == 0) {
        printf("%s sleep-time...\n", argv[0]);
        exit(-1);
    }

    setbuf(stdout, NULL);

    for (int i = 1; i < argc; i++) {
        switch (fork()) {
            case -1:
                printf("fork() failed");
                exit(-1);
            case 0:
                printf("[%s] child %d start with PID %ld, PPID %ld, sleeping %s\n",
                       get_cur_time("%T"), i, (long)getpid(), (long)getppid(), argv[i]);
                sleep(atoi(argv[i]));
                _exit(EXIT_SUCCESS);
            default:
                break;
        }
    }

    for (;;) {
        child_pid = wait(NULL);
        if (child_pid == -1) {
            if (errno == ECHILD) {
                printf("No more children -bye!\n");
                exit(EXIT_SUCCESS);
            } else {
                printf("wait");
                exit(-1);
            }
        }

        dead_num++;
        printf("[%s] wait() return child PID %ld (dead_num=%d)\n", get_cur_time("%T"),
               (long)child_pid, dead_num);
    }
}