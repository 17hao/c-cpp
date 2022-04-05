#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAXHEAP 1024

extern char **environ; /* Defined by libc */

void unixError(char *msg);

pid_t Fork();

//+------------------+
//| P.897 chapter 10 |
//+------------------+

#define MAXLINE 8192
#define RIO_BUFSIZE 8192
typedef struct {
    int rio_fd;                // Descriptor for this internal buffer
    int rio_cnt;               // Unread bytes in internal buf
    char *rio_bufptr;          // Next unread byte in internal buffer
    char rio_buf[RIO_BUFSIZE]; // Internal buffer
} rio_t;

//====== unbuffered input and output ======

/**
 * transfer n bytes from the current file position of descriptor fd
 * to memory location usrbuf
 */
ssize_t rio_readn(int fd, void *usrbuf, size_t n);
/**
 * transfer n bytes from location usrbuf to file descriptor fd
 */
ssize_t rio_writen(int fd, void *usrbuf, size_t n);

//====== buffered input and output ======

void rio_readinitb(rio_t *rp, int fd);

/**
 * read the next text line from file rp, copies it to memory location usrbuf,
 * and terminates the text line with NULL character
 */
ssize_t rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen);
ssize_t rio_readnb(rio_t *rp, void *usrbuf, size_t n);