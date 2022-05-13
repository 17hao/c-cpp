#include <stdio.h>
#include <time.h>

int main() {
  time_t t;
  struct tm *gm;
  t = time(NULL);
  gm = gmtime(&t);

  printf("Seconds from Epoch (1970 Jan 1 00:00): %ld\n", (long)t);

  printf("ctime() formats time value as: %s", ctime(&t));

  printf("asctime() formats time value as: %s", asctime(gm));
}