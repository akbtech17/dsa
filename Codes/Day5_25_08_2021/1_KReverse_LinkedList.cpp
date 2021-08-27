// 1_KReverse_LinkedList.cpp
// https://leetcode.com/problems/reverse-nodes-in-k-group/
#include <bits/stdc++.h>
using namespace std;

class ListNode {
	public:
		int val;
		ListNode* next;

		ListNode(int val) {
			this->val = val;
			next = NULL;
		}
};

void insertList(ListNode*& head, int val) {
	ListNode* newnode = new ListNode(val);
	if(!head) {
		head = newnode;
		return;
	}
	ListNode* temp = head;
	while(temp->next) temp = temp->next;
	temp->next = newnode;
}

void printList(ListNode* head) {
	while(head) {
		cout<<head->val;
		if(head->next) cout<<"->";
		head = head->next;
	}
	cout<<endl;
	return;
}

void buildList(ListNode*& head) {
	for(int i=1; i<=5; i++) insertList(head,i);
	printList(head);
	return;
}

ListNode* reverseListRecursive(ListNode* head) {
	if(!head or !head->next) return head;
	ListNode* smallList = reverseListRecursive(head->next);
	head->next->next = head;
	head->next = NULL;
	return smallList;
}

ListNode* reverseListIterative(ListNode* head) {
	ListNode *prev = NULL, *curr = head;
	while(curr) {
		ListNode* nextnode = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextnode;
	}
	return prev;
}

ListNode* kReverse(ListNode* head, int k) {
	if(!head) return NULL;
	int i = k;
	ListNode *prev = NULL, *curr = head;
	while(curr and i > 0) {
		ListNode* nextnode = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextnode;
		i--;
	}
	ListNode* smallList = kReverse(curr,k);
	head->next = smallList;
	return prev;
}

int lengthOfList(ListNode* head) {
	if(!head) return 0;
	return 1+lengthOfList(head->next);
}

ListNode* solve(ListNode* head, int k, int d) {
	if(d == 0) return head;
	if(!head) return NULL;
	int i = k;
	ListNode *prev = NULL, *curr = head;
	while(curr and i > 0) {
		ListNode* nextnode = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextnode;
		i--;
	}
	ListNode* smallList = solve(curr,k,d-1);
	head->next = smallList;
	return prev;
}

ListNode* reverseKGroup(ListNode* head, int k) {
	int l = lengthOfList(head);
	int d = l/k;
	ListNode* krev = solve(head,k,d);
	// printList(krev);
	return krev;
}

int main() {
	ListNode* head = NULL;
	buildList(head);
	// head = reverseListIterative(head);
	// head = reverseListRecursive(head);
	head = reverseKGroup(head,3);
	printList(head);
	return 0;
}