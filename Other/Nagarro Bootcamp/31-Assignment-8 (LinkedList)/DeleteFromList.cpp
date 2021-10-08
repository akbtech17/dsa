// DeleteFromList.cpp
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

void insert(ListNode *&head, int val) {
	ListNode *newnode = new ListNode(val);
	if(head == NULL) {
		head = newnode;
		return;
	}
	ListNode *temp = head;
	while(temp->next!=NULL) temp = temp->next;
	temp->next = newnode;
	return;
}

void del(ListNode *&head, int pos) {
	if(pos == 0) {
		head = head->next;
		return;
	}
	ListNode *temp = head, *prev;
	while(pos--) {
		prev = temp;
		temp = temp->next;
	}
	prev->next = temp->next;
	return;
}

void printList(ListNode *head) {
	while(head!=NULL) {
		cout<<head->val<<" "; 
		head = head->next;
	}
	// cout<<ndl;
	return;
}
int main() {
	int num,q;
	cin>>num>>q;
	ListNode *head = NULL;
	while(num--) { 
		int val;
		cin>>val;
		insert(head,val);
	}

	while(q--) {
		int pos;
		cin>>pos;
		del(head,pos);
		printList(head);
		cout<<endl;
	}
	return 0;
}