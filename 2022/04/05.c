#include <stdio.h>
#include <string.h>

#define LEN 1024

int main() {
    // char *dest = malloc(sizeof(char) * LEN);
    char dest[LEN];
    // char *src = "hello, world!";
    char src[5] = {'h', 'e', 'l', 'l', 'o'};
    char *srcp = src;
    printf("src = %s\n", srcp);
    printf("len(src) = %ld\n", strlen(srcp));
    memcpy(dest, srcp, strlen(srcp));
    printf("%s\n", dest);
}