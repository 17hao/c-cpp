#include <stdio.h>
#include <sys/resource.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
  int which, prio;
  id_t who;

  if (argc != 4 || strchr("pgu", argv[1][0]) == NULL) {
    printf("%s {p|g|u} who priority\n"
           "set priority of: p=process; g=process group; u=process for user\n", argv[0]);
    exit(-1);
  }

  which = argv[1][0] == 'p' ? PRIO_PROCESS : (argv[1][0] == 'g' ? PRIO_PGRP : PRIO_USER);
  who = atol(argv[2]);
  prio = atoi(argv[3]);

  if (setpriority(which, who, prio) == -1) {
    printf("set priority");
    exit(-1);
  }

  errno = 0;
  prio = getpriority(which, who);
  if ((prio == -1) || errno != 0) {
    printf("get priority");
    exit(-1);
  }

  printf("Nice value = %d\n", prio);
  exit(EXIT_SUCCESS);
}