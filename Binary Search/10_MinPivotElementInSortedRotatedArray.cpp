// 10_MinPivotElementInSortedRotatedArray.cpp
// Problem Link - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Code Link - https://ide.codingblocks.com/s/639485
#include <bits/stdc++.h>
using namespace std;

// A1: Using the MaxPivot Approach
// TC: O(LogN) 
// SC: O(LogN)
class Solution1 {
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
    int findMin(vector<int> nums) {
        int ans_idx = maxPivotIdx(nums,0,nums.size()-1);
        // -1 means, arr is not rotated and ans is the first element
        if(ans_idx == -1) return nums[0];
        return nums[ans_idx+1];
    }
};

// A2: Using the MinPivot Approach
// TC: O(LogN) 
// SC: O(LogN)
class Solution2 {
public:
    int minPivotIdx(vector<int> &nums, int s, int e) {
        // if no element present, return -1
        if(s>e) return -1;

        // find mid
        int m = s+(e-s)/2;

        // check if we are standing on/near the pivot
        if(m<e and nums[m]>nums[m+1]) return m+1;
        if(m>s and nums[m-1]>nums[m]) return m;

        // now on which part to check ??
        // if standing on the second line, search in the first...
        if(nums[m]<=nums[e]) return minPivotIdx(nums,s,m-1);   
        // else in the second
        return minPivotIdx(nums,m+1,e);
    }
    int findMin(vector<int> nums) {
        int ans_idx = minPivotIdx(nums,0,nums.size()-1);
        // -1 means, arr is not rotated and ans is the first element
        if(ans_idx == -1) return nums[0];
        return nums[ans_idx];
    }
};

int main() {
	Solution2 S;
	cout<<S.findMin({3,4,5,1,2})<<endl;
	cout<<S.findMin({4,5,6,7,0,1,2})<<endl;
	cout<<S.findMin({11,13,15,17})<<endl;

	return 0;
}

