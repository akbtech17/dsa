// 9_MaxPivotElementInSortedRotatedArray.cpp
// Problem Link - https://www.geeksforgeeks.org/maximum-element-in-a-sorted-and-rotated-array/
// Code Link - https://ide.codingblocks.com/s/639483
#include <bits/stdc++.h>
using namespace std;

// Approach: Recursion
// TC: O(LogN) 
// SC: O(LogN)
class Solution {
public:
    int maxPivotIdx(vector<int> &nums, int s, int e) {
        // if no element present, return -1
        if(s>e) return -1;

        // find mid
        int m = s+(e-s)/2;

        // check if we are standing on/near the pivot
        if(m<e and nums[m]>nums[m+1]) return m;
        if(m>s and nums[m-1]>nums[m]) return m-1;

        // now on which part to check ??
        // if standing on the first line, search in the second...
        if(nums[s]<=nums[m]) return maxPivotIdx(nums,m+1,e);   
        // else in the first
        return maxPivotIdx(nums,s,m-1);
    }
    int findMax(vector<int> nums) {
        int ans_idx = maxPivotIdx(nums,0,nums.size()-1);
        // -1 means, arr is not rotated and ans is the last element
        if(ans_idx == -1) return nums[nums.size()-1];
        return nums[ans_idx];
    }
};

int main() {
	Solution S;
	cout<<S.findMax({3,4,5,1,2})<<endl;
	cout<<S.findMax({4,5,6,7,0,1,2})<<endl;
    cout<<S.findMax({11,13,15,17})<<endl;
	cout<<S.findMax({1,2,3})<<endl;

	return 0;
}

