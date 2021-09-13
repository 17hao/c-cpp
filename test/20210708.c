/**
 * Find 5th element from tail
 *
 * @since 2021-7-8 Thursday 14:39
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    struct ListNode* next;
    int val;
};

struct ListNode* func(struct ListNode* head, int i) {
    int count = 0;
    struct ListNode* cur = head;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    int index = 0;
    cur = head;
    while (index++ < count - i) {
        cur = cur->next;
    }
    return cur;
}

int main(int argc, char* argv[]) {
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->val = 1;
    struct ListNode* cur = dummy;
    for (int i = 6; i > 0; i--) {
        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->val = i;
        cur->next = node;
        cur = cur->next;
        // printf("%d->", node->val);
    }
    struct ListNode* res = func(dummy->next, 2);
    printf("%d", res->val);
}
