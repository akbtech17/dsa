// 1-ReverseStackUsingRecursiveStack.cpp
#include <iostream>
#include <stack>
using namespace std;


void pushAtBottom(stack<int> &stk, int te) {
	if(stk.empty()) {
		stk.push(te);
		return;
	}
	int te2 = stk.top();
	stk.pop();
	pushAtBottom(stk,te);
	stk.push(te2);

	return;
}

//using recursive space
void reverseStack(stack<int> &stk) {
	//base case
	if(stk.empty()) return;
	
	//remove the top element
	int te = stk.top();
	stk.pop();
	//reverse the small stk
	reverseStack(stk);

	//push the top element at the bottom
	pushAtBottom(stk,te);
	return;
}

int main() {
	stack<int> stk;
	stk.push(1);
	stk.push(2);
	stk.push(3);

	// //print stack
	// while(!stk.empty()) {
	// 	cout<<stk.top()<<" ";
	// 	stk.pop();
	// }
	// cout<<endl;

	reverseStack(stk);

	//print stack
	while(!stk.empty()) {
		cout<<stk.top()<<" ";
		stk.pop();
	}
	cout<<endl;

	return 0;
}