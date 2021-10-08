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

void insert(ListNode *&head,int val) {
	ListNode *newnode = new ListNode(val);
	newnode->next = head;
	head= newnode;
	return;
}

// ListNode* merge(ListNode *h1, ListNode* h2) {
// 	if(h1 == NULL) return h2;
// 	if(h2 == NULL) return h1;	

// 	ListNode *h3 = NULL;
// 	if(h1->val<h2->val) {
// 		h3 = new ListNode(h1->val);
// 		h3->next = merge(h1->next,h2);
// 		return h3;
// 	}
// 	h3 = new ListNode(h2->val);
// 	h3->next=merge(h1,h2->next);
// 	return h3;
// }

ListNode *merge(ListNode *h1, ListNode *h2) {
	if(h1 == NULL) return h2;
	if(h2 == NULL) return h1;

	ListNode *h3 = NULL;
	if(h1->val < h2->val) {
		h3 = new ListNode(h1->val);
		h3->next = merge(h1->next,h2);
		return h3; 
	}
	h3 = new ListNode(h2->val);
	h3->next = merge(h1,h2->next);
	return h3;
}

ListNode *getMid(ListNode *head) {
	if(head == NULL or head->next == NULL) return head; 
	ListNode *s = head;
	ListNode *f = head->next;

	while( f!=NULL and f->next!=NULL) {
		f = f->next->next;
		s = s->next;
	}
	return s;

}

// ListNode* getMid(ListNode *head) {
// 	if(head == NULL or head->next == NULL) return head;
// 	ListNode *s = head;
// 	ListNode *f = head->next;

// 	while(f!=NULL and f->next!=NULL) {
// 		f = f->next->next;
// 		s = s->next;
// 	}

// 	return s;
// }

void printList(ListNode *head) {
	while(head!=NULL) {
		cout<<head->val<<" ";
		head = head->next;
	}
	return;
}

ListNode* ms(ListNode *head) {
	if(head == NULL or head->next==NULL) return head;
	ListNode *mid = getMid(head);
	ListNode *head2 = mid->next;
	mid->next = NULL;
	head = ms(head);
	head2 = ms(head2);
	return merge(head,head2);
}

// ListNode* ms(ListNode *head) {
// 	if(head == NULL or head->next == NULL) return head;
// 	ListNode *mid = getMid(head);
// 	ListNode *head2 = mid->next;
// 	mid->next = NULL;

// 	head = ms(head);
// 	head2 = ms(head2);

// 	return merge(head,head2);
// }

int main() {
	int num;
	cin>>num;
	ListNode *head= NULL;
	while(num--) {
		int val;
		cin>>val;
		insert(head,val);
	}
	head = ms(head);
	printList(head);
	return 0;
}