/*
 * Add 2 numbers
 *
 * @since 2021-7-13 Tuesday 16:40
 */

#include "ListNode.h"
#include <stdio.h>
#include <stdlib.h>

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
  struct ListNode *n1 = l1;
  struct ListNode *n2 = l2;
  struct ListNode *dummy = malloc(sizeof(struct ListNode));
  struct ListNode *cur = dummy;
  dummy->next = NULL;
  int carry = 0;
  while (n1 != NULL && n2 != NULL) {
    struct ListNode *node = malloc(sizeof(struct ListNode));
    int sum = n1->val + n2->val + carry;
    node->next = NULL;
    node->val = sum % 10;
    carry = sum > 9 ? 1 : 0;
    cur->next = node;
    cur = node;
    n1 = n1->next;
    n2 = n2->next;
  }
  struct ListNode *unProcessed = n1 != NULL ? n1 : n2;
  while (unProcessed != NULL) {
    struct ListNode *node = malloc(sizeof(struct ListNode));
    int sum = unProcessed->val + carry;
    node->next = NULL;
    node->val = sum % 10;
    carry = sum > 9 ? 1 : 0;
    cur->next = node;
    cur = node;
    unProcessed = unProcessed->next;
  }
  if (carry > 0) {
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->next = NULL;
    node->val = carry;
    cur->next = node;
  }
  return dummy->next;
}

int main(int argc, char *argv[]) {
  struct ListNode *l1 = malloc(sizeof(struct ListNode));
  struct ListNode *l2 = malloc(sizeof(struct ListNode));
  struct ListNode *cur = l2;
  l1->val = 1;
  l2->val = 9;
  for (int i = 0; i < 3; i++) {
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->val = 9;
    cur->next = node;
    cur = cur->next;
  }
  struct ListNode *res = addTwoNumbers(l1, l2);
  cur = res;
  while (cur != NULL) {
    printf("%d ", cur->val);
    cur = cur->next;
  }
}
