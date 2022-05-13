#include <stdio.h>

void swap(int nums[], int i, int j) {
  int tmp = nums[i];
  nums[i] = nums[j];
  nums[j] = tmp;
}

struct Employee {
  int id;
  char *name;
};

// void fun(struct Employee e) {
//     e.id = 0;
// }

void fun(struct Employee *e) {
  e->id = 0;
}

int main(int argc, char const *argv[]) {
  // int nums[3] = {1, 2, 3};
  // for (int i = 0; i < 3; i++) {
  //     printf("%d ", nums[i]);
  // }
  // printf("\n");
  // swap(nums, 0, 2);
  // for (int i = 0; i < 3; i++) {
  //     printf("%d ", nums[i]);
  // }

  struct Employee e = {1, "test"};
  // fun(e);
  fun(&e);
  printf("%d\n", e.id);
}
