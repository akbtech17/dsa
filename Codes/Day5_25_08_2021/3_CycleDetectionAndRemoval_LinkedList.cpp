// 3_CycleDetectionAndRemoval_LinkedList.cpp
// https://leetcode.com/problems/linked-list-cycle/

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

void buildList(ListNode*& head, vector<int> nums) {
	for(int i=0; i<nums.size(); i++) insertList(head,nums[i]);
	printList(head);
	return;
}

bool hasCycle(ListNode* head) {
	ListNode *s = head, *f = head;
	if(s->next) f = s->next->next;
	while(s != f) {
		if(s == f) return true;
		s = s->next;
		f = f->next->next;
	}

	return false;
}