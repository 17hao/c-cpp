#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef enum { TRUE, FALSE } Boolean;

char *cur_time(const char *format) {
  char buf[100];
  time_t t;
  time(&t);
  struct tm *tm;
  tm = localtime(&t);
  strftime(buf, 100, format, tm);
  return buf;
}