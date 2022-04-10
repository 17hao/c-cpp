#include <stdio.h>
#include <string.h>
#include <unistd.h>

void readDemo() {
    FILE *f = fopen("./foobar.txt", "r");
    char c;
    fread(&c, sizeof(char), 1, f);
    printf("buffer = %c\n", c);
    long fp = ftell(f);
    printf("file position = %ld\n", fp);
}

// 写入nmemb * size字节数
void writeDemo() {
    FILE *f = fopen("./foobar.txt", "r+");
    fseek(f, 0, SEEK_END);
    char *buf = "\n2022-4-6 23:47\n";
    int n = fwrite(buf, sizeof(char), strlen(buf), f);
    printf("write %d bytes\n", n);
    fclose(f);
}

int main(int argc, char *argv[]) {
    // readDemo();
    writeDemo();
}