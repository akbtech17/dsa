// 5_TwoSum2.cpp
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// https://ide.codingblocks.com/s/635354

#include <bits/stdc++.h>
using namespace std;

// Approach 1 - Bruteforce (TLE)
// TC - O(N^2)
// SC - O(1)
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0; i<n; i++) {
        	for(int j=0; j<n; j++) {
        		if(i != j and nums[i]+nums[j] == target) 
        			return vector<int>({i+1,j+1});
        	}
        }
        return vector<int>({});
    }
};

// Approach 2 - 2 Pointers
// TC - O(N)
// SC - O(1)
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        while(s<=e) {
            int csum = nums[s]+nums[e];
            if(csum == target) return vector<int>({s+1,e+1});
            else if(csum < target) s++;
            else e--;
        }
        return vector<int>({});
    }
};