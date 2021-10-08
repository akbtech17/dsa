// MergeTwoSortedLists.cpp
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

ListNode* modifyList(ListNode* h1, ListNode* h2) {
	if(h1 == NULL) return h2;
	if(h2 == NULL) return h1;

	if(h1->val<h2->val) {
		ListNode *temp = new ListNode(h1->val);
		temp->next = modifyList(h1->next,h2);
		return temp;
	}

	ListNode *temp = new ListNode(h2->val);
	temp->next = modifyList(h1,h2->next);
	return temp;
}


int main() {
	int t;
	cin>>t;
	while(t--) {
		ListNode *h1=NULL, *h2=NULL;
		int n1,n2,val;
		cin>>n1;
		while(n1--) {
			int val;
			cin>>val;
			insertAtTail(h1,val);
		}
		cin>>n2;
		while(n2--) {
			int val;
			cin>>val;
			insertAtTail(h2,val);
		}
		ListNode *h3 = modifyList(h1,h2);
		printList(h3);
		cout<<endl;
	}
	
	return 0;
}