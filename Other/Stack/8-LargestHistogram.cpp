// 8-LargestHistogram.cpp
// https://leetcode.com/problems/largest-rectangle-in-histogram/

#include<bits/stdc++.h>
using namespace std;

vector<int> nsl(vector<int> v) {
	stack<int> stk;
	vector<int> ans(v.size(),-1);

	// we will iterate from left 
	for(int i=0;i<v.size();i++) {
		// pop if greater element
		while(!stk.empty() and v[stk.top()]>=v[i])
			stk.pop();
		// get ans
		ans[i] = stk.empty()? -1: stk.top();
		// push the curr element
		stk.push(i);
	}
	return ans;
}

vector<int> nsr(vector<int> v) {
	stack<int> stk;
	int n = v.size();
	vector<int> ans(v.size(),-1);

	// we will iterate from right
	for(int i=v.size()-1;i>=0;i--) {
		// pop if greater element
		while(!stk.empty() and v[stk.top()]>=v[i])
			stk.pop();
		// get ans
		ans[i] = stk.empty()? n: stk.top();
		// push the curr element
		stk.push(i);
	}
	return ans;
}

int largestRectangleArea(vector<int>& heights) {
	vector<int> nsR = nsr(heights); 
	vector<int> nsL = nsl(heights);
	int area = 0;
	int n = heights.size();
	for(int i=0;i<n;i++) {
		int carea = (nsR[i]-1)-(nsL[i]+1)+1;
		carea *= heights[i];
		area = max(carea,area);
	}

	return area;
}

int main() {
	vector<int> h1({2,1,5,6,2,3});
	vector<int> h2({2,4});

	cout<<largestRectangleArea(h1)<<endl;
	cout<<largestRectangleArea(h2)<<endl;

	return 0;
}