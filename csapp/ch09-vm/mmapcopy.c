// Using mmap to copy an arbitray-size disk file to stdout.
// The name of the input file should be passed as a command-line argument.

#include "csapp.h"

void handleErr(char *msg) {
    do {
        perror(msg);
        exit(EXIT_FAILURE);
    } while (0);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "%s file name\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        handleErr("open");
    }
    struct stat sb;
    if (fstat(fd, &sb) == -1) {
        handleErr("fstat");
    }

    off_t offset = 0;
    off_t pa_offset = offset & ~(sysconf(_SC_PAGE_SIZE) - 1);
    size_t length = sb.st_size - offset;

    char *addr = mmap(NULL, length, PROT_READ, MAP_PRIVATE, fd, pa_offset);
    if (addr == MAP_FAILED) {
        handleErr("mmap");
    }

    ssize_t s = write(STDOUT_FILENO, addr + offset - pa_offset, length);
    // printf("")

    munmap(addr, length);
    close(fd);
    exit(EXIT_SUCCESS);
}