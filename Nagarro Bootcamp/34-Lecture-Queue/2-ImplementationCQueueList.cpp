// 2-ImplementationCQueueList.cpp
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

void insertAtTail(ListNode *&f, ListNode *&e, int val) {
	ListNode *newnode = new ListNode(val);
	if(!f) {
		f = newnode;
		e = newnode;
		return;
	}
	e->next = newnode;
	e = newnode;
	return;
}
void deleteAtHead(ListNode *&f, ListNode *&e) {
	if(f == NULL) return;
	if(f == e) {
		ListNode *temp = f; 
		delete temp;
		f = e = NULL;
		return;
	}
	ListNode *temp = f; 
	f = f->next; 
	delete temp;
	return;
}

class Queue {
	ListNode *f,*e;
	int cs;
public:
	Queue() {
		cs = 0;
		f = e = NULL;
	}
	void push(int val) {
		insertAtTail(f,e,val);
		cs++;
		return;
	}
	void pop() {
		if(!f) {
			cout<<"Queue UnderFLow\n";
			return;
		}
		deleteAtHead(f,e);
		cs--;
		return;
	}
	int front() {
		return f!=NULL ? f->val : -1;
	}
	int size() {
		return cs;
	}
	bool empty() {
		return f == NULL;
	}
};

int main() {
	Queue q;
	cout<<q.size()<<endl;
	
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	
	cout<<q.size()<<endl;

	while(!q.empty()) {
		cout<<q.front()<<":";
		q.pop();
	}

	return 0;
}