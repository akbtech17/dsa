// 3_NextGreaterElementRight.cpp
// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1

#include<bits/stdc++.h>
using namespace std;

// Approach1 - Bruteforce
// TC - O(N^2)
// SC - O(1)
vector<int> ngr1(vector<int> v) {
	int n = v.size();
	for(int i=0; i<n; i++) {
		bool flag = false;
		for(int j=i+1; j<n; j++) {
			if(v[j] > v[i]) {
				v[i] = j;
				flag = true;
				break;
			}
		}
		if(!flag) v[i] = -1;
	}
	return v;
}


// Approach2 - Using Stack
// TC - O(N)
// SC - O(N)
vector<int> ngr2(vector<int> v) {
	stack<int> stk;
	vector<int> ans(v.size(),-1);

	// we will iterate from right
	for(int i=v.size()-1;i>=0;i--) {
		// pop if smaller element
		while(!stk.empty() and stk.top()<v[i])
			stk.pop();
		// get ans
		ans[i] = stk.empty()? -1: stk.top();
		// push the curr element
		stk.push(v[i]);
	}
	return ans;
}

int main() {
	vector<int> v({4, 5, 2, 25});
	vector<int> ans = ngr1(v);

	for(int i=0;i<v.size();i++) {
		cout<<v[i]<<":"<<ans[i]<<endl;
	}

	return 0;
}