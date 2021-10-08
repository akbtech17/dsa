// 3-EvaluatingBooleanExpression
#include<bits/stdc++.h>
using namespace std;

char evalAnd(string s) {
	for(auto ch : s) {
		if(ch == 'f') return 'f';
	}
	return 't';
}
char evalOr(string s) {
	for(auto ch : s) {
		if(ch == 't') return 't';
	}
	return 'f';
}
char evalNot(string s) {
	return s[0]!='t'?'t':'f';
}

void evalInnerExp(stack<char> &stk) {
	string  inner_exp = "";
	while(!stk.empty()) {
		char ch = stk.top();
		stk.pop();
		if(ch == '(') {
			char op = stk.top();
			stk.pop();

			switch(op) {
				case '&' : stk.push(evalAnd(inner_exp)); break;
				case '|' : stk.push(evalOr(inner_exp)); break;
				case '!' : stk.push(evalNot(inner_exp)); break;
			} 
			break;
		}
		else {
			inner_exp += ch;
		}
	}
	return;
}

bool evaluateBoolExpr(string expr) {
	stack<char> stk;
	for(int i=0;i<expr.size();i++) {
		char ch = expr[i];
		if(ch == ')') {
			//build, evaluate the inner exp
			evalInnerExp(stk);
		}
		else if(ch == ',') {
			//do nothing...
			continue;
		}
		else {
			 //ch = &, |, !, T, F, (
			 stk.push(ch); 
		}
	}
	//if stk top is T return true, if it is f return false
	return stk.top()=='t';
}
// |(&(t,f,t),!(t))
// |(&(t,f,t),!(f))
int main() {
	string expr;
	cin>>expr; //no space in input
	// getline(cin,expr);

	cout<<expr<<" : "<<evaluateBoolExpr(expr);
	return 0;
}