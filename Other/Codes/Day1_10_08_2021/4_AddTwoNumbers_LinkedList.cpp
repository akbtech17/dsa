// 4_AddTwoNumbers_LinkedList.cpp
// https://leetcode.com/problems/add-two-numbers/

#include <iostream>
using std::cout;
using std::endl;
// using std:

class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};

void insertAtEnd(ListNode*& head, int val) {
	ListNode* newnode = new ListNode(val);
	if(head == NULL) head = newnode;
	else {
		ListNode* temp = head;
		while(temp->next != NULL) temp = temp->next;
		temp->next = newnode;
	}
	return ;
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

ListNode* buildList(int *arr, int n) {
	ListNode* head = NULL;
	for(int i=0;i<n;i++) 
		insertAtEnd(head,arr[i]);

	printList(head);
	return head;
}


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       	ListNode* head = NULL;
       	
       	int carry = 0;
       	while(l1 and l2) {
       		int csum  = l1->val + l2->val + carry;
       		carry = csum/10; 
       		csum %= 10;
       		insertAtEnd(head,csum);

       		l1 = l1->next;
       		l2 = l2->next;
       	}
       	while(l1) {
       		int csum  = l1->val + carry;
       		carry = csum/10; 
       		csum %= 10;
       		insertAtEnd(head,csum);

       		l1 = l1->next;
       	}
       	while(l2) {
       		int csum  = l2->val + carry;
       		carry = csum/10; 
       		csum %= 10;
       		insertAtEnd(head,csum);

       		l2 = l2->next;
       	}
       	while(carry) {
       		int csum  = carry;
       		carry = csum/10; 
       		csum %= 10;
       		insertAtEnd(head,csum);
       	}
       	printList(head);
       	return head;
    }	
};

int main() {
	int arr1[] = {2,4,3};
	int n1 = sizeof(arr1)/sizeof(int);
	ListNode* list1 = buildList(arr1,n1); 

	int arr2[] = {5,6,4};
	int n2 = sizeof(arr2)/sizeof(int);
	ListNode* list2 = buildList(arr2,n2); 

	Solution S;
	S.addTwoNumbers(list1,list2);

	return 0;
}