// 33_NthFibonacciNumber.cpp
// Problem Link - https://leetcode.com/problems/fibonacci-number/
// Solution Link - https://ide.codingblocks.com/s/636312
#include <bits/stdc++.h>
using namespace std;

// A1 : 1D BU DP
// TC : O(N)
// SC : O(N)
class Solution1 {
public:
    int fib(int n) {
        vector<int> dp(n+1,0);
        for(int i=0; i<=n; i++)
            if(i == 0) dp[i] = 0;            
            else if(i == 1) dp[i] = 1;
            else dp[i] = dp[i-1] + dp[i-2];
        
        return dp[n];
    }
};

// A2 : Using two variables
// TC : O(N)
// SC : O(1)
class Solution2 {
public:
    int fib(int n) {
        int n1 = 0;
        int n2 = 1;
        if(n == 0 or n == 1) return n; 
        
        int ans = 0;
        while(n>=2) {
            ans = n1 + n2;
            n1 = n2;
            n2 = ans;
            n--;
        }
        return ans;
    }
};