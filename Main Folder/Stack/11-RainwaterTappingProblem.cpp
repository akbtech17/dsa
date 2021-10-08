// 11-RainwaterTappingProblem.cpp
// https://leetcode.com/problems/trapping-rain-water/

#include<bits/stdc++.h>
#define pb push_back
#define vi vector<int>
using namespace std;

int trap(vector<int>& height) {
	int n = height.size();
	vi gL(n,0), gR(n,0);
	int mx = 0;

	for(int i=0;i<n;i++) {
		gL[i] = mx;
		mx = max(mx,height[i]);
	}

	mx = 0;
	for(int i=n-1;i>=0;i--) {
		gR[i] = mx;
		mx = max(mx,height[i]);
	}

	int ans = 0;
	for(int i=0;i<n;i++) {
		int ch = min(gL[i],gR[i]);
		if(ch>height[i]) {
			ans += ch-height[i];
		}
	}

	return ans;
}

int main() {
	vi height({0,1,0,2,1,0,1,3,2,1,2,1});
	vi height2({4,2,0,3,2,5});
	cout<<trap(height)<<endl;
	cout<<trap(height2)<<endl;

	return 0;
}

