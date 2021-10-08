// BubbleSort.cpp
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

void printList(ListNode *head) {
	while(head) {
		cout<<head->val<<" ";
		head= head->next;
	}
	return;
}

void sortList(ListNode *head) {
	int len = 0;
	ListNode *temp = head;
	while(temp) {
		temp = temp->next;
		len++;
	}
	while(len--) {
		ListNode *temp2 = head;
		bool swapHua = false;
		while(temp2) {
			if(temp2->next and temp2->val>temp2->next->val) {
				swap(temp2->val,temp2->next->val);	
				swapHua = true;		
			}
			temp2 = temp2->next;
		} 
		if(!swapHua) break;
		
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