// 4_RedundantParenthesis_Stack.cpp
// https://www.geeksforgeeks.org/expression-contains-redundant-bracket-not/
// https://www.interviewbit.com/problems/redundant-braces/


// Input: 
// ((a+b))
// (a+(b)/c)
// (a+b*(c-d))
// Output: 
// Yes
// Yes
// No

#include <bits/stdc++.h>
using namespace std;

// to remove space from the string
// auto it = remove(s.begin(),s.end(),' ');
// s.erase(it,s.end());


// there must be atleast one operator per set of parenthesis
// then the set of parenthesis are not redundant..

bool isOperator(char ch) {
	if(ch == '+' or ch == '-' or ch =='*' or ch == '/') 
		return true;
	return false;
}

bool isRedundant(string expr) {
	stack<char> stk;
	int n = expr.size();

	for(int i=0; i<n; i++) {
		char ch = expr[i];
		if(ch == ')') {
			bool operator_mila = false;
			while(stk.top()!='(') {
				if(isOperator(stk.top())) operator_mila = true;
				stk.pop();
			}
			stk.pop();
			if(!operator_mila) return true;
		}
		else stk.push(ch);
	}
	return false;
}


int main() {
	cout<<isRedundant("((a+b))")<<endl;
	cout<<isRedundant("(a+(b)/c)")<<endl;
	cout<<isRedundant("(a+b*(c-d))")<<endl;
	return 0;
}