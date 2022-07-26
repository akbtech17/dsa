// 6_UpperBound.cpp
// Problem Link - https://www.geeksforgeeks.org/implementing-upper_bound-and-lower_bound-in-c/
// Code Link - https://ide.codingblocks.com/s/639502
#include <bits/stdc++.h>
using namespace std;

// A1: Iterative
// TC: O(LogN) 
// SC: O(1)
class Solution1 {
public:
    int upper_bound(int s, int e, int key, vector<int>& nums) {
        int ans = -1;
        while(s<=e) {
            int m = s+(e-s)/2;
            if(nums[m] <= key) {
                ans = m;
                s = m+1;
            }
            else e = m-1;
        }
        return ans == -1 ? 0 : ans+1;
    }
    int findUpperBound(vector<int> nums, int target) {
        return upper_bound(0,nums.size(),target,nums);
    }
};

// A2: Inbuilt Function
// TC: O(LogN) 
// SC: O(1)
class Solution2 {
public:
    int findUpperBound(vector<int> nums, int target) {
        int pos = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
        return pos;
    }
};

int main() {
	Solution1 S;
	cout<<S.findUpperBound({1,2,3,4,5,5,5,5,9,10},6)<<endl;
    cout<<S.findUpperBound({0,2,3,4,5,5,5,5,9,10},1)<<endl;
    cout<<S.findUpperBound({0,2,3,4,5,5,5,5,9,10},5)<<endl;
    cout<<S.findUpperBound({0,2,3,4,5,5,5,5,9,10},0)<<endl;

    Solution2 S2;
    cout<<S2.findUpperBound({1,2,3,4,5,5,5,5,9,10},6)<<endl;
    cout<<S2.findUpperBound({0,2,3,4,5,5,5,5,9,10},1)<<endl;
    cout<<S2.findUpperBound({0,2,3,4,5,5,5,5,9,10},5)<<endl;
    cout<<S2.findUpperBound({0,2,3,4,5,5,5,5,9,10},0)<<endl;

	return 0;
}

