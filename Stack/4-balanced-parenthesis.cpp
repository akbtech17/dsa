// 4 - balanced - parenthesis
#include <iostream>
#include <vector>
#include <stack>
using namespace std;


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