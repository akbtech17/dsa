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

	void printList() {
		ListNode *temp = head;
		while(temp!=NULL) {
			cout<<temp->val;
			if(temp->next != NULL) cout<<"->";
			temp=temp->next;
		}
		cout<<endl;
		return;
	}
};	

int main() {
	//Instantiating List
	LinkedList L1;
	//Inserting ELements
	for(int i=1;i<=10;i++)
		L1.insertAtTail(i);
	
	//print List
	L1.printList();

	L1.insertAtPos(10,0);
	L1.printList();

	L1.deleteAtPos(10);
	L1.printList();
	L1.deleteAtPos(1);
	L1.printList();


	// //finding length of List
	// cout<<"length of list : "<<L1.lengthOfList()<<endl;

	// //searching an element in list
	// int key = 3;
	// if(L1.findInList(key) != -1) cout<<key<<" is found at "<<findInList(key)<<"\n";
	// else cout<<key<<" is not found\n";

	// key = 0;
	// if(L1.findInList(key) != -1) cout<<key<<" is found at "<<findInList(key)<<"\n";
	// else cout<<key<<" is not found\n";

	// //deleting nodes
	// bool deleteHead = true;
	// while(L1.isEmpty() == false) {
	// 	if(deleteHead) {
	// 		L1.deleteAtHead();
	// 		deleteHead= false; 
	// 	}
	// 	else {
	// 		L1.deleteAtTail();
	// 		deleteHead = true;
	// 	}
	// 	L1.printList();
	// }

	// //searching an element in list recursive
	// int key = 3;
	// if(L1.findInListRecursive(key) != -1) cout<<key<<" is found at "<<L1.findInListRecursive(key)<<" \n";
	// else cout<<key<<" is not found\n";

	// key = 0;
	// if(L1.findInListRecursive(key) != -1) cout<<key<<" is found at "<<L1.findInListRecursive(key)<<" \n";
	// else cout<<key<<" is not found\n";
	return 0;
}