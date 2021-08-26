#include <iostream>

struct ListNode {
    int val;

    ListNode* next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode* next) : val(x), next(next) {
    }
};

ListNode* toList(int* arr, int len) {
    ListNode* dummy = new ListNode();
    ListNode* cur = dummy;
    for (int i = 0; i < len; i++) {
        ListNode* node = new ListNode(arr[i]);
        cur->next = node;
        cur = cur->next;
    }
    return dummy->next;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
}