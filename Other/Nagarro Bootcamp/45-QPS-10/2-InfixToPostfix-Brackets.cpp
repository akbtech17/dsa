// 2-InfixToPostfix-Brackets.cpp
// with brackets

#include <iostream>
#include <vector>
#include <stack>
using std::string;
using std::vector;
using std::cout;
using std::stack;

// we treat '(' as an operator with the lowest prec = -1

// Observations: 
// 1 - Order of operands are same in Infix and Postfix Expressions
// 2 - Order of operators are only different, 
//     they are in order of evaluation.

// Rules/Algo
// 1 - Iterate Infix Expression from Left to Right.
// 2 - if we encounter operands, directly add it to op string
// 3 - '(' add to stk
// 4 - ')' pop operators from stk, and add them to the postfix til you see '('
//      pop '('
// 5 - if we encounter operator, check
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
		else if(ch == '(') stk.push(ch);
		else if(ch == ')') {
			while(stk.top()!='(') {
				char top = stk.top();
				postfix.push_back(string(1, top));
				stk.pop();
			}
			stk.pop();    // pop the opening parenthesis
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
	// vector<string> postfix = infixToPostfix("(a+b)*((c+d)/e)*f");
	// vector<string> postfix = infixToPostfix("(-(a+b))");
	vector<string> postfix = infixToPostfix("(a+(-b))");

	for(string item : postfix) cout<<item;
	return 0;
}



// Problems in this code

// 1 - It can only deal with digits, not numbers
//     1+2 is OK
//     12+34 will not work

// 2 - (A+-B) will alos create an issue here, will not work for unary expressions

// 3 - -(A+B) will also not work