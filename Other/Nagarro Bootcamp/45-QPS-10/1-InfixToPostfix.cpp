// 1-InfixToPostfix.cpp
// without brackets
#include <iostream>
#include <vector>
#include <stack>
using std::string;
using std::vector;
using std::cout;
using std::stack;

// Observations: 
// 1 - Order of operands are same in Infix and Postfix Expressions
// 2 - Order of operators are only different, 
//     they are in order of evaluation.

// Rules/Algo
// 1 - Iterate Infix Expression from Left to Right.
// 2 - if we encounter operands, directly add it to op string
// 3 - if we encounter operator, check
//     if the stk is empty or stk.top op prec < curr op prec
//         Yes - directly push the curr op onto stk
//         No - Pop el of the stk and add to the op string, until the
//              stk is either empty of prec gets below than the curr op.


bool isOperator(char ch) {
	if(ch == '+' or ch == '-' or ch == '*' or ch == '/')
		return true;
	return false;
}

int prec(char op) {
	if(op == '+' or op == '-') return 1;
	if(op == '*' or op == '/') return 2;
	return -1;
}

vector<string> infixToPostfix(string infix) {
	vector<string> postfix;
	stack<char> stk;

	for(int i=0;i<infix.length(); i++) {
		char ch = infix[i];
		if(isOperator(ch)) {
			while(!stk.empty() and prec(ch) <= prec(stk.top())) {
				char top = stk.top();
				postfix.push_back(string(1, top));
				stk.pop();
			}
			stk.push(ch);
		}
		else {
			postfix.push_back(string(1, ch));
		}
	}

	while(!stk.empty()) {
		char top = stk.top();
		postfix.push_back(string(1, top));
		stk.pop();
	}

	return postfix;
}

int main() {
	vector<string> postfix = infixToPostfix("a+b*c+d/e*f");

	for(string item : postfix) cout<<item;
	return 0;
}