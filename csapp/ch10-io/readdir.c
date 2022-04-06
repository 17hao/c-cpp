#include "csapp.h"

int main(int argc, char *argv[]) {
    DIR *dir = opendir(argv[1]);

    struct dirent *dep;
    while ((dep = readdir(dir)) != NULL) {
        printf("%s\n", dep->d_name);
    }
    closedir(dir);
    exit(0);
}