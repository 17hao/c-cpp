/**
 * palindrome linked list
 *
 * @since 2021-7-9 Friday 11:45
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ListNode.h"

void printLinkedList(struct ListNode* head) {
	while (head != NULL) {
		printf("%d ", head->val);
		head = head->next;
	}
}

bool isPalindrome(struct ListNode* head) {
	if (head->next == NULL) {
		return true;
	}
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	struct ListNode* mid;
	if (fast != NULL) {
		mid = slow->next;
	} else {
		mid = slow;
	}
	struct ListNode* dummy = malloc(sizeof(struct ListNode));
	dummy->next = mid;
	//printLinkedList(dummy->next);
	struct ListNode* cur = mid->next;
	mid->next = NULL;
	// revrse linked list
	while (cur != NULL) {
		struct ListNode* next = cur->next;
		cur->next = dummy->next;
		dummy->next = cur;
		cur = next;
	}
	printLinkedList(dummy->next);
	cur = dummy->next;
	while (cur != NULL) {
		if (cur->val != head->val) {
			return false;
		}
		cur = cur->next;
		head = head->next;
	}
	return true;
}

struct ListNode* buildLinkedList(int* arr, int length) {
	struct ListNode* dummy = malloc(sizeof(struct ListNode));
	struct ListNode* cur = dummy;
	for (int i = 0; i < length; i++) {
		struct ListNode* node = malloc(sizeof(struct ListNode));
		node->val = arr[i];
		cur->next = node;
		cur = cur->next;
	}
	return dummy->next;
}

int main(int argc, char* argv[]) {
	int arr[6] = {1,2,3,3,2,1};
	struct ListNode* head = buildLinkedList(arr, 6);
	bool res = isPalindrome(head);
	printf("%d", res);
}
