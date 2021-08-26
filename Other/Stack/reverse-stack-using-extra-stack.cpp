// 2 - reverse - stack - using - extra - stack.cpp
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//tc -> n square
//sc -> n (extra stack)
void transferElement(int n, stack<int> &src, stack<int> &dest) {
	while (n--) {
		dest.push(src.top());
		src.pop();
	}
	return;
}

void reverseStack1(stack<int> &stk1) {
	stack<int> stk2;
	int n = stk1.size() - 1;
	while (n > 0) {
		int top = stk1.top();
		stk1.pop();
		transferElement(n, stk1, stk2);
		stk1.push(top);
		transferElement(n, stk2, stk1);
		n--;
	}
	return ;
}

//tc -> n
//sc -> n (extra stack)
void reverseStack2(stack<int> &stk1) {
	stack<int> stk2;
	while (!stk1.empty()) {
		stk2.push(stk1.top());
		stk1.pop();
	}
	swap(stk1, stk2);
	return ;
}

void reverseStack3(stack<int> &stk) {
	if (stk.size() == 0 or stk.size() == 1) return;
	int top_element = stk.top();
	stk.pop();

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
	reverseStack1(stk);
	while (!stk.empty()) {
		cout << stk.top() << endl;
		stk.pop();
	}
	return 0;
}