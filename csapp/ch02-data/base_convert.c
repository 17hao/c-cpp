/**
 * Giving a number, return binary, decimal, hexadecimal values.
 *
 * usage: ./a.out [-b|-d|-x] unsigned num
 *
 * binary: 0b11
 * decimal: 3
 * hexadecimal: 0x3
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binaryToDecimal(char *num, int len) {
  int res = 0;
  for (int i = len - 1; i >= 0; i--) {
    res += pow(2, len - 1 - i) * (num[i] - '0');
  }
  printf("decimal: %d\n", res);
}

void decimalToBinary(char *num, int len) {
  char *res = malloc(30 * sizeof(char));
  int n = atoi(num);
  int idx = 0;
  while (n > 1) {
    res[idx++] = (n % 2) + '0';
    n /= 2;
  }
  res[idx] = 1 + '0';
  for (int i = idx; i >= 0; i--) {
    printf("%c", res[i]);
  }
  printf("\n");
}

void binaryToHex(char *num, int len) {
  int size = len % 4 == 0 ? len / 4 : len / 4 + 1;
  char *res = malloc((size + 1) * sizeof(char));
  res[size] = '\0';
  int i = len - 1;
  for (; i >= 0; i -= 4) {
    int sum = 0;
    for (int j = i; j >= i - 3 && j >= 0; j--) {
      sum += pow(2, i - j) * (num[j] - '0');
    }
    if (sum < 10) {
      res[--size] = sum + '0';
    } else {
      res[--size] = sum - 10 + 'A';
    }
  }
  printf("hexadecimal: %s\n", res);
}

void hexToBinary(char *num, int len) {
  printf("binary: ");
  for (int i = 0; i < len; i++) {
    int n;
    if (num[i] >= '0' && num[i] <= '9') {
      n = num[i] - '0';
    } else {
      n = num[i] - 'A' + 10;
    }
    if (n == 0) {
      printf("%s", "0000");
      continue;
    }
    char *buf = malloc(4 * sizeof(char));
    int idx = 0;
    while (n > 1) {
      buf[idx++] = n % 2;
      n /= 2;
    }
    buf[idx] = n;
    for (int i = idx; i >= 0; i--) {
      printf("%d", buf[i]);
    }
  }
  printf("\n");
}

void decimalToHex(char *num, int len) {
  char *res = malloc(30 * sizeof(char));
  int n = atoi(num);
  int idx = 0;
  while (n > 15) {
    int r = n % 16;
    res[idx++] = r > 10 ? r - 10 + 'A' : r + '0';
    n /= 16;
  }
  res[idx] = n > 10 ? n - 10 + 'A' : n + '0';
  for (int i = idx; i >= 0; i--) {
    printf("%c", res[i]);
  }
  printf("\n");
}

void hexToDecimal(char *num, int len) {
  int res = 0;
  for (int i = len - 1; i >= 0; i--) {
    int n;
    if (num[i] >= '0' && num[i] <= '9') {
      n = num[i] - '0';
    } else {
      n = num[i] - 'A' + 10;
    }
    res += pow(16, len - i - 1) * n;
  }
  printf("decimal: %d\n", res);
}

void baseConvert(char *num, char *option) {
  int len = strlen(num);
  switch (option[1]) {
  case 'b':
    binaryToDecimal(num, len);
    binaryToHex(num, len);
    break;
  case 'd':
    decimalToBinary(num, len);
    decimalToHex(num, len);
    break;
  case 'x':
    hexToBinary(num, len);
    hexToDecimal(num, len);
    break;
  }
}

int main(int argc, char *argv[]) {
  // char *line = NULL;
  // size_t liencap = 0;
  // int linelen;
  // linelen = getline(&line, &liencap, stdin);
  // printf("len: %d, line: %s\n", linelen, line);
  if (argc < 2) {
    printf("usage: ./a.out [-b|-d|-x] unsigned num\n");
    exit(EXIT_FAILURE);
  }
  baseConvert(argv[2], argv[1]);
  return 0;
}
