/*
  what is the output of the child process?
  what is the ouput of the parent process?
*/
#include "csapp.h"

int main() {
    int a = 9;

    if (Fork() == 0) {
        printf("pid=%d p1: a=%d\n", getpid(), a--);
    }

    printf("pid=%d p2: a=%d\n", getpid(), a++);
    exit(0);
}