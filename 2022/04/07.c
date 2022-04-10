#include <stdio.h>
#include <stdlib.h>

#define LINE_SIZE 4

/**
 * stdin, stdout are all buffered
 * nothing will output until either:
 *   1. the output buffer is overflow
 *   2. a newline sequence '\n' is output
 *   3. fflush is called for the specific stream
 *   4. the program exits
 */
void readFromStdinV1() {
    char *line = malloc(LINE_SIZE * sizeof(char));
    while (1) {
        fread(line, sizeof(char), LINE_SIZE, stdin);

        fflush(stdout);
        fwrite(line, sizeof(char), LINE_SIZE, stdout);

        printf("%s\n", line);
        // exit(0);
    }
}

/**
 * 1. fgets reads a line, it will stop at a newline.
 * 2. fread reads raw data, it will stop after a specified number of bytes, independetly of
 *    any newline that might or might not present.
 */
void readFromStdinV2() {
    char *buf = malloc(LINE_SIZE * sizeof(char));
    while (1) {
        fgets(buf, LINE_SIZE, stdin);
        printf("%s\n", buf);
    }
}

int main() {
    // readFromStdinV1();
    readFromStdinV2();
}