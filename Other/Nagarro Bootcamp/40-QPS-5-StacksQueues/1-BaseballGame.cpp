// 1-BaseballGame.cpp
// https://leetcode.com/problems/baseball-game/

#include<bits/stdc++.h>
using namespace std;

int calPoints(vector<string>& ops) {
	stack<int> stk;
	int n = ops.size();

	for(int i=0;i<n;i++) {
		string str = ops[i];
		if(str == "C") {
			stk.pop();
		}
		else if(str == "D") {
			stk.push(stk.top()*2);
		}
		else if(str == "+") {
			int temp = stk.top();
			stk.pop();
			int temp2 = stk.top();
			stk.push(temp);
			stk.push(temp+temp2);
		}
		else {
			stk.push(stoi(str));
		}
	}

	int ans = 0;

	while(!stk.empty()) {
		ans += stk.top();
		stk.pop();
	}

	return ans;
}

int main() {
		
}