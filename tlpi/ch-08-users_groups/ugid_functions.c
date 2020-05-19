#include <stdio.h>
#include <pwd.h>
#include <grp.h>

/**
 * Convert user id to uer name.
 */
char *username_from_id(uid_t uid) {
  struct passwd *pwd;

  pwd = getpwuid(uid);
  return pwd == NULL ? NULL : pwd->pw_name;
}

int main() {
  printf("%s\n", username_from_id(0));
}