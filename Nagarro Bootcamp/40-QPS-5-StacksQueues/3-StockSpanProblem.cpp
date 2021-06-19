// 3-StockSpanProblem.cpp
#include<bits/stdc++.h>
using namespace std;

vector<int> ngl(vector<int> &nums) {
	vector<int> ans(nums.size(),-1);
	int n = nums.size();
	stack<int> stk;

	for(int i=0;i<n;i++) {
		while(!stk.empty() and nums[stk.top()]<=nums[i])
			stk.pop();
		ans[i] = stk.empty()?1:i-stk.top();
		stk.push(i);
	}

	return ans;
}

int main() {
	vector<int> nums({100, 80, 60, 70, 60, 75, 85});
	vector<int> ans = ngl(nums);

	for(auto el : ans) cout<<el<<" ";

	return 0;
}