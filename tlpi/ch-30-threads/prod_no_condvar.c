#include <pthread.h>
#include "../lib/tlpi_hdr.h"

static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

static int avail;

static void *prod_thread(void *arg) {
  int cnt = atoi((char *) arg);
  int s, j;

  for (j = 0; j < cnt; j++) {
    sleep(1); // suspend producer thread 1s
    s = pthread_mutex_lock(&mtx);
    if (s != 0) {
      printf("pthread_mutex_lock");
      exit(-1);
    }

    avail++;

    s = pthread_mutex_unlock(&mtx);
    if (s != 0) {
      printf("pthread_mutex_unlock");
      exit(-1);
    }
  }
  printf("avail=%d\n", avail);

  return NULL;
}

int main(int argc, char *argv[]) {
  pthread_t tid;
  int s;
  int total_required = 0;

  int num_consumed = 0;
  Boolean done = FALSE;
  time_t t;

  t = time(NULL);

  for (int i = 1; i < argc; i++) {
    total_required += atoi(argv[i]);
    s = pthread_create(&tid, NULL, prod_thread, argv[i]);
    if (s != 0) {
      printf("pthread_create");
      exit(-1);
    }
  }

  sleep(1);

  printf("avail=%d\n", avail);
  for (;;) {
    s = pthread_mutex_lock(&mtx);
    if (s != 0) {
      printf("pthread_mutex_lock");
      exit(-1);
    }

    while (avail > 0) {
      num_consumed++;
      avail--;
      printf("[tid=%d]T=%ld: num_consumed=%d\n", (int) pthread_self(), (long) (time(NULL) - t), num_consumed);
      done = num_consumed >= total_required;
    }

    s = pthread_mutex_unlock(&mtx);
    if (s != 0) {
      printf("pthread_mutex_unlock");
      exit(-1);
    }

    if (done)
      break;
  }
  exit(EXIT_SUCCESS);
}