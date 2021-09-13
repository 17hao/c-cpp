#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void *thread_func(void *arg) {
    char* s = (char *)arg;
    printf("%s", s);

    return (void *)strlen(s);
}

int main() {
    pthread_t t1;
    void* res;
    int s;

    s = pthread_create(&t1, NULL, prod_thread, "hello, world\n");
    if (s == -1) {
        printf("pthread_create\n");
        exit(-1);
    }

    printf("Message from main()\n");
    s = pthread_join(t1, &res);
    if (s != 0) {
        printf("pthread_join\n");
        exit(-1);
    }
    printf("Thread returned %ld\n", (long)res);
    //  printf("Thread returned %ld\n", (long) &res);

    exit(EXIT_SUCCESS);
}