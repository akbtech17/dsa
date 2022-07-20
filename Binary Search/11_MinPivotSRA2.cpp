// 11_MinPivotSRA2.cpp
// Problem Link - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
// Code Link - https://ide.codingblocks.com/s/661680
#include <bits/stdc++.h>
using namespace std;

// Approach: Using the MinPivot Approach
// TC: O(LogN) 
// SC: O(LogN)
class Solution {
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
        // if standing on the contant line, we dont know where to search!
        if(nums[s] == nums[e] and nums[s] == nums[m]) return minPivotIdx(nums,s+1,e-1);
        
        // if standing on the second line, search in the first...
        if(nums[m]<=nums[e]) return minPivotIdx(nums,s,m-1);   
        // else in the second
        return minPivotIdx(nums,m+1,e);
    }
    int findMin(vector<int> &nums) {
        int ans_idx = minPivotIdx(nums,0,nums.size()-1);
        // -1 means, arr is not rotated and ans is the first element
        if(ans_idx == -1) {
            int i=0;
            while(i<nums.size() and nums[i] == nums[0]) i++;
            return i>=nums.size() ? 
                nums[0] :
                nums[i]<nums[0] ? nums[i] : nums[0];
        }
        return nums[ans_idx];
    }
};