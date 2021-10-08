// InsertionSort.cpp
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

void insertAtTail(ListNode *&head, int val) {
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

void buildList(ListNode *&head) {
	long long int n;
	cin>>n;
	while(n--) {
		int d;
		cin>>d;
		// cout<<d;
		insertAtTail(head,d);
	}
	return;
}

void insertBefore(ListNode *&list, ListNode *node, ListNode* nodei) {
	//insert at head
	if(node == list) {
		nodei->next = list;
		list = nodei;
		return;
	}
	
	ListNode *prev = list;
	while(prev->next!=node) prev = prev->next;
	nodei->next = prev->next;
	prev->next = nodei;
	return;
}

void printList(ListNode *head) {
	while(head) {
		cout<<head->val<<" ";
		head= head->next;
	}
	return;
}


void sortList(ListNode *&head) {
	if(!head or !head->next) return;
	ListNode *temp = head->next;
	while(temp) {
		ListNode *itr = head;
		ListNode *next = temp->next;
		while(itr!=temp) {
			if(itr->val<=temp->val) itr=itr->next;
			else {
				insertBefore(head,itr,temp);
				break;
			}
		}
		temp = next;
	} 
	return;
}

int main() {
	ListNode *head = NULL;
	buildList(head);
	sortList(head);
	printList(head);

	return 0;
}