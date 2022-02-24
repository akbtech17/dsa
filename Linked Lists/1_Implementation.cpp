// 1_Implementation.cpp
// Code Link - https://ide.codingblocks.com/s/656568
#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
	int val;
	ListNode *next;

	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class List {
	ListNode *head;
	int len;
public:
	List() : head(NULL), len(0){}
	
	void printList() {
		ListNode *temp = head;
		while(temp) {
			cout<<temp->val;
			if(temp->next) cout<<"->";
			temp = temp->next;
		}
		cout<<endl<<"lenght of the list : "<<size()<<endl;
	}
	
	void push_front(int val) {
		ListNode *newnode = new ListNode(val);
		newnode->next = head;
		head = newnode;
		len++;
		return;
	}

	void push_back(int val) {
		ListNode *newnode = new ListNode(val);
		len++;
		if(!head) {
			head = newnode;
			return;
		}

		ListNode *prev = NULL;
		ListNode *temp = head;

		while(temp) {
			prev = temp;
			temp = temp->next;
		}

		prev->next = newnode;
		
		return;
	}

	void push_at(int val, int pos) {
		if(pos<1 or pos>len) return;

		len++;
		if(pos == 1) {
			push_front(val);
			return;
		}
		if(pos == len) {
			push_back(val);
			return;
		}

		ListNode *newnode = new ListNode(val);
		ListNode *temp = head;
		pos -= 2;
		while(pos--) {
			temp = temp->next;
		}
		newnode->next = temp->next;
		temp->next = newnode;

		return;
	}

	void pop_front() {
		if(!head) return;

		ListNode *key = head;
		head = head->next;

		delete key;
		len--;
		return;
	}
	void pop_back() {
		if(!head) return;

		ListNode *key = head;
		ListNode *prev = NULL;
		
		while(key->next) {
			prev = key;
			key = key->next;
		}
		prev->next = NULL;
		delete key;
		len--;
		return;
	}
	void pop_at(int pos) {
		if(pos<1 or pos>len) return;

		len--;
		if(pos == 1) {
			pop_front();
			return;
		}
		if(pos == len) {
			pop_back();
			return;
		}

		ListNode *temp = head;
		pos -= 2;
		while(pos--) {
			temp = temp->next;
		}
		ListNode *key =  temp->next;
		temp->next = key->next;
		delete key;

		return;
	}
	
	bool isEmpty() {
		return head == NULL;
	}
	int size() {
		return len;
	}

	int searchKey(int key) {
		int pos = 1;
		ListNode *temp = head;
		while(temp) {
			if(temp->val == key) return pos;
			pos++;
			temp = temp->next;
		}
		return -1;
	}
};

int main() {
	List ls;
	ls.push_back(1);
	ls.push_back(2);
	ls.push_back(3);
	ls.push_back(4);
	ls.push_front(5);

	ls.pop_front();
	ls.pop_back();
	ls.push_at(5,2);
	ls.pop_at(2);
	ls.printList();

	cout<<ls.searchKey(2);
	return 0;
}