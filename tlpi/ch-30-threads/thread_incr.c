#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

static int glob = 0;

static void *thread_func(void *arg) {
  int loc, j;
  int loops = * ((int *) arg);
  for (j = 0; j < loops; j++) {
    loc = glob;
    loc++;
    glob = loc;
  }
  glob = loc;

  return NULL;
}

int main(int argc, char *argv[]) {
  pthread_t t1, t2;

  int loops = argc > 1 ? atoi(argv[1]) : 10000;
  int s;

  s = pthread_create(&t1, NULL, thread_func, &loops);
  if (s != 0) {
    printf("pthread_create()");
    exit(-1);
  }
  s = pthread_create(&t2, NULL, thread_func, &loops);
  if (s != 0) {
    printf("pthread_create()");
    exit(-1);
  }

  s = pthread_join(t1, NULL);
  if (s != 0) {
    printf("pthread_join");
    exit(-1);
  }
  s = pthread_join(t2, NULL);
  if (s != 0) {
    printf("pthread_join");
    exit(-1);
  }

  printf("glob = %d\n", glob);
  exit(EXIT_SUCCESS);
}