// 1_BinarySearch.cpp
// Problem Link - https://leetcode.com/problems/binary-search/
// Code Link - https://ide.codingblocks.com/s/635294
#include <bits/stdc++.h>
using namespace std;

// A1: Recursive
// TC: O(LogN)
// SC: O(LogN)
class Solution1 {
public:
    int recurse(vector<int>& nums, int key, int s, int e) {
        // base case
        if(s>e) return -1;

        // recursive cases
        int m = (s+e)/2;
        if(nums[m] == key) {
            return m;
        }
        else if(nums[m] > key) {
            return recurse(nums,key,s,m-1);
        }
        return recurse(nums,key,m+1,e);
    }
    int search(vector<int>& nums, int target) {
        return recurse(nums,target,0,nums.size()-1);
    }
};


// A2: Iterative
// TC: O(LogN)
// SC: O(1)
class Solution2 {
public:
    int search(vector<int>& nums, int target) {
    	int s = 0;
    	int e = nums.size()-1;

    	while(s<=e) {
    		int m = s + (e-s)/2;
    		if(nums[m] == target) return m;
    		else if (nums[m] < target) s = m+1;
    		else e = m-1;
    	}
        return -1;
    }
};

// A3: Using Inbuilt Function
// TC: O(LogN)
// SC: O(1)
class Solution3 {
public:
    int search(vector<int>& nums, int target) {
        int pos = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        return  pos == nums.size() ? -1 : nums[pos] != target ? -1 : pos;
    }
};