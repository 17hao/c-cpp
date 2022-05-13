#include <iostream>

#include "ListNodeCpp.h"

/**
 * Rotate the list to the right by k places.
 *
 * @since 2021-8-27 Friday 17:00
 */
class Solution {
public:
  ListNode *rotateRight(ListNode *head, int i) {
    if (head == nullptr) {
      return head;
    }
    int size = sizeOfList(head);
    int k = i % size;
    if (k == 0) {
      return head;
    }
    ListNode *cur = head;
    for (int i = 0; i < size - k - 1; i++) {
      cur = cur->next;
    }
    ListNode *res = cur->next;
    cur->next = nullptr;
    ListNode *tail = res;
    for (int i = 1; i < k; i++) {
      tail = tail->next;
    }
    tail->next = head;
    return res;
  }

private:
  int sizeOfList(ListNode *head) {
    int res = 0;
    while (head != nullptr) {
      res++;
      head = head->next;
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int arr[5] = {0, 1, 2, 3, 4};
  ListNode *head = toList(arr, 5);
  ListNode *res = s.rotateRight(head, 0);
  // ListNode* res = s.rotateRight(head, 1);
  // ListNode* res = s.rotateRight(head, 5);
  while (res != nullptr) {
    std::cout << res->val << " ";
    res = res->next;
  }
}
