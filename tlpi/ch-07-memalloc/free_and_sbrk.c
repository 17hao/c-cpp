/**
 * Only works in linux.
 *
 * ./free_and_sbrk 1000 1024
 * ./free_and_sbrk 1000 1024 2
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ALLOCS 1000000

int main(int argc, char* argv[]) {
    char* ptr[MAX_ALLOCS];
    int num_allocs, block_size, free_step, free_min, free_max;

    if (argc < 3 || strcmp(argv[1], "--help") == 0) {
        printf("%s num-allocs block-size [step [min [max]]]\n", argv[0]);
        exit(-1);
    }

    num_allocs = atoi(argv[1]);
    block_size = atoi(argv[2]);

    if (num_allocs > MAX_ALLOCS) {
        printf("num-allocs > %d\n", MAX_ALLOCS);
    }

    free_step = argc > 3 ? atoi(argv[3]) : 1;
    free_min = argc > 4 ? atoi(argv[4]) : 1;
    free_max = argc > 5 ? atoi(argv[5]) : num_allocs;

    if (free_max > num_allocs) {
        printf("free-max > num-allocs\n");
        exit(-1);
    }

    printf("Initial program break:               %10p\n", sbrk(0));
    printf("Allocating %d * %d bytes\n", num_allocs, block_size);

    int i;
    for (i = 0; i < num_allocs; i++) {
        ptr[i] = malloc(block_size);
        if (ptr[i] == NULL) {
            printf("malloc");
            exit(-1);
        }
    }

    printf("Program break is now:                %10p\n", sbrk(0));

    printf("Freeing blocks from %d to %d in step %d\n", free_min, free_max, free_step);

    for (i = free_min - 1; i < free_max; i += free_step) {
        free(ptr[i]);
    }

    printf("After free(), program break is now:  %10p\n", sbrk(0));

    exit(EXIT_SUCCESS);
}