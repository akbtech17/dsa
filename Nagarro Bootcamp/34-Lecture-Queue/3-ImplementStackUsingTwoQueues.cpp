// 3-ImplementStackUsingTwoQueues.cpp
#include<bits/stdc++.h>
using namespace std;

class Stack {
	queue<int> q1,q2;
public:
	Stack() {}
	
	void push(int val) {
		if(q1.empty() and q2.empty())
			q1.push(val);
		else if(!q1.empty() and q2.empty()) 
			q1.push(val);
		else q2.push(val);

		return;
	}

	void pop() {
		if(q1.empty() and q2.empty()) 
			cout<<"Stack UnderFlow";
		else if(!q1.empty() and q2.empty()) {
			while(q1.size() > 1) {
				q2.push(q1.front());
				q1.pop();
			}
			q1.pop();
		}
		else {
			while(q2.size() > 1) {
				q1.push(q2.front());
				q2.pop();
			}
			q2.pop();
		}
		return;
	}
	int top() {
		if(q1.empty() and q2.empty()) 
			cout<<"Stack UnderFlow";
		else if(!q1.empty() and q2.empty()) {
			while(q1.size() > 1) {
				q2.push(q1.front());
				q1.pop();
			}
			int el = q1.front();
			q2.push(el);
			q1.pop();
			return el;
		}
		else {
			while(q2.size() > 1) {
				q1.push(q2.front());
				q2.pop();
			}
			int el = q2.front();
			q1.push(el);
			q2.pop();
			return el;
		}
		return -1;
	}
	int size() {
		return q1.size()>0? q1.size() : q2.size()>0 ? q2.size() : 0;
	}
	bool empty() {
		return q1.empty() && q2.empty();
	}
};

int main() {
	Stack s;
	cout<<s.size()<<endl;
	
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	
	cout<<s.size()<<endl;

	while(!s.empty()) {
		cout<<s.top()<<":";
		s.pop();
	}

	return 0;
}