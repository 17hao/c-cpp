/**
 * Remove nth node from the end of list and return its head.
 *
 * @since 2021-7-27 Tuesday 19:24
 * @finish 2021-8-4 Wednesday 16:36
 */

#include <stdio.h>
#include <stdlib.h>

#include "ListNode.h"

/**
 * time complexity O(2n)
 * space complexity O(1)
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* cur = head;
    int len = 0;
    while (cur != NULL) {
        len++;
        cur = cur->next;
    }
    printf("%d\n", len);
    struct ListNode* pre = dummy;
    for (int i = 0; i < len - n; i++) {
        pre = pre->next;
    }
    printf("%d\n", pre->val);
    struct ListNode* next = pre->next->next;
    pre->next = next;
    return dummy->next;
}

/**
 * time complexity O(n)
 * space complexity O(n)
 */
struct ListNode* removeNthFromEndImprove(struct ListNode* head, int n) {
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* pre = dummy;
    while (1) {
        struct ListNode* cur = pre;
        for (int i = 0; i <= n; i++) {
            cur = cur->next;
        }
        if (cur == NULL) {
            struct ListNode* next = pre->next->next;
            pre->next = next;
            return dummy->next;
        } else {
            pre = pre->next;
        }
    }
}

int main(int argc, char* argv[]) {
    int* arr = malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++) {
        arr[i] = i;
    }
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    struct ListNode* cur = dummy;
    for (int i = 0; i < 5; i++) {
        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->val = arr[i];
        cur->next = node;
        cur = cur->next;
    }
    cur = removeNthFromEndImprove(dummy->next, 1);
    while (cur != NULL) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
}