// 3-Adding2Lists.cpp

// You are given two non-empty linked lists representing two non-negative integers
// The digits are stored in reverse order, 
// and each of their nodes contains a single digit. 
// Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, 
// except the number 0 itself.

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

void IH(ListNode *&head, int val) {
	ListNode *newnode = new ListNode(val);
	newnode->next = head;
	head = newnode;
	return;
}

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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {  
	ListNode *head = NULL;
	int carry = 0;

	if(l1->val == 0 and l1->next == NULL) return l2;
	if(l2->val == 0 and l2->next == NULL) return l1;

	while(l1 and l2) {
		int csum = l1->val+l2->val+carry;
		carry = csum/10;
		csum %= 10;
		IT(head,csum);

		l1=l1->next;
		l2=l2->next;
	} 
	while(l1) {
		int csum = l1->val+carry;
		carry = csum/10;
		csum %= 10;
		IT(head,csum);

		l1=l1->next;
	}
	while(l2) {
		int csum = l2->val+carry;
		carry = csum/10;
		csum %= 10;
		IT(head,csum);

		l2=l2->next;
	}

	while(carry>0) {
		int csum = carry;
		carry = csum/10;
		csum %= 10;
		IT(head,csum);
	}
	
	return head;
}

void buildList(ListNode *&head) {
	int d;
	cin>>d;
	while(d!=-1) {
		IH(head,d);
		cin>>d;
	}
	return;
}

void inputLists(ListNode*&L1, ListNode*&L2) {
	buildList(L1);
	buildList(L2);
	return;
}

void printList(ListNode *head) {
	while(head) {
		cout<<head->val<<" ";
		head = head -> next; 
	}
	cout<<endl;
	return;
}

int main() {
	ListNode *l1 = NULL,*l2 = NULL;
	inputLists(l1,l2);
	printList(l1);
	printList(l2);
	ListNode* l3 = addTwoNumbers(l1,l2);
	printList(l3);
	return 0;
}