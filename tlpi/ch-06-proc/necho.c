#include <stdio.h>

/**
 * A simple version of echo(1).
 */
int main(int argc, char* argv[]) {
    char** p;

    for (p = argv; *p != NULL; p++) {
        printf("%s ", *p);
    }
}