// 3-Basic_Calculator.cpp
// https://leetcode.com/problems/basic-calculator/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <ctype.h>
using std::cout;
using std::string;
using std::vector;
using std::stack;
using std::endl;


class Solution {
public:
	bool isOperator(char ch) {
		if(ch == '+' or ch == '-' or ch =='*' or ch == '/') return true;
		return false;
	}

	int prec(char ch) {
		if(ch == '+' or ch == '-') return 1;
		if(ch == '*' or ch == '/') return 2;
		return 0;
	}

	vector<string> inToPos(string infix) {
		// stack, vector<string> to store ans
		stack<char> stk;
		vector<string> postfix;

		// iterate infix from left to right
		int n = infix.size();
		for(int i=0; i<n; i++) {
			char ch = infix[i];
			// 1 - 'Operator'
			if(isOperator(ch)) {
				// pop all operators greater equal to curr operator
				while(!stk.empty() and prec(stk.top()) >= prec(ch)) {
					char tp = stk.top();
					stk.pop();
					postfix.push_back(string(1,tp));
				}
				// now push the current operator in stk
				stk.push(ch);
			}
			// 2 - '('
			else if(ch == '(') stk.push(ch);
			// 3 - ')'
			else if(ch == ')') {
				// while we dont encounter '(' 
				// pop and add el to ans
				while(!stk.empty() and stk.top()!='(') {
					char tp = stk.top();
					stk.pop();
					postfix.push_back(string(1,tp));
				}
				// pop the opening parenthesis
				stk.pop();
			}
			// 4 - 'Space'
			else if (ch == ' ') continue;
			// 5 - 'Operands'
			else {
				// extract full operand
				string temp = string(1,ch);
				while((i+1)<n and isdigit(infix[i+1])) {
					temp += infix[i+1];
					i++;
				}
				postfix.push_back(temp);
			}
		}

		while(!stk.empty()) {
			char tp = stk.top();
			postfix.push_back(string(1, tp));
			stk.pop();
		}
		return postfix;
	} 

	void printVS(vector<string> v) {
		// cout<<v.size();
		for(auto el : v) cout<<el<<" ";
		cout<<endl;
		return;
	}

	void printStk(stack<int> stk) {
		// cout<<v.size();
		while(!stk.empty()) {
			cout<<stk.top()<<"::";
			stk.pop();
		}
		cout<<endl;
		return;
	}

	int evalPos(vector<string> postfix) {
		// stack to hold values
		// printVS(postfix);
		stack<int> vals;	
		int n = postfix.size();
		for(int i=0; i<n; i++) {
			string cs = postfix[i];
			// 1 - if the cs is Operator
			if(cs.size() == 1 and !(cs>="0" and cs<="9")) {
				if(vals.size() >= 2) {
					int n2 = vals.top();
					vals.pop();
					int n1 = vals.top();
					vals.pop();

					switch(cs[0]) {
						case '+' : 
							vals.push(n1+n2);
							break;
						case '-' : 
							vals.push(n1-n2);
							break;
						case '*' : 
							vals.push(n1*n2);
							break;
						case '/' : 
							vals.push(n1/n2);
							break;
					}
				}
				else {
					int n1 = vals.top();
					vals.pop();

					switch(cs[0]) {
						case '+' : 
							vals.push(n1);
							break;
						case '-' : 
							vals.push(-n1);
							break;
					}
				}
			}
			// 2 - else Operand
			else {
				vals.push(stoi(cs));
			}
			// printStk(vals);
		}
		return vals.top();
	}
	
    int calculate(string s) {
    	// cout<<s;
        return evalPos(inToPos(s));
    }
};

int main() {
	Solution S;
	cout<<S.calculate(" 20-1 + 2 ")<<endl;
	cout<<S.calculate("1 + 1")<<endl;
	cout<<S.calculate("(1+(4+5+2)-3)+(6+8)")<<endl;
	cout<<S.calculate("(2+(-3))")<<endl;
	cout<<S.calculate("3+5/2")<<endl;

	return 0;
}