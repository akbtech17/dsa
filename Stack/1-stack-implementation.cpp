// 1 - stack - implementation.cpp
#include <iostream>
#include <vector>
using namespace std;

template<typename T >

class Stack {
private:
	vector<T> stk;
public:
	Stack() {
	}
	void push(T data) {
		stk.push_back(data);
		return;
	}
	void pop() {
		if (!empty())stk.pop_back();
		return;
	}
	T top() {
		if (stk.size() != 0) {
			return stk[stk.size() - 1];
		}
		return -1;
	}
	bool empty() {
		return stk.size() == 0;
	}
	T size() {
		return stk.size();
	}
};

int main() {
	Stack<char> stk;
	for (int i = 0; i <= 5; ++i)
	{
		stk.push(i + 'a');
	}

	while (!stk.empty()) {
		cout << stk.top() << endl;
		stk.pop();
	}

	return 0;
}