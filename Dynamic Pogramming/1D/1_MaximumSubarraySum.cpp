// 1_MaximumSubarraySum.cpp
// Problem Link - https://leetcode.com/problems/maximum-subarray/
// Code Link - https://ide.codingblocks.com/s/673787
#include<bits/stdc++.h>
using namespace std;

// A1 : Bottom Up Approach
// TC : O(N)
// SC : O(N)
int maxSubArray2(vector<int>& nums) {
    if(nums.size() == 0) return 0;
        
    vector<int> dp(nums.size(),0);
    dp[0] = nums[0];

    for(int i=1;i<nums.size();i++) {
        dp[i] = max(nums[i],dp[i-1]+nums[i]);
    }
        
    int mx = INT_MIN;
    
    // find the subarray with maximum sum
    for(auto el : dp) mx = max(mx,el);

    return mx;
}

// A2 : Kadane's Algorithm
// TC : O(N)
// SC : O(1)
int maxSubArray1(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    int msum = nums[0];
    int csum = nums[0];
        
    for(int i=1; i<nums.size(); i++) {
        if(csum>=0) csum += nums[i];
        else csum = nums[i];
        msum = max(msum,csum);
    }
    return msum;
}