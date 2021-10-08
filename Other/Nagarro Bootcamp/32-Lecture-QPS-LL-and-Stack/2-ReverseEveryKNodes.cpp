// 2-kReverse.cpp
//assumption - non-empty list
#include<iostream>
using namespace std;

class ListNode {
public:
	int val;
	ListNode *next;

	ListNode(int val) {
		this->val = val;
		this->next = nullptr;
	}
};

void insertAtTail(ListNode *&head, int val) {
	ListNode *newnode = new ListNode(val);
	if(head == NULL) {
		head = newnode;
		return;
	}
	ListNode *curr = head;
	while(curr->next) {
		curr = curr->next;
	}
	curr->next = newnode;
	return;
}

void buildList(ListNode *&head) {
	int val;
	cin>>val;
	while(val!=-1) {
		insertAtTail(head,val);
		cin>>val;
	}
	return;
}

void buildList2(ListNode *&head) {
	int val;
	cin>>val;
	//initially it cannot be -1
	head = new ListNode(val);
	ListNode *curr = head;

	while(val!=-1) {
		cin>>val;
		if(val == -1) break;

		ListNode* newnode = new ListNode(val);
		curr->next = newnode;
		curr = newnode;
	}

	return;
}

void printList(ListNode *head) {
	while(head!=NULL) {
		cout<<head->val<<"->";
		head = head->next;
	}
	cout<<"NULL"<<endl;
	return;
}

ListNode* reverseList(ListNode *head) {
	ListNode *prev = NULL;
	ListNode *curr = head;
	while(curr) {
		ListNode *nextnode = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextnode;
	}

	return prev;
}

ListNode* kReverse(ListNode *head, int k) {
	//base case
	if(head == NULL) return NULL;

	ListNode *prev = NULL;
	ListNode *curr = head;
	ListNode *nextnode = NULL;

	int cnt = 0;
	// k-reverse the first k nodes
	while(curr and cnt<k) {
		nextnode = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextnode;
		cnt++;
	}

	//recursive case
	ListNode *smallList = kReverse(curr,k);

	//join the small list
	head->next = smallList;
	return prev;
}

int main() {
	ListNode *head = nullptr;
	buildList2(head);
	int k;
	cin>>k;
	printList(head);
	head = kReverse(head,k);
	printList(head);
	return 0;
}