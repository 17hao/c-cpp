#include <stdio.h>

int main() {
  int x = 1, y = 2, z[10];
  int *ip;  // 指向int类型的指针

  ip = &x;  // &x将x的地址赋值给ip, 未带*表示ip是一个地址(一个变量),
            // 带了*表示所指向地址的值
  printf("pointer ip points to %d\n", x);

  y = *ip;  // 将指针ip所指地址的值赋给y
  *ip = 0;
  printf("x, y = %d, %d\n", *ip, y);

  ip = &z[0];
  printf("ip is: %d\n", *ip);

  printf("size of ip: %lu\n", sizeof(ip));
}