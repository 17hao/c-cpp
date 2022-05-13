#include "ListNodeCpp.h"

/**
 * Given the head of a linked list, return the list after sorting
 * it in ascending order.
 *
 * @since 2021-10-27 Wednesday 16:05
 */
class Solution {
public:
  ListNode *sortList(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }
    ListNode *slow = head, *fast = head, *pre = head;
    while (fast && fast->next) {
      pre = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    pre->next = nullptr;
    return merge(sortList(head), sortList(slow));
  }

private:
  ListNode *merge(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode();
    ListNode *cur = dummy;
    while (l1 && l2) {
      if (l1->val <= l2->val) {
        cur->next = new ListNode(l1->val);
        cur = cur->next;
        l1 = l1->next;
      } else {
        cur->next = new ListNode(l2->val);
        cur = cur->next;
        l2 = l2->next;
      }
    }
    if (l1) {
      cur->next = l1;
    }
    if (l2) {
      cur->next = l2;
    }
    return dummy->next;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  std::vector<int> nums{4, 2, 1, 5, 2};
  ListNode *head = LinkedListUtils::toList(nums);
  ListNode *res = s.sortList(head);
  LinkedListUtils::printList(res);
}
