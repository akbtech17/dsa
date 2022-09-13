// 36_ClimbingStairs.cpp
// Problem Link - https://leetcode.com/problems/climbing-stairs/
// Code Link - https://ide.codingblocks.com/s/639612

#include <bits/stdc++.h>
using namespace std;

// A1 : BU DP
// TC : O(N)
// SC : O(N)
class Solution1 {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0] = 1;
        for(int i=1; i<=n; i++) {
            dp[i] = i>=2 ? dp[i-2] + dp[i-1] : dp[i-1];
        }
        return dp[n];
    }
};

// A2 : BU DP (using two variables) similar to fibonacci series
//      total ways to reach the current step will be
//      dp[i-1] + dp[i-2] as we can reach the current step from
//      (i-1)th step and (i-2)th step
// TC : O(N)
// SC : O(1)
class Solution2 {
public:
    int climbStairs(int n) {
        // 1 - 1 way
        // 2 - 2 ways
        if(n<=2) return n;
        
        int a = 1;
        int b = 2;
        int ans;
        
        for(int i=3; i<=n; i++) {
            ans = a+b;
            a = b;
            b = ans; 
        }
        return ans;
    }
};

int main() {
	Solution1 S;
	cout<<S.climbStairs(2)<<endl;
	cout<<S.climbStairs(3)<<endl;

	return 0;
}