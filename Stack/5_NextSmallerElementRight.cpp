// 5-NextSmallerElementRight.cpp
#include<bits/stdc++.h>
using namespace std;

// next smaller element in right
// tc - linear
// sc - linear
vector<int> nsr(vector<int> v) {
	stack<int> stk;
	vector<int> ans(v.size(),-1);

	// we will iterate from right
	for(int i=v.size()-1;i>=0;i--) {
		// pop if greater element
		while(!stk.empty() and stk.top()>v[i])
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
	vector<int> ans = nsr(v);

	for(int i=0;i<v.size();i++) {
		cout<<v[i]<<":"<<ans[i]<<endl;
	}

	return 0;
}