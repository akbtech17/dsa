// fw4 - maximum - of - all - subarrays.cpp
#include <bits/stdc++.h>
#define vi vector<int> 
#define pb push_back
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	int s = 0;
	int e = 0;

	vi ans;
	list<int> l;
	while(e<nums.size()) {
		// include current calcs
		while(l.size()>0 and l.back(n)<nums[e]) l.pop_back();
		l.push_front(nums[e]);

		int ws = e-s+1;
		// window sizze not reached
		if(ws<k) {
			e++;
		}	
		// window size reached
		else if(ws == k) {
			ans.pb(l.front());

			if(!l.empty() and l.front() == nums[s]) 
				l.pop_front();
			s++;
			e++;
		}
	}

	return ans;
}

int main() {
	vi nums({1,3,-1,-3,5,3,6,7});
	int k = 3;

	vector<int> ans = maxSlidingWindow(nums,k)	;

 	for(auto el : ans) cout<<el<<" ";

	return 0;
}