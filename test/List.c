#include <stdio.h>

struct ListNode {
	struct ListNode* next;
	int val;
};

int main(int argc, char* argv[]) {
	struct ListNode* head = &(struct ListNode) {.next = NULL, .val = 0};
	struct ListNode* next = &(struct ListNode) {.next = NULL, .val = 1};
	head->next = next;
	struct ListNode* cur = head;
	while (cur != NULL) {
		printf("%d -> ", cur->val);
		cur = cur->next;
	}
	return 0;
}
