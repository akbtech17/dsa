// 3_SearchInsertPosition.cpp
// Problem Link - https://leetcode.com/problems/search-insert-position/
// Code Link - https://ide.codingblocks.com/s/635296
#include <bits/stdc++.h>
using namespace std;

// A1: Iterative
// TC: O(N)
// SC: O(1)
class Solution1 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int idx = 0;
        while(idx<nums.size() and nums[idx]<target ) {
            idx++;
        }
        
        return idx;
    }
};

// A2: Iterative
// TC: O(LogN)
// SC: O(1)
class Solution2 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        
        while(s<=e) {
            int m = s+(e-s)/2;
            if(nums[m]<target) s = m+1;
            else e = m-1;
        }
      
        return s;
    }
};

// A3: Inbuilt Function
// TC: O(LogN)
// SC: O(1)
class Solution3 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int pos = lower_bound(nums.begin(), nums.end(), target)-nums.begin();
        return pos;
    }
};