// 3_LargestRectangleHistogram_Stack.cpp
// https://leetcode.com/problems/largest-rectangle-in-histogram/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void printV(vector<int> v) {
		for(auto el : v) cout<<el<<" ";
		cout<<endl;
		return;
	}
	vector<int> NSR(vector<int> &arr) {
		vector<int> nsr(arr.size());
		int n = arr.size();
		stack<int> stk;
		for(int i=n-1; i>=0; i--) {
			// pop
			while(!stk.empty() and arr[stk.top()] >= arr[i])
				stk.pop();
			// ans
			nsr[i] = stk.empty() ? n : stk.top();
			// push
			stk.push(i);
		}
		// printV(nsr);
		return nsr;
	}

	vector<int> NSL(vector<int> &arr) {
		vector<int> nsl(arr.size());
		int n = arr.size();
		stack<int> stk;
		for(int i=0; i<n; i++) {
			// pop
			while(!stk.empty() and arr[stk.top()] >= arr[i])
				stk.pop();
			// ans
			nsl[i] = stk.empty() ? -1 : stk.top();
			// push
			stk.push(i);
		}
		// printV(nsl);
		return nsl;
	}
    int largestRectangleArea(vector<int> &heights) {
        vector<int> nsr = NSR(heights);
        vector<int> nsl = NSL(heights);

        int n = heights.size();
        int ans = 0;
        for(int i=0;i<n;i++) {
        	int h = heights[i];
        	int w = (nsr[i]-1)-(nsl[i]+1) + 1;
        	int area = h*w;
        	ans = max(ans,area);
        	// cout<<area<<" ";
        }

        return ans;
    }
};

int main() {
	Solution S;
	cout<<S.largestRectangleArea({2,1,5,6,2,3})<<endl;
	// cout<<S.largestRectangleArea({2,4})<<endl;

	return 0;
}