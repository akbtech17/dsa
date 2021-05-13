// 2-BalancedParenthesis.cpp
#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string s) {
	stack<char> stk;
	map<char,char> mp;
	mp.insert({'}','{'});
	mp.insert({']','['});
	mp.insert({')','('});

	for(int i=0;i<s.size();i++) {
		char ch = s[i];
		if(ch=='(' or ch == '{' or ch=='[') {
			stk.push(ch);
		}
		else if(ch==')' or ch == '}' or ch==']') {
			if(stk.empty() == true) return false;
			if(stk.top() == mp[ch]) {
				stk.pop();
				continue;
			}
			return false;
		}
		else {
			continue;
		}
	}
	if(stk.empty()) return true;
	return false;
}

bool isBalanced2(string s) {
	stack<char> stk;
	for(int i=0;i<s.size();i++) {
		char ch = s[i];
		switch(ch) {
			case '(': 
				stk.push(ch);
				break;
			case '{': 
				stk.push(ch);
				break;
			case '[': 
				stk.push(ch);
				break;
			case ')': 
				if(!stk.empty() and stk.top() != '(') return false;
				else stk.pop();
				break;
			case '}': 
				if(!stk.empty() and stk.top() != '{') return false;
				else stk.pop();
				break;
			case ']': 
				if(!stk.empty() and stk.top() != '[') return false;
				else stk.pop();
				break;
		}
	}
	if(stk.empty())return true;
	return false;
}

void tell(string s) {
	if(isBalanced2(s)) cout<<s<<" is balanced\n";
	else cout<<s<<" is not balanced\n";
	return;
}

int main() {
	string s1 = "()";
	string s2 = "{(a)b}";
	string s3 = "{(a)b}}";
	tell(s1);
	tell(s2);
	tell(s3);
	return 0;
}