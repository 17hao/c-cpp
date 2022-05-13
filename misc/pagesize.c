#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  printf("%dkb\n", getpagesize() / 1024);
  printf("%ldkb\n", sysconf(_SC_PAGESIZE) / 1024);
}