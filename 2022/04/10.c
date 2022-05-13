#include <stdio.h>
#include <stdlib.h>

#define LEN 5

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode **reverse(struct ListNode **head);

int main() {
  int nums[LEN] = {0, 1, 2, 3, 4};
  struct ListNode *dummy = &(struct ListNode){};
  struct ListNode *cur = dummy;
  for (int i = 0; i < LEN; i++) {
    // struct ListNode node = {nums[i], NULL}; // 有问题的代码，需要看汇编
    // cur->next = &node;
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->val = nums[i];
    cur->next = node;
    cur = cur->next;
  }
  // struct ListNode *head = dummy->next;
  // while (head != NULL) {
  //     printf("%d ", head->val);
  //     head = head->next;
  // }
  struct ListNode **res = reverse(&dummy->next);
  while (*res != NULL) {
    printf("%d ", (*res)->val);
    *res = (*res)->next;
  }
}

void doReverse(struct ListNode **head, struct ListNode *dummy) {
  if (*head == NULL) {
    return;
  }
  struct ListNode **next = malloc(sizeof(struct ListNode));
  *next = (*head)->next;
  // **next = &(*head)->next; // 有问题的代码
  (*head)->next = dummy->next;
  dummy->next = *head;
  doReverse(next, dummy);
}

struct ListNode **reverse(struct ListNode **head) {
  struct ListNode *dummy = &(struct ListNode){};
  doReverse(head, dummy);
  return &(dummy->next);
}