// 4_MinShiftsToBalanceBrackets.cpp
// https://www.geeksforgeeks.org/cost-balance-parantheses/#
#include <iostream>
#include <stack>
#include <vector>
using std::cout;
using std::endl;
using std::stack;
using std::string;
using std::pair;
using std::vector;
using std::swap;
using std::min;

bool isBalanced(string str) {
	stack<char> stk;
	for(int i=0;i<str.size();i++) {
		char ch = str[i];
		if(ch == '{') stk.push('{');
		else {
			if (stk.empty() or stk.top() != '{') return false;
			stk.pop();
		}
	}
	return stk.empty();
}

pair<int,int> countOpeningAndClosing(string str) {
	int op = 0;
	int cl = 0;

	for(auto el : str) {
		if(el == '{') op++;
		if(el == '}') cl++;
	}

	return {op,cl};
}

void solve(string str) {
	int n = str.size();
	pair<int,int> cnt = countOpeningAndClosing(str);
	int opening = cnt.first;
	int closing = cnt.second;
	if(opening != closing) {
		cout<<"NOT POSSIBLE";
		return;
	}
	int ccl = 0, cop = 0;
	// vector<int> temp(n,n);
	// int prev = n;
	// for(int i=n-1;i>=0;i--) {
	// 	temp[i] = prev;
	// 	if(str[i] == '{') prev = i;
	// }

	// // for(auto el : temp) cout<<el<<" ";
	// // cout<<endl;


	int cost = 0;
	for(int i=0;i<n;i++) {
		// update the flags;
		char ch = str[i];
		if(ch == '{') cop++;
		if(ch == '}') ccl++;

		if(cop>=ccl) {
			cout<<cop<<" "<<ccl<<endl;
			continue;
		}

		// find the index of next opening par
		int idx1 = i+1;
		for(;idx1<n;idx1++) {
			if(str[idx1] == '{') break;
		}

		int idx2 = n-1;
		for(;idx1>=0;idx2--) {
			if(str[idx2] == '{') break;
		}
		idx2 = n- idx2;
		idx2+=i;

		int idx = min(idx1,idx2);
		int curr_cost = idx - i + 1;

		swap(str[i],str[idx]);
		cop += 1;
		ccl -= 1;
		cout<<cop<<" "<<ccl<<" "<<curr_cost<<endl;
		cost += curr_cost;
	}
	cout<<cost;
	return;
}

int main() {

	solve("}{");
	cout<<endl;
	solve("}}{{");
	cout<<endl;
	solve("}}}{{{");
	cout<<endl;

	return 0;
}

