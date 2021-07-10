// 1-MaximumSubarraySum.cpp
// 2-MaximumSubarray.cpp
// https://leetcode.com/problems/maximum-subarray/
#include<bits/stdc++.h>
using namespace std;

// Kadane
int maxSubArray(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    int msum = nums[0];
    int csum = nums[0];
        
    for(int i=1;i<nums.size();i++) {
        if(csum>=0) csum += nums[i];
        else csum = nums[i];
        msum = max(msum,csum);
    }
    return msum;
}


// Bottom Up Dp
int maxSubArray(vector<int>& nums) {
    if(nums.size() == 0) return 0;
        
    vector<int> dp(nums.size(),0);
    dp[0] = nums[0];
    for(int i=1;i<nums.size();i++) {
        dp[i] = max(nums[i],dp[i-1]+nums[i]);
    }
        
    int mx = INT_MIN;
        
    for(auto el : dp) mx = max(mx,el);
    return mx;
}