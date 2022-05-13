#include "ListNodeCpp.h"

using namespace LinkedListUtils;

/**
 * @since 2021-9-10 Friday 15:40
 */
class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    ListNode *dummy = new ListNode();
    ListNode *beforeHead = new ListNode();
    ListNode *head0 = beforeHead;
    ListNode *afterHead = new ListNode();
    ListNode *head1 = afterHead;
    while (head != nullptr) {
      if (head->val < x) {
        head0->next = head;
        head0 = head0->next;
      } else {
        head1->next = head;
        head1 = head1->next;
      }
      head = head->next;
    }
    head1->next = nullptr;
    head0->next = afterHead->next;
    return beforeHead->next;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int arr[6] = {1, 4, 3, 2, 5, 2};
  ListNode *head = toList(arr, 6);
  ListNode *res = s.partition(head, 3);
  printList(res);
}
