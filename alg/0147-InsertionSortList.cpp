#include "ListNodeCpp.h"

/**
 * Sort the list useing insertion sort
 *
 * @since 2021-9-2 Thursday 16:52
 */
class Solution {
public:
  struct ListNode *insertionSortList(struct ListNode *head) {
    struct ListNode *dummy = new ListNode();
    while (head != nullptr) {
      struct ListNode *pre = dummy;
      while (pre->next != nullptr && pre->next->val < head->val) {
        pre = pre->next;
      }
      struct ListNode *next = pre->next;
      struct ListNode *nextHead = head->next;
      pre->next = head;
      head->next = next;
      head = nextHead;
    }
    return dummy->next;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int arr[5] = {3, 2, 4, 56, 1};
  struct ListNode *head = toList(arr, 5);
  struct ListNode *res = s.insertionSortList(head);
  printList(res);
}
