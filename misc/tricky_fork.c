/**
 * https://coolshell.cn/articles/7965.html
 *
 * 当前进程执行完fork()后，共计2个进程。
 * 每个进程从fork()的下一行开始执行
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    for (int i = 0; i < 2; i++) {
        fork();
        // printf("- ");
        // printf("-\n");
        // fflush(stdout);
        printf("ppid=%d, pid=%d, i=%d -\n", getppid(), getpid(), i);
        // fflush(stdout);
    }

    // sleep(10); // sleep a while, use pstree|grep tricky to show ps tree

    wait(NULL);
    wait(NULL);

    exit(EXIT_SUCCESS);
}
