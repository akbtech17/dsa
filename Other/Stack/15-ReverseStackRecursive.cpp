// 16-ReverseStackRecursive.cpp

#include<bits/stdc++.h>
using namespace std;

void pushAtBottom(stack<int> &stk, int el) {
	// base case
	if(stk.empty()) {
		stk.push(el);
		return;
	}

	// recurive case
	int tp = stk.top();
	stk.pop();
	pushAtBottom(stk,el);
	stk.push(tp);

	return;
}

void reverseStk(stack<int> &stk) {
	// base case
	if(stk.empty() or stk.size() == 1) return;
	// recurseive case

	// 1-remove the top element
	int tp = stk.top();
	stk.pop();
	// 2-reverse the remaing stk
	reverseStk(stk);
	// 3-push tp ele in the bottom of stk
	pushAtBottom(stk,tp);

	return;
}

int main() {
	stack<int> stk;
	stk.push(1);
	stk.push(2);
	stk.push(3);
	stk.push(4);

	reverseStk(stk);

	while(!stk.empty()) {
		cout<<stk.top()<<" ";
		stk.pop();
	}

	return 0;
}