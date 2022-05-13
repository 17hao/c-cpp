#include <iostream>

#include "ListNodeCpp.h"

/**
 * Reorder list
 *
 * @since 2021-8-6 Friday 17:46
 * @finished 2021-8-11 Wednesday 17:45
 */
class Solution {
public:
  void reorderList(struct ListNode *head) {
    // find middle of linked list
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
    }
    struct ListNode *half = slow->next;
    slow->next = nullptr;

    // reverse second half linked list
    struct ListNode *dummy = new ListNode();
    while (half != nullptr) {
      struct ListNode *next = half->next;
      half->next = dummy->next;
      dummy->next = half;
      half = next;
    }

    // reorder 2 linked lists
    struct ListNode *firstHalf = head;
    struct ListNode *secondHalf = dummy->next;
    while (firstHalf != nullptr && secondHalf != nullptr) {
      struct ListNode *next1 = firstHalf->next;
      struct ListNode *next2 = secondHalf->next;
      firstHalf->next = secondHalf;
      secondHalf->next = next1;
      firstHalf = next1;
      secondHalf = next2;
    }
    // if (firstHalf != nullptr) {
    //     secondHalf->next = firstHalf;
    // }
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  struct ListNode *dummy = new ListNode();
  struct ListNode *cur = dummy;
  for (int i = 1; i < 5; i++) {
    struct ListNode *node = new ListNode(i);
    cur->next = node;
    cur = cur->next;
  }
  s.reorderList(dummy->next);
  cur = dummy->next;
  while (cur != nullptr) {
    std::cout << cur->val << " ";
    cur = cur->next;
  }
}
