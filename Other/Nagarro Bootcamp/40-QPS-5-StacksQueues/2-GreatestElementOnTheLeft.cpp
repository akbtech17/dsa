// 2-GreatestElementOnTheLeft.cpp
#include<bits/stdc++.h>
using namespace std;

vector<int> ngl(vector<int> &nums) {
	vector<int> ans(nums.size(),-1);
	int n = nums.size();
	stack<int> stk;

	for(int i=0;i<n;i++) {
		while(!stk.empty() and stk.top()<=nums[i])
			stk.pop();
		ans[i] = stk.empty()?-1:stk.top();
		stk.push(nums[i]);
	}

	return ans;
}

int main() {
	vector<int> nums({8,2,7,4,3,6});
	vector<int> ans = ngl(nums);

	for(auto el : ans) cout<<el<<" ";

	return 0;
}