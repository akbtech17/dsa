// 55_Handshakes.cpp
// Question - https://practice.geeksforgeeks.org/problems/handshakes1303/1
// Code - 
// Resource - https://www.youtube.com/results?search_query=gfg+handshakes
#include <bits/stdc++.h>
using namespace std;

// A1: Recursive Solution
// TC: O(N*2) 
// SC: O(N)
class Solution1 {
public:
    int count(int n){
        // code here
        if(n == 0) return 1;
        int ans = 0;
        for(int i=2; i<=n; i+=2) {
            int c1 = count(i-2);
            int c2 = count(n-i);
            ans += (c1*c2);
        }
        return ans;
    }
};

// A1: Recursive Solution
// TC: O(N) 
// SC: O(N)
class Solution2 {
public:
    int recurse(int n, vector<int> &dp) {
        // code here
        if(n == 0) return dp[n] = 1;
        if(dp[n] != -1) return dp[n];

        int ans = 0;
        for(int i=2; i<=n; i+=2) {
            int c1 = recurse(i-2,dp);
            int c2 = recurse(n-i,dp);
            ans += (c1*c2);
        }
        return dp[n] = ans;
    }
    int count(int n) {
        // code here
        vector<int> dp(n+1,-1);
        return recurse(n,dp);
    }
};

// A3: Bottom Up Dp
// TC: O(N) 
// SC: O(N)
class Solution3 {
public:
    int count(int n) {
        // code here
        vector<int> dp(n+1,0);
        for(int i=2; i<=n; i+=2) {
        	for(int pivot=2; pivot<=i; ) 
        }
        return dp[n];
    }
};