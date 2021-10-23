// 40_Traingle.cpp
// https://leetcode.com/problems/triangle/
// https://ide.codingblocks.com/s/639649

// Approach - 2D BU DP
// TC - O(N^2)
// SC - O(N)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        vector<int> dp;
        dp.push_back(triangle[0][0]);
        
        int n = triangle.size();
        for(int i=1; i<n; i++) {
            vector<int> cdp(i+1,0);
            for(int j=0; j<=i; j++) {
                int pi = INT_MAX;
                int pii = INT_MAX;
                int pn = dp.size();
                if(j<pn) pi = dp[j];
                if(j-1>=0) pii = dp[j-1];
                cdp[j] = triangle[i][j] + min(pi,pii);
            }   
            dp = cdp;
        }
        int ans = INT_MAX;
        for(auto el : dp) ans = min(ans,el);
        return ans;
    }
};
