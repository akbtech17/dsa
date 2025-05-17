#include <iostream>
#include <map>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode *random;
	ListNode() {
		val = 0;
		next = NULL;
		random = NULL;
	}
	ListNode(int data1) {
		val = data1;
		next = NULL;
		random = NULL;
	}
	ListNode(int data1, ListNode *next1, ListNode *r) {
		val = data1;
		next = next1;
		random = r;
	}
};

// Approach1: Bruteforce using Hash Map
// TC: O(2N)
// SC: O(N)
class Solution {
public:
	ListNode *copyRandomList(ListNode *head) {
		if (head == nullptr) return NULL;

		unordered_map<ListNode *, ListNode *> mp;
		ListNode *temp = head;
		ListNode *newHead = new ListNode(0);
		ListNode *newTail = newHead;

		while (temp != nullptr) {
			ListNode *newNode = new ListNode(temp->val);
			newTail->next = newNode;
			newTail = newNode;
			mp[temp] = newNode;
			temp = temp->next;
		}

		newHead = newHead->next;
		temp = head;
		ListNode *tempNew = newHead;

		while (temp != nullptr) {
			tempNew->random = mp[temp->random];

			temp = temp->next;
			tempNew = tempNew->next;
		}

		return newHead;
	}
};

// Approach2: Optimized
// TC: O(3N)
// SC: O(1)
class Solution {
public:
	ListNode *copyRandomList(ListNode *head) {
		// 1. Insert the Clone Node in-between each ith, (i+1)th node
		ListNode *curr = head;
		while (curr) {
			ListNode *curr_next = curr->next;
			ListNode *newnode = new ListNode(curr->val);

			newnode->next = curr_next;
			curr->next = newnode;

			curr = curr_next;
		}

		// 2. Set the Random Ptrs
		curr = head;
		while (curr) {
			curr->next->random = curr->random ? curr->random->next : NULL;
			curr = curr->next ? curr->next->next : NULL;
		}

		// 3. Seperate the two lists
		ListNode *cloneHead = head ? head->next : NULL;

		curr = head;
		ListNode *copy = cloneHead;
		while (curr and copy) {
			curr->next = curr->next ? curr->next->next : NULL;
			copy->next = copy->next ? copy->next->next : NULL;

			curr = curr->next;
			copy = copy->next;
		}

		return cloneHead;
	}
};