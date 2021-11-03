// 50_AirthmeticSlices2.cpp
// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long int recurse(vector<int> &nums, long long int i, vector<long long int> ap, vector<long long int> &dp) {
        if(i == nums.size()) {
            // if(ap.size()>=3)for(auto nn : ap) cout<<nn<<" ";
            // cout<<endl;
            return ap.size()>=3 ? 1 : 0;
        }
        // if(dp[i] != -1) return dp[i];
        
        if(ap.size() < 2) {
            long long int w1 = recurse(nums,i+1,ap,dp);
            ap.push_back(nums[i]);
            long long int w2 = recurse(nums,i+1,ap,dp);
            return dp[i] = w1+w2;
        }
        else {
            long long int diff = ap[ap.size()-1] - ap[ap.size()-2];
            if(diff == nums[i]-ap[ap.size()-1]) {
                long long int w1 = recurse(nums,i+1,ap,dp);
                ap.push_back(nums[i]);
                long long int w2 = recurse(nums,i+1,ap,dp);
                return dp[i] = w1+w2;
            }
            else return dp[i] = recurse(nums,i+1,ap,dp);
        }
        return 0;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<long long int> ap, dp(nums.size()+1,-1);
        int ans = recurse(nums,0,ap,dp);
        // for(auto nn : dp) cout<<nn<<" ";
        return ans;
    }
};


class Solution2 {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        int n = nums.size();

        for()
        return dp[n-1];
    }
};