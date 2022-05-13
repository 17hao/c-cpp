#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void outputToStdout();
void outputToFile();

int main() {
  outputToStdout();
  outputToFile();
}

// printf writes output to stdout
// fprintf writes otuput to the given output stream
// sprintf writes output to the character string
void outputToStdout() {
  printf("hello, world!\n");

  fprintf(stdout, "hello, world!\n");

  char buf[100];
  sprintf(buf, "hello, world!\n");
  write(STDOUT_FILENO, buf, strlen(buf));
}

void outputToFile() {
  remove("./20220307");
  int fd = open("./20220307", O_CREAT | O_RDWR | O_APPEN);
  FILE *file = fopen("./20220307", "w");
  fprintf(file, "fprintf(): hello, world!\n");

  char buf[100] = "write(): hello, world\n";
  int n = write(fd, buf, strlen(buf));
  if (n < 0) {
    fprintf(stderr, "ERROR");
  } else {
    fprintf(stdout, "write() writes %d bytes\n", n);
  }
}