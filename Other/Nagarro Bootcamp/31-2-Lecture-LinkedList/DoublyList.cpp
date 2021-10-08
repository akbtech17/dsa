#include<iostream> 
using namespace std;

class DListNode {
public:
	int val;
	DListNode *prev, *next;
	DListNode(int val) {
		this->val = val;
		this->prev = NULL;
		this->next = NULL;
	}
};

class DoublyList {
	DListNode *head;
	DListNode *tail;
public:
	DoublyList() {
		head = NULL;
		tail = NULL;
	}

	void insertAtHead(int val) {
		DListNode *newnode = new DListNode(val);
		if(head == NULL) {
			head = newnode;
			tail = newnode;
		}
		else {
			newnode->next = head;
			head->prev = newnode;
			head = newnode;
		}
		return;
	}

	void insertAtTail(int val) {
		DListNode *newnode = new DListNode(val);
		if(head == NULL) {
			head = newnode;
			tail = newnode;
		}
		else {
			tail->next = newnode;
			newnode->prev = tail;
			tail = newnode;
		}
		return;
	}

	void deleteAtHead() {
		if(head == NULL) return;
		else if(head == tail) {
			delete head;
			head = NULL;
			tail = NULL;
		}
		DListNode *temp = head;
		head = head->next;
		head->prev = NULL;
		delete temp;
	}

	void deleteAtTail() {
		if(head == NULL) return;
		else if(head == tail) {
			delete head;
			head = NULL;
			tail = NULL;
		}
		DListNode *temp = tail;
		tail = tail->prev;
		tail->next = NULL;
		delete temp;
	}

	void printList() {
		DListNode *temp = head;
		while(temp!=NULL) {
			cout<<temp->val<<"->";
			temp = temp->next;
		}
		cout<<"NULL\n";
		temp = tail;
		cout<<"NULL";
		while(temp!=NULL) {
			cout<<"<-"<<temp->val;
			temp = temp->prev;
		}
		cout<<"\n";
		return;
	}
};

int main() {
	DoublyList List;
	List.insertAtTail(1);
	List.insertAtTail(2);
	List.insertAtTail(3);
	List.insertAtTail(4);
	List.insertAtTail(5);
	List.deleteAtHead();
	List.deleteAtTail();
	List.printList();

	return 0;
}