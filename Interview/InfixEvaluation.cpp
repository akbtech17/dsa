// InfixEvaluation.cpp
#include<bits/stdc++.h>
using namespace std;

int precedence(char ch) {
	if(ch =='+' or ch=='-') return 1;
	else if (ch =='*' or ch=='/') return 2;
	return 0;
}

int applyOperator(int a, int b, char op) {
	switch(op) {
		case '+' :
			return a+b;	
		case '-' :	
			return a-b;
		case '*' :	
			return a*b;
		case '/' :	
			return a/b;
	}

	return 0;
}

int eval(string s) {
	stack<int> nums;
	stack<int> op;

	for(int i=0;i<s.size();i++) {
		char ch = s[i];
		// if space

		// if opening bracket
		// if number
		// if closing
		// else
	}
}

int main() {

}