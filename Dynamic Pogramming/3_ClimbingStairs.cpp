// 3_ClimbingStairs.cpp
// Problem Link - https://leetcode.com/problems/climbing-stairs/
// Code Link - https://ide.codingblocks.com/s/639612
// Reference Link - https://www.youtube.com/watch?v=mLfjzJsN8us&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=3&ab_channel=takeUforward
#include <bits/stdc++.h>
using namespace std;


// A1 : Recurrence
// TC : O(2^N)
// SC : O(N)
class Solution1 {
public:
    int helper(int n) {
        if(n == 0) return 1;
        int w1 = n-1>=0 ? helper(n-1) : 0;
        int w2 = n-2>=0 ? helper(n-2) : 0;
        
        return w1+w2;
    }
    int climbStairs(int n) {
        return helper(n);
    }
};


// A2 : Memoization
// TC : O(N) 
// SC : O(N) + O(N)
class Solution2 {
public:
    int helper(int n,vector<int> &dp) {
        if(n == 0) return 1;
        if(dp[n-1] != -1) return dp[n-1];
        int w1 = n-1>=0 ? helper(n-1,dp) : 0;
        int w2 = n-2>=0 ? helper(n-2,dp) : 0;
        
        return dp[n-1] = w1+w2;
    }
    int climbStairs(int n) {
        vector<int> dp(n,-1);
        return helper(n,dp);
    }
};

// A3 : Tabulation
// TC : O(N)
// SC : O(N)
class Solution3 {
public:
    
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for(int idx=1; idx<=n; idx++) {
            int w1 = idx-1>=0 ? dp[idx-1] : 0;
            int w2 = idx-2>=0 ? dp[idx-2] : 0;

            dp[idx] = w1+w2;
        }
        return dp[n];
    }
};

// A4 : Space Optimization
// TC : O(N)
// SC : O(1)
class Solution4 {
public:
    
    int climbStairs(int n) {
        if(n<=1) return n;
        
        int ppstep, pstep, curr;
        
        if(n>0) ppstep = 0;
        if(n>1) pstep = 1;
 
      
        for(int idx=1; idx<=n; idx++) {
            int w1 = idx-1>=0 ? pstep : 0;
            int w2 = idx-2>=0 ? ppstep : 0;

            curr = w1+w2;
            
            ppstep = pstep;
            pstep = curr;
        }
        return curr;
    }
};
