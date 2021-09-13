#include <ctype.h>
#include <stdio.h>
#include <string.h>

/**
 * 结构数组, 类似于int [10]
 */
struct key {
    char *word;
    int count;
} keytab[] = {"auto",    0, "break",    0, "case", 0, "char",     0, "const", 0, "continue", 0,
              "default", 0, "unsigned", 0, "void", 0, "volatile", 0, "while", 0};

int binsearch(char *, struct key *, int);

int main() {
}

int binsearch(char *word, struct key tab[], int n) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
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

struct key *binarySearch(char *word, struct key *tab, int n) {
    struct key *low = &tab[0], *high = &tab[n - 1];
    while (low < high) {
        struct key *mid = low + (high - low) / 2;
        int cond = strcmp(word, mid->word);
        if (cond > 0) {
            low = mid + 1;
        } else if (cond < 0) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return NULL;
}