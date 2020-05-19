#include <stdio.h>
#include <stdlib.h>

/* array subscript version */
void my_strcpy_1(char *s, char *t) {
  int i = 0;
  while ((s[i] = t[i]) != '\0')
    i++;
}

void my_strcpy_2(char *s, char *t) {
  while ((*s = *t) != '\0') {
    s++;
    t++;
  }
}

void my_strcpy_3(char *s, char *t) {
  while ((*s++ = *t++) != '\0');
}

void my_strcpy_4(char *s, char *t) {
  while (*s++ = *t++);
}

int main(int argc, char *argv[]) {
  char *s = malloc(100L);
  char *t = "hello, world";
//    my_strcpy_1(s, t);
//    my_strcpy_2(s, t);
//    my_strcpy_3(s, t);
  my_strcpy_4(s, t);
  printf("%s\n", s);
}