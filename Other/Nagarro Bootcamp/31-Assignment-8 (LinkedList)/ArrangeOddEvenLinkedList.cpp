// ArrangeOddEvenLinkedList.cpp
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

ListNode *modifyList(ListNode* head) {
	if(!head) return NULL;
	ListNode* evenHead = head->next;

	ListNode* oddItr = head;
	ListNode* evenItr = evenHead;
	while(oddItr and evenItr) {
		oddItr->next = oddItr->next ? oddItr->next->next : NULL;
		oddItr = oddItr->next;
		evenItr->next = evenItr->next ? evenItr->next->next : NULL;
		evenItr = evenItr->next;
	}

	oddItr = head;
	while(oddItr->next) oddItr = oddItr->next;
	oddItr->next = evenHead;
	return head;
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
	cout<<"Original List: ";
	printList(head);
	cout<<endl<<"Modified List: ";
	head = modifyList(head);
	printList(head);
	return 0;
}