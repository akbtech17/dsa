// 7-SwapNodesInPairs.cpp
// https://leetcode.com/problems/swap-nodes-in-pairs/
#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
	int val;
	ListNode *next;

	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};

void IT(ListNode *&head, int val) {
	ListNode *newnode = new ListNode(val);
	if(!head) {
		head = newnode;
		return;
	}

	ListNode *temp = head;
	while(temp->next) temp = temp->next;
	temp->next = newnode;
	return;
}

void printList(ListNode *head) {
	while(head) {
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<endl;
	return ;
}

ListNode* reverseList(ListNode *head) {
	ListNode *n = NULL, *t = NULL;

	while(head!=NULL) {
		t = head;
		head = head->next;
		t->next = n;
		n = t;
	}

	return n;
}

ListNode* swapPairs(ListNode *head) {
	if(head == NULL or head->next == NULL) return head;
	ListNode *second = head->next;
	if(head->next) head->next = swapPairs(head->next->next);
	if(second) second->next = head;
	return second;
}

void buildList(ListNode *&head) {
	IT(head,1);
	IT(head,2);
	IT(head,3);
	IT(head,4);
	IT(head,5);
	IT(head,6);
	printList(head);
	return;
}

int main() {
	ListNode *head = NULL;
	buildList(head);
	head = swapPairs(head);
	printList(head);
	return 0;
}