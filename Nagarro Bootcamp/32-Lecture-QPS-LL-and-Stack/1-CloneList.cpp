// 1-CloneList.cpp
// assumption - List is not empty
#include<iostream>
using namespace std;

class ListNode {
public:
	int val;
	ListNode *random, *next;

	ListNode(int val) {
		this->val = val;
		this->random = nullptr;
		this->next = nullptr;
	}
};

void createList(ListNode *&head) {
	head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);

	//1->3
	head->random = head->next->next;
	//2->4
	head->next->random = head->next->next->next;
	//3->1
	head->next->next->random = head;
	//4->2
	head->next->next->next->random = head->next;
}

//
void printList(ListNode *head) {
	// {current, next, random} =>
	while(head!=NULL) {
		if(head->next and head->random) 
			cout<<"{"<<head->val<<","<<head->next->val<<","<<head->random->val<<"}";
		else if(!head->next and head->random) 
			cout<<"{"<<head->val<<","<<"NULL"<<","<<head->random->val<<"}";
		else if(!head->next and !head->random) 
			cout<<"{"<<head->val<<","<<"NULL"<<","<<"NULL"<<"}";
		else if(head->next and !head->random)
			cout<<"{"<<head->val<<","<<head->next->val<<","<<"NULL"<<"}";
		if(head) cout<<"->";
		head = head->next;
	}
	cout<<endl;
	return;
}

ListNode* cloneList(ListNode *head) {
	ListNode *cloneHead = NULL;
	//1. insert the clone node in-between ith and i+1th node
	ListNode *curr = head;
	while(curr!=NULL) {
		ListNode *curr_next = curr->next;
		ListNode *newnode = new ListNode(curr->val);

		newnode->next = curr_next;
		curr->next = newnode;
		curr = curr_next; 
	}
	// 2.set the random pointers
	curr = head;
	while(curr!=NULL) {
		if(curr->next!=NULL)
			curr->next->random = curr->random ? curr->random->next : NULL;
		if(curr->next!= NULL)
			curr = curr->next ? curr->next->next : NULL;
	}
	// 3.seperate the two lists
	cloneHead = head->next;

	curr = head;
	ListNode *copy = cloneHead;
	while(curr and copy) {
		curr->next = curr->next ? curr->next->next : NULL;
		copy->next = copy->next ? copy->next->next : NULL;

		curr = curr->next;
		copy = copy->next;
	}
	// printList(head);
	return cloneHead;
}

int main() {
	ListNode *head = nullptr;
	createList(head);

	ListNode *cloneHead = cloneList(head);
	printList(head);
	printList(cloneHead);

	//comparing the addresses
	ListNode *p = head;
	ListNode *q = cloneHead;


	while(p and q) {
		if(p!=q) cout<<"X ";
		p = p->next;
		q = q->next;
	}
	
	return 0;
}