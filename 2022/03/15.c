#include <stdio.h>
#include <string.h>
#include <unistd.h>

void execDemo();

int main() {
    // char *str = "ls -al";
    // char *delim = strchr(str, ' ');
    // *delim = '\0';
    // printf("str = %s\n", str);
    execDemo();
}

void execDemo() {
    char *argv[] = {"/bin/ls", NULL};
    // char *environ[] = {
    //     "PATH=/usr/local/sbin/:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games", NULL};
    char **environ;
    if (execv(argv[0], argv) < 0) {
        printf("execve error\n");
    }
}