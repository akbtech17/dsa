// 1-LinkedListImplementation.cpp
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


class LinkedList {
	ListNode* head;
	ListNode* tail;
public:
	LinkedList() {
		head = NULL;
		tail = NULL;
	}

	ListNode* getHead() {
		return head;
	}

	void setHead(ListNode *head) {
		this->head = head;
	}
	void insertAtHead(int val) {
		ListNode *temp = new ListNode(val);
		if(head == NULL) tail = temp;
		temp->next = head;
		head = temp;
		return;
	}
	void insertAtTail(int val) {
		ListNode *temp = new ListNode(val), *temp2 = head;
		if(temp2 == NULL) {
			head = temp;
			tail = temp;
			return;
		}

		while(temp2->next != NULL) temp2 = temp2->next;
		temp2->next = temp;
		tail = temp;

		return;
	}

	void insertAtPos(int pos, int val) {
		if(pos <= 0) insertAtHead(val);
		else if(pos >= lengthOfList()) insertAtTail(val);
		else {
			ListNode *temp = new ListNode(val), *n = head, *p;
			pos--;
			while(pos--) {
				n = n->next;
			}
			temp->next = n->next;
			n->next = temp;
		}
		return;
	}

	void deleteAtHead() {
		if(head!=NULL) {
			ListNode *temp = head;
			head = head->next;
			delete temp;
		}	
		if(head == NULL) tail = NULL;
		return;
	}

	void deleteAtTail() {
		if(head!=NULL) {
			if(head == tail ) {
				delete head;
				head = tail = NULL;
			}
			else {
				ListNode *temp = head;
				while(temp->next!=tail) {
					temp = temp->next;
				}
				delete tail;
				temp->next = NULL;
				tail = temp;
			}
		}
		return;
	}

	void deleteAtPos(int pos) {
		if(head!=NULL) {
			if(pos <= 0) deleteAtHead();
			else if(pos >= lengthOfList()) deleteAtTail();
			else {
				ListNode* temp = head;
				pos--;
				while(pos--) {
					temp = temp->next;
				}
				ListNode* p = temp->next;
				temp->next = p->next;
				delete p; 
			}
		}
		return;
	}

	int findInList(int val) {
		ListNode* temp = head;
		int pos = 0;
		while(temp!=NULL) {
			if(temp->val == val) {
				return pos;
			}
			pos++;
			temp = temp->next;
		}
		return -1;
	}

	int recurse(ListNode* temp, int val, int pos=0) {
		if(temp == NULL) return -1;
		if(temp->val == val) return pos;
		return recurse(temp->next,val,pos+1);
	}

	int findInListRecursive(int val) {
		return recurse(head,val);
	}

	int lengthOfList() {
		int n = 0;
		ListNode *temp = head;
		while(temp!=NULL) {
			temp =  temp->next;
			n++;
		}
		return n;
	}

	bool isEmpty() {
		return head==NULL?true:false;
	}

	ListNode* findMiddleNode() {
		int len = lengthOfList();
		if(len%2 == 0) len = (len/2)-1;
		else len /=2;
		ListNode* temp = head;
		while(len--) temp = temp->next;
		return temp;
	}

	ListNode* findMiddleNode2() {
		ListNode *s,*f;
		if(head == NULL or head->next == NULL) return head;
		s = head;
		f = head->next;

		while(f!=NULL and f->next!=NULL) {
			f = f->next->next;
			s = s->next;
		} 

		return s;
	}

	void printMiddleNode() {
		cout<<"middle node is : "<<findMiddleNode2()->val<<endl;
		return;
	}

	void reverseListIterative() {
		ListNode *c = head, *n = head, *head2 = NULL;
		// c = head;
		while(c!=NULL) {
			
			n = c->next;
			c->next = head2;
			head2 = c;
			c = n;
		}

		head = head2;
		printList();
		return;
	}

	void kthLastNode(int k) {
		ListNode *s = head, *f = head;

		for(int i=0;i<k and f!=NULL;i++) {
			f = f->next;
		}

		if(f == NULL) {
			cout<<"Not Possible\n";	
			return;
		}

		while(f!=NULL) {
			s=s->next;
			f=f->next;
		}

		cout<<k<<"th node from the last is : "<<s->val<<endl;
		return;
	}
 
	void printList() {
		ListNode *temp = head;
		while(temp!=NULL) {
			cout<<temp->val;
			cout<<"->";
			temp=temp->next;
		}
		cout<<"NULL";
		cout<<endl;
		return;
	}	
};	


LinkedList mergeTwoSortedLists(LinkedList L1, LinkedList L2) {
	ListNode *h1 = L1.getHead();
	ListNode *h2 = L2.getHead();

	LinkedList L3;

	while(h1!=NULL and h2!=NULL) {
		if(h1->val<h2->val) {
			L3.insertAtTail(h1->val);
			h1 = h1->next; 
		}
		else {
			L3.insertAtTail(h2->val);
			h2 = h2->next; 
		}
	}

	while(h1!=NULL) {
		L3.insertAtTail(h1->val);
		h1 = h1->next; 
	}

	while(h2!=NULL) {
		L3.insertAtTail(h2->val);
		h2 = h2->next; 
	}
	return L3;
}


ListNode* helper(ListNode *h1, ListNode* h2) {
	if(h1 == NULL) return h2;
	if(h2 == NULL) return h1;

	if(h1->val < h2->val) {
		ListNode* temp = new ListNode(h1->val);
		temp->next = helper(h1->next,h2);
		return temp;
	}
	ListNode* temp = new ListNode(h2->val);
	temp->next = helper(h1,h2->next);
	return temp;
}

LinkedList mergeTwoSortedListsRecursive(LinkedList L1, LinkedList L2) {
	ListNode *h1 = L1.getHead();
	ListNode *h2 = L2.getHead();
	LinkedList L3;
	L3.setHead(helper(h1,h2));
	return L3;
}


int main() {
	//Instantiating List
	LinkedList L1,L2;
	for(int i=0;i<=10;i+=2) L1.insertAtTail(i);
	for(int i=1;i<=15;i+=2) L2.insertAtTail(i);

	L1.printList();
	L2.printList();

	LinkedList L3 = mergeTwoSortedListsRecursive(L1,L2);
	L3.printList();

	return 0;
}