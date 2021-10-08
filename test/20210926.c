#include <stdio.h>
#include <string.h>

char* process(const char* input) {
    int len = strlen(input);
    char buf[len * 2];
    int index = 0;
    for (int i = 0; i < len; i++) {
        char c = input[i];
        if (c == '*') {
            buf[index++] = '\\';
            buf[index++] = c;
        } else {
            buf[index++] = c;
        }
    }
    return buf;
}

int main(int argc, char const* argv[]) {
    // const char* input = argv[1];
    // char* res = process(input);
    // printf("%s\n", res);
    while (1) {
        int c = getchar();
        const char hex[] = "0123456789ABCDEF";
        printf("%c", hex[(unsigned char)c >> 4]);
        printf("%c", hex[(unsigned char)c & 15]);
    }
}
