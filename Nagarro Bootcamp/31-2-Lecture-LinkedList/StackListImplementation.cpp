// StackListImplementation.cpp
#include <iostream>
using namespace std;

class ListNode {
public:
	int val;
	ListNode *next;
	ListNode(int val) {
		this->val = val;
		next = NULL;
	}
};

class Stack {
	ListNode *head;
	int len;
public:
	Stack() {
		len = 0;
		head = NULL;
	}

	void push(int val) {
		ListNode *newnode = new ListNode(val);
		newnode->next = head;
		head = newnode;
		len++;
		return;
	}
	void pop() {
		if(len == 0) return;
		ListNode *temp = head;
		head = head->next;
		delete temp;
		len--;
		return;
	}
	bool empty() {
		return len==0?true:false;
	}

	int size() {
		return len;
	}
	
	int top() {
		return len==0?-1:head->val;
	}

};

int main() {
	Stack stk;

	stk.push(1);
	stk.push(2);
	stk.push(3);
	cout<<"size of stk is "<<stk.size()<<endl;
	while(!stk.empty()) {
		cout<<stk.top();
		stk.pop();
	}

	return 0;
}