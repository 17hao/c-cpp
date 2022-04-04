#include "csapp.h"

/*
 Private global variables
*/
static char *mem_heap;     // Points to first byte of heap
static char *mem_brk;      // Points to last byte of heap plus 1
static char *mem_max_addr; // Max legal heap addr plus 1

/*
 Initialize the memory system model
*/
void mem_init() {
    mem_heap = (char *)malloc(MAXHEAP);
    mem_brk = mem_heap;
    mem_max_addr = (char *)(mem_heap + MAXHEAP);
}

/*
 Simple model of the sbrk function. Extend the heap by incr bytes
 and returns the start address of the new area. In this model, the
 heap cannot be shrunk.
*/
void *mem_sbrk(int incr) {
    char *old_brk = mem_brk;
    if (incr < 0 || ((mem_brk + incr) > mem_max_addr)) {
        errno = ENOMEM;
        perror("mem_sbrk");
        return (void *)-1;
    }
    mem_brk += incr;
    return (void *)old_brk;
}