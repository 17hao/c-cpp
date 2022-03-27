#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    errno = EPERM;
    perror("error");
    exit(EXIT_FAILURE);
}