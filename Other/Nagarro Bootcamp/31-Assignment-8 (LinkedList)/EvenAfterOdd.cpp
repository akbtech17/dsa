// EvenAfterOdd.cpp
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


void insertAtTail(ListNode *&head, int val) {
	ListNode *newnode = new ListNode(val);
	if(head == NULL) {
		head = newnode;
		return;
	}

	ListNode *temp = head;
	while(temp->next!=NULL) temp=temp->next;
	temp->next = newnode;
	return;
}

void printList(ListNode *head) {
	while(head!=NULL) {
		cout<<head->val<<" ";
		head = head->next;
	}
	return;
}

void insertAtLast(ListNode*&list, ListNode* node) {
	if(!list) {
		list = node;
		node->next = NULL;
		return;
	}
	ListNode *temp = list;
	while(temp->next) temp=temp->next;
	temp->next = node;
	node->next = NULL;
	return;
}

ListNode* modifyList(ListNode* head) {
	ListNode* odd = NULL;
	ListNode* even = NULL;

	while(head!=NULL) {
		if(head->val%2!=0) {
			//odd
			ListNode* temp = head;
			head = head->next;
			insertAtLast(odd,temp);
		}
		else {
			//even
			ListNode* temp = head;
			head = head->next;
			insertAtLast(even,temp);
		}
		// head= head->next;
	}

	//connect lists
	ListNode *temp = odd;
	while(temp->next) temp = temp->next;
	temp->next = even; 
	return odd;
}


int main() {
	ListNode *head = NULL;
	long long int num;
	cin>>num;
	
	while(num--) {
		int val;
		cin>>val;
		insertAtTail(head,val);
	}
	head = modifyList(head);
	printList(head);
	return 0;
}