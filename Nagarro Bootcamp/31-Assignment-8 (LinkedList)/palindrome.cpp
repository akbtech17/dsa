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

void insertAtHead(ListNode *&head, int val) {
	ListNode *newnode = new ListNode(val);
	newnode->next = head;
	head = newnode;
	return;
}

ListNode* reverse(ListNode *head) {
	ListNode* newhead = NULL;
	while(head!=NULL) {
		ListNode* temp = new ListNode(head->val);
		head = head->next;
		temp->next = newhead;
		newhead = temp;
	}
	return newhead;
}

bool isSame(ListNode *h1,ListNode *h2) {
	while(h1!=NULL and h2!=NULL) {
		if(h1->val != h2->val) return false;
		h1 = h1->next;
		h2 = h2->next;
 	}
	if(h1 == NULL and h2!=NULL) return false;
	else if(h1 != NULL and h2==NULL) return false;
	return true;
}

int main() {
	ListNode *head = NULL;
	long long int num;
	cin>>num;
	while(num--) {
		int val;
		cin>>val;
		insertAtHead(head,val);
	}

	ListNode *head2 = reverse(head);

	if(isSame(head,head2)) cout<<"true";
	else cout<<"false";
	return 0;
}