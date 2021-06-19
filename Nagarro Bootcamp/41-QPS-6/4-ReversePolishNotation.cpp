// 4-ReversePolishNotation.cpp
// https://leetcode.com/problems/evaluate-reverse-polish-notation/
// PostFix

#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<stdlib.h>

#define pb push_back
#define vs vector<string>
using std::cout;
using std::vector;
using std::string;
using std::endl;
using std::stack;
using namespace std;

int evalRPN(vector<string>& tokens) {
   	  stack<int> vals;
   	  int n = tokens.size();
   	  for(int i=0;i<n;i++) {
   	  	string cs = tokens[i];
   	  	if(cs.length() == 1 and !(cs[0]-'0'>=0 and cs[0]-'0'<=9)) {
   	  		int num1, num2;
   	  		switch(cs[0]) {
   	  		case '+' : 
   	  			num1 = vals.top();
   	  			vals.pop();
   	  			num2 = vals.top();
   	  			vals.pop();
   	  			vals.push(num1+num2);
   	  			break;
   	  		case '-' :
   	  			num1 = vals.top();
   	  			vals.pop();
   	  			num2 = vals.top();
   	  			vals.pop();
   	  			vals.push(num2-num1);
   	  			break;
   	  		case '/' :
   	  			num1 = vals.top();
   	  			vals.pop();
   	  			num2 = vals.top();
   	  			vals.pop();
   	  			vals.push(num2/num1);
   	  			break;
   	  		case '*' :
   	  			num1 = vals.top();
   	  			vals.pop();
   	  			num2 = vals.top();
   	  			vals.pop();
   	  			vals.push(num2*num1);
   	  			break;
   	  		}
   	  	}
   	  	else {
   	  		vals.push(stoi(cs));
   	  	}
   	  	
   	  }

   	  return vals.top();
}

int main() {
	vs tokens({"4","13","5","/","+"});
	cout<<evalRPN(tokens)<<endl;
	return 0;
}