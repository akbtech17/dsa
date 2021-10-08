// 9-BalancedParenthesis.cpp
// https://leetcode.com/problems/valid-parentheses/

#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
 	stack<char> stk;
 	int n = s.size();
 	
 	for(int i=0;i<n;i++) {
 		char ch = s[i];

 		switch(ch) {
 			case '(':
 			case '{':
 			case '[': 
	 			stk.push(ch);
	 			break;

 			case ')': 
	 			if(!stk.empty() and stk.top() == '(')
	 				stk.pop();
	 			else return false;
	 			break;

	 		case '}': 
	 			if(!stk.empty() and stk.top() == '{')
	 				stk.pop();
	 			else return false;
	 			break;

	 		case ']': 
	 			if(!stk.empty() and stk.top() == '[')
	 				stk.pop();
	 			else return false;
	 			break;

	 		default: 
	 			return false;
	 			break;
 		}
 	}

 	return stk.empty() ? true : false;
}

int main() {
	string s1 = "()";  
	string s2 = "()[]{}";  
	string s3 = "(]";  

	cout<<isValid(s1)<<endl;
	cout<<isValid(s2)<<endl;
	cout<<isValid(s3)<<endl;

	return 0;
}