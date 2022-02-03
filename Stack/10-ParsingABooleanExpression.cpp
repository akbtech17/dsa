// 10-ParsingABooleanExpression.cpp
// https://leetcode.com/problems/parsing-a-boolean-expression/

#include<bits/stdc++.h>
using namespace std;

char evalNot(string exp) {
	return exp[0] == 't' ? 'f' : 't';
}

char evalAnd(string exp) {
	for(auto el : exp) 
		if(el == 'f') return 'f';

	return 't';
}

char evalOr(string exp) {
	for(auto el : exp) 
		if(el == 't') return 't';
	return 'f';
}

char evalExp(stack<char> &stk, char closing) {
	string exp = "";
	while(stk.top()!=closing) {
		exp.push_back(stk.top());
		stk.pop();
	}
	stk.pop();
	char op = stk.top();
	stk.pop();

	// cout<<exp<<" "<<op<<endl;

	switch(op) {
		case '!' : 
			return evalNot(exp);
			break;
		case '|' : 
			return evalOr(exp);
			break;
		case '&' : 
			return evalAnd(exp);
			break;
	}
	return 't';
}

bool parseBoolExpr(string exp) {

	int n = exp.size();
	stack<char> stk;


	for(int i=0;i<n;i++) {
		char ch = exp[i];
		char result;
		switch(ch) {
			case '(': 
			case '{': 
			case '[': 
			case '!': 
			case '&': 
			case '|':
			case 't':
			case 'f':
				stk.push(ch);
				break;
			case ')' :  
				result = evalExp(stk,'(');
				stk.push(result);
				break;
			case '}' :  
				result = evalExp(stk,'{');
				stk.push(result);
				break;
			case ']' :  
				result = evalExp(stk,'[');
				stk.push(result);
				break;
			case ',' : continue;
		}
	}

	return stk.top()=='t' ? true : false;
}

int main() {
	string exp1 = "!(f)";
	string exp2 = "|(f,t)";
	string exp3 = "&(t,f)";
	string exp4 = "|(&(t,f,t),!(t))";

	cout<<parseBoolExpr(exp1)<<endl;
	cout<<parseBoolExpr(exp2)<<endl;
	cout<<parseBoolExpr(exp3)<<endl;
	cout<<parseBoolExpr(exp4)<<endl;

	return 0;
}