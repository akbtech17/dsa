// 3 - reverse - stack - using - recursion.cpp
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void insertElementAtBottom(int element, stack<int> &stk) {
	if (stk.size() == 0) {
		stk.push(element);
		return;
	}
	int curr_element = stk.top();
	stk.pop();
	insertElementAtBottom(element, stk);
	stk.push(curr_element);
	return;
}

void reverseStack(stack<int> &stk) {
	if (stk.size() == 0 or stk.size() == 1) return;
	int curr_element = stk.top();
	stk.pop();
	reverseStack(stk);
	insertElementAtBottom(curr_element, stk);
	return;
}



int main() {
	stack<int> stk;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int data;
		cin >> data;
		stk.push(data);
	}
	reverseStack(stk);
	while (!stk.empty()) {
		cout << stk.top() << endl;
		stk.pop();
	}
	return 0;
}