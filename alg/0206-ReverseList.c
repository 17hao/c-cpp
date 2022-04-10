/*
 * reverse linked list
 *
 * @since 2021-7-12 Monday 16:53 - 17:31
 */

#include "ListNode.h"
#include <stdio.h>
#include <stdlib.h>

struct ListNode *reverseList(struct ListNode *head) {
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    struct ListNode *curNode = head;
    while (curNode != NULL) {
        struct ListNode *nextNode = curNode->next;
        curNode->next = dummy->next;
        dummy->next = curNode;
        curNode = nextNode;
    }
    return dummy->next;
}

int main(int argc, char *argv[]) {
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    struct ListNode *cur = dummy;
    int n = 10;
    for (int i = 0; i < n; i++) {
        struct ListNode *node = malloc(sizeof(struct ListNode));
        node->val = i;
        cur->next = node;
        cur = cur->next;
    }
    struct ListNode *res = reverseList(dummy->next);
    cur = res;
    while (cur != NULL) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
}
