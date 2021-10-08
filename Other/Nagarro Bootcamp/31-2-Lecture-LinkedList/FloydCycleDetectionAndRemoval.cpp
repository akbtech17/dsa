// FloydCycleDetectionAndRemoval.cpp
#include <iostream>
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

void insertAtTail(ListNode *&head, int val) {
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

void printList(ListNode *head) {
	while(head!=NULL) {
		cout<<head->val<<"->";
		head = head->next;
	}
	cout<<"NULL\n";
	return;
}

void createCycle(ListNode *&head) {
	ListNode *last = head;
	while(last->next!=NULL) last = last->next;
	last->next = head->next->next;
	return;
}

void removeCycle(ListNode *head, ListNode *f, ListNode *s) {
	s = head;
	ListNode *prev = head;

	while(prev->next != f) {
		prev = prev->next;
	}

	while(s!=f) {
		prev = f;
		f = f->next;
		s = s->next;
	}
	prev->next = NULL;
	return;
}

bool isCyclePresent(ListNode *head) {
	ListNode *s = head;
	ListNode *f = head;

	while(f and f->next) {
		 s = s->next;
		f = f->next->next;
		if(s == f) {
			removeCycle(head,f,s);
			return true;
		}
	}
	return false;
}



int main() {
	ListNode *head = NULL;
	for(int i=1;i<=10;i++)
		insertAtTail(head,i);
	
	// createCycle(head);
	// printList(head);
	// if(isCyclePresent(head)) cout<<"cycle is present\n";
	// else cout<<"cycle is not present\n";

	createCycle(head);
	if(isCyclePresent(head)) cout<<"cycle is present\n";
	else cout<<"cycle is not present\n";
	printList(head);
	return 0;
}