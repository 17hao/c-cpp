#include <pthread.h>
#include "../lib/tlpi_hdr.h"

static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

static int avail;

static void *prod_thread(void *arg) {
  int cnt = atoi((char *) arg);
  int s;
  for (int i = 0; i < cnt; i++) {
    sleep(1);
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

    s = pthread_cond_signal(&cond);
    if (s != 0) {
      printf("pthread_cond_signal");
      exit(-1);
    }
  }

  return NULL;
}

int main(int argc, char *argv[]) {
  pthread_t tid;
  int s;
  Boolean done = FALSE;
  int total_required = 0, num_consumed = 0;
  time_t t = time(NULL);

  for (int i = 1; i < argc; i++) {
    total_required += atoi(argv[i]);
    s = pthread_create(&tid, NULL, prod_thread, argv[i]);
    if (s != 0) {
      printf("pthread_create");
      exit(-1);
    }
  }

  for (;;) {
    s = pthread_mutex_lock(&mtx);
    if (s != 0) {
      printf("pthread_mutex");
      exit(-1);
    }

    while (avail == 0) {
      pthread_cond_wait(&cond, &mtx);
    }

    while (avail > 0) {
      num_consumed++;
      avail--;
      printf("[tid=%d] T=%ld: num_consumed=%d\n", (int) pthread_self(), (long) (time(NULL) - t), num_consumed);
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