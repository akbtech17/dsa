// https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
#include<bits/stdc++.h>
using namespace std;

// tc - linear
// sc - linear
vector<int> findSpan(vector<int> &stocks) {
	// find the next greater element in right side f each element
	vector<int> ngr(stocks.size(),-1);
	stack<int> stk;
	int n = stocks.size();
	for(int i=0;i<n;i++) {
		// pop the lements if small
		while(!stk.empty() and stocks[stk.top()]<=stocks[i])
			stk.pop();
		// form the ans
		ngr[i] = stk.empty() ? -1 : stk.top();
		// push the current element
		stk.push(i);
	}

	vector<int> span(n,1);
	for(int i=0;i<n;i++) {
		span[i] = i-ngr[i];
	}

	return span;
}

int main() {
	vector<int> stocks({100, 80, 60, 70, 60, 75, 85});
	vector<int> stocks2({10, 4, 5, 90, 120, 80});
	vector<int> span = findSpan(stocks2);

	for(auto el : span) cout<<el<<" ";
	return 0;
}