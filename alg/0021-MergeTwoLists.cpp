#include <iostream>

#include "ListNodeCpp.h"

using namespace LinkedListUtils;

/**
 * Merge two sorted linked lists
 *
 * @since 2021-8-26 Thursday 14:58
 */
class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode();
    ListNode *cur = dummy;
    while (l1 != nullptr && l2 != nullptr) {
      while (l1 != nullptr && l2 != nullptr && l1->val <= l2->val) {
        cur->next = l1;
        cur = cur->next;
        l1 = l1->next;
      }
      while (l1 != nullptr && l2 != nullptr && l2->val < l1->val) {
        cur->next = l2;
        cur = cur->next;
        l2 = l2->next;
      }
    }
    if (l1 == nullptr) {
      cur->next = l2;
    }
    if (l2 == nullptr) {
      cur->next = l1;
    }
    return dummy->next;
  }

  ListNode *mergeTwoLists1(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode();
    ListNode *cur = dummy;
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val <= l2->val) {
        cur->next = l1;
        l1 = l1->next;
      } else {
        cur->next = l2;
        l2 = l2->next;
      }
      cur = cur->next;
    }
    if (l1 == nullptr) {
      cur->next = l2;
    } else {
      cur->next = l1;
    }
    return dummy->next;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  // int a[4] = {1, 2, 3, 4};
  int a[4] = {1, 2, 3, 4};
  ListNode *l1 = toList(a, 4);
  // int b[4] = {2, 3, 4, 5};
  int b[4] = {5, 6, 7, 8};
  ListNode *l2 = toList(b, 4);
  // ListNode* res = s.mergeTwoLists(l1, l2);
  ListNode *res = s.mergeTwoLists1(l1, l2);
  printList(res);
}
