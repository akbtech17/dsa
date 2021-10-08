// 7_OddRepeat.cpp
// https://www.codechef.com/problems/REPEAT

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> nums) {
	int ans = -1;
	map<int,long long int> mp;

	for(auto el : nums) mp[el]++;
	for(auto p : mp) {
		if(p.second % 2 == 0) return p.first;
	}
	return ans;
}

int32_t main() {
	// cout<<solve({1,2,2,2,3,1})<<endl;
	// cout<<solve({2,4,6,8,10,12,14})<<endl;
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i=0; i<n; i++) cin>>nums[i];
	cout<<solve(nums);
	return 0;
}