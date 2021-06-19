// StackImplementation.cpp
#include<iostream>
#include<vector>
using namespace std;


class Stack {
	vector<int> v;
public:
	void push(int val) {
		v.push_back(val);
	}
	void pop() {
		v.pop_back();
	}
	int top() {
		return empty()? -1: v[v.size()-1];
	}
	int size() {
		return v.size();
	}
	bool empty() {
		return v.size()==0?true:false;
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