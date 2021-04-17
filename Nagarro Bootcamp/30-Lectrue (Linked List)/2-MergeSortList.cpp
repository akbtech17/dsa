// 2-MergeSortList.cpp
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
	ListNode* n = new ListNode(val);
	if(head == NULL) {
		head = n;
		return;
	}
	ListNode *temp = head;
	while(temp->next!=NULL) temp = temp->next;
	temp->next = n;
	return;
}

void printList(ListNode *head) {
	while(head!=NULL) {
		cout<<head->val<<"->";
		head=head->next;
	}
	if(head == NULL) cout<<"null\n";
	return;
}

ListNode *mergeSortedLists(ListNode *h1, ListNode *h2) {
	if(h1 == NULL) return h2;
	if(h2 == NULL) return h1;

	ListNode *h3 = NULL;
	if(h1->val < h2->val) {
		h3 = new ListNode(h1->val);
		h3->next = mergeSortedLists(h1->next,h2);
		return h3; 
	}
	h3 = new ListNode(h2->val);
	h3->next = mergeSortedLists(h1,h2->next);
	return h3;
}

ListNode* getMiddle(ListNode *head) {
	if(head == NULL or head->next == NULL) return head;
	ListNode *s = head;
	ListNode *f = head->next;

	while(f!=NULL and f->next!=NULL) {
		f = f->next->next;
		s = s->next;
	}

	return s;
}

ListNode* mergeSort(ListNode *head) {
	if(head == NULL or head->next == NULL) return head;
	ListNode *mid = getMiddle(head);
	ListNode *head2 = mid->next;
	mid->next = NULL;

	head = mergeSort(head);
	head2 = mergeSort(head2);

	return mergeSortedLists(head,head2);
}

int main() {
	// ListNode *head1 = NULL;
	// insertAtTail(head1,1);
	// insertAtTail(head1,3);
	// insertAtTail(head1,5);
	// printList(head1);

	ListNode *head2 = NULL;
	insertAtTail(head2,5);
	insertAtTail(head2,4);
	insertAtTail(head2,3);
	insertAtTail(head2,2);
	insertAtTail(head2,1);
	head2 = mergeSort(head2);
	printList(head2);

	// ListNode *head3 = mergeSortedLists(head1,head2);
	// printList(head3);
	


	return 0;
}