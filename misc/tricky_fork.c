#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

/* https://coolshell.cn/articles/7965.html  */

int main() {
  for (int i = 0; i < 2; i++) {
    fork();
    //printf("-");
    printf("-\n");
  }

  wait(NULL);
  wait(NULL);

  exit(EXIT_SUCCESS);
}
