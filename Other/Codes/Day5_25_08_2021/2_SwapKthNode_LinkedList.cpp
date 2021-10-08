// 2_SwapKthNode_LinkedList.cpp
// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

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

int lengthOfList(ListNode* head) {
	if(!head) return 0;
	return 1+lengthOfList(head->next);
}

ListNode* swapNodes(ListNode* head, int k) {
	int l = lengthOfList(head);
	int n1 = k-1;
	int n2 = l-k;
	ListNode *s = head, *f = head;
	while(n1--) s = s->next;
	while(n2--) f = f->next;
	swap(s->val,f->val);
	return head;
}

int main() {
	ListNode* head = NULL;
	buildList(head, {1,2,3});
	printList(swapNodes(head,2));
	return 0;
}