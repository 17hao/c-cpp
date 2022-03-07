//  gcc -DCOMPILETIME -c mymalloc.c
#ifdef COMPILETIME
#include <stdio.h>
#include <malloc.h>

/* malloc wrapper function */
void *mymalloc(size_t size) {
    void *ptr = malloc(size);
    printf("malloc(%d)=%p\n", (int)size, ptr);
    return ptr;
}

/* free wrapper function */
void myfree(void *ptr) {
    free(ptr);
    printf("free(%p)\n", ptr);
}
#endif

// gcc -DLINKTIME -c mymyalloc.c
#ifdef LINKTIME
#include <stdio.h>

void *__real_malloc(size_t size);
void __real_free(void *ptr);

/* malloc wrapper function */
void *__wrap_malloc(size_t size) {
    void *ptr = __real_malloc(size); // call libc malloc
    printf("malloc(%d)=%p\n", (int)size, ptr);
    return ptr;
}

/* free wrapper function */
void __wrap_free(void *ptr) {
    __real_free(ptr); // call libc free
    printf("free(%p)\n", ptr);
}
#endif

// gcc -DRUNTIME -shared -fpic -o mymalloc.so mymalloc.c -ldl
#ifdef RUNTIME
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <unistd.h>
#include <string.h>

void *malloc(size_t size) {
    void *(*mallocp)(size_t size);
    char *error;

    mallocp = dlsym(RTLD_NEXT, "malloc"); // get address of libc malloc
    if ((error = dlerror()) != NULL) {
        fputs(error, stderr);
        exit(1);
    }
    char *ptr = mallocp(size); // call libc malloc
    char buf[100];
    // printf("malloc(%d) = %p\n", (int)size, ptr); // Segmentation fault
    sprintf(buf, "malloc(%d) = %p\n", (int)size, ptr);
    write(STDOUT_FILENO, buf, strlen(buf));
    return ptr;
}

void free(void *ptr) {
    void (*freep)(void *) = NULL;
    char *error;

    if (!ptr) {
        return;
    }

    freep = dlsym(RTLD_NEXT, "free"); // get address of libc free
    if ((error = dlerror()) != NULL) {
        fputs(error, stderr);
        exit(1);
    }
    freep(ptr);
    char buf[100];
    sprintf(buf, "free(%p)\n", ptr);
    write(STDOUT_FILENO, buf, strlen(buf));
}
#endif