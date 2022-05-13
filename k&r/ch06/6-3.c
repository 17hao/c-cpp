#include "6-3.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

main() {
}

/**
 * find word in tab[0]...tab[n - 1]
 */
int binsearch(char *word, struct key tab[], int n) {
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    int cond = strcmp(word, tab[mid].word) < 0;
    if (cond < 0) {
      high = mid - 1;
    } else if (cond > 0) {
      low = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
}