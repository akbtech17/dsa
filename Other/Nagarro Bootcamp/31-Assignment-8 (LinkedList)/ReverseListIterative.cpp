// ReverseListIterative.cpp
#include<iostream>
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

void insert(ListNode *&h, int val) {
	ListNode *newnode = new ListNode(val);
	if(h == NULL) {
		h = newnode;
		return;
	}
	ListNode *temp = h;
	while(temp->next!=NULL) temp = temp->next;
	temp->next = newnode;
	return;
}

ListNode *reverse(ListNode *h) {
	if(h == NULL or h->next == NULL) return h;
	ListNode *small = reverse(h->next);
	h->next->next = h;
	h->next = NULL;
	return small;
}

void printList(ListNode *h) {
	while(h!=NULL) {
		cout<<h->val<<" ";
		h = h->next;
	}
}

int main() {
	int num;
	cin>>num;
	ListNode *h = NULL;
	while(num--) {
		// cout<<num;
		int val;
		cin>>val;
		insert(h,val);
	}
	h = reverse(h);
	printList(h);
	return 0;
}