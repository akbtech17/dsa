// 5_LowerBound.cpp
// Problem Link - https://www.geeksforgeeks.org/implementing-upper_bound-and-lower_bound-in-c/
// Code Link - https://ide.codingblocks.com/s/639501
#include <bits/stdc++.h>
using namespace std;

// A1: Recursive
// TC: O(LogN) 
// SC: O(1)
class Solution1 {
public:
    int lower_bound(int s, int N, int key, vector<int>& nums) {
        // N = size, not size-1
        // s<N
        while(s<N) {
        	int m = s+(N-s)/2;
        	if(nums[m]>=key) N = m; // we have to consider m, as it can be lower bound
        	else s = m+1;
        }
        return s;
    }
    int findLowerBound(vector<int> nums, int target) {
        return lower_bound(0,nums.size(),target,nums);
    }
};


// A2: Inbuilt Function
// TC: O(LogN) 
// SC: O(1)
class Solution2 {
public:
    int findLowerBound(vector<int> nums, int target) {
        int pos = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        return pos;
    }
};

int main() {
	Solution1 S;
	cout<<S.findLowerBound({1,2,3,4,5,5,5,5,9,10},6)<<endl;
    cout<<S.findLowerBound({0,2,3,4,5,5,5,5,9,10},1)<<endl;
    cout<<S.findLowerBound({0,2,3,4,5,5,5,5,9,10},5)<<endl;

    Solution2 S2;
    cout<<S2.findLowerBound({1,2,3,4,5,5,5,5,9,10},6)<<endl;
    cout<<S2.findLowerBound({0,2,3,4,5,5,5,5,9,10},1)<<endl;
    cout<<S2.findLowerBound({0,2,3,4,5,5,5,5,9,10},5)<<endl;
    cout<<S2.findLowerBound({0,2,3,4,5,5,5,5,9,10},11)<<endl;
    cout<<S2.findLowerBound({0,2,3,4,5,5,5,5,9,10},-1)<<endl;

	return 0;
}

