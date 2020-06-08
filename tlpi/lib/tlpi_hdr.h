#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

typedef enum {
  TRUE,
  FALSE
} Boolean;

char *cur_time(const char *format) {
  char buf[100];
  time_t t;
  time(&t);
  struct tm *tm;
  tm = localtime(&t);
  strftime(buf, 100, format, tm);
  return buf;
}