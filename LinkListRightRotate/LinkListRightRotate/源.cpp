#include <iostream>

using namespace std;

/**
* Definition for singly-linked list.

*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		//base cases
		if (nullptr == head) {
			return nullptr;
		}
		if (nullptr == head->next) {
			return head;
		}
		// close linkList into the ring
		ListNode* oldTail = head;
		int n;
		for (n = 1; nullptr != oldTail->next; n++) {
			oldTail = oldTail->next;
		}
		oldTail->next = head;
		// find new tail
		ListNode* newTail = head;
		for (int i = 0; i < n - k%n - 1; ++i)
		{
			newTail = newTail->next;
		}
		ListNode* newHead = newTail->next;
		// break the ring
		newTail->next = nullptr;
		return newHead;
	}
};


int main()
{
	Solution solution;
	ListNode* head = new ListNode(1);
	ListNode* curNode;
	curNode = head;
	for (int i = 2; i < 6; ++i) {
		ListNode* node = new ListNode(i);
		curNode->next = node;
		curNode = node;
	}
	curNode = nullptr;
	solution.rotateRight(head, 2);
	return 0;
}