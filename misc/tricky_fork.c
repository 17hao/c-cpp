/* https://coolshell.cn/articles/7965.html  */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    for (int i = 0; i < 2; i++) {
        fork();
        // printf("-");
        printf("-\n");
    }

    wait(NULL);
    wait(NULL);

    exit(EXIT_SUCCESS);
}
