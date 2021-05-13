// InbuiltStack.cpp
#include<iostream>
#include<stack>
using namespace std;

int main() {
	stack<int> stk;
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