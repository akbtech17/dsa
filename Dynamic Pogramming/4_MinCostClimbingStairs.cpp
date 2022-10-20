// 4_MinCostClimbingStairs.cpp
// Problem Link - https://leetcode.com/problems/min-cost-climbing-stairs/
// Solution Link - https://ide.codingblocks.com/s/639613
#include <bits/stdc++.h>
using namespace std;

// A2 : 1D TD DP
// TC : O(N)
// SC : O(N)
class Solution1 {
public:
    int recurse(vector<int> &cost, int i, vector<int> &dp) {
        if(i >= cost.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int ccost = cost[i];
        
        int w1 = recurse(cost, i+1, dp);
        int w2 = recurse(cost, i+2, dp);
        
        return dp[i] = ccost + min(w1,w2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        return min(recurse(cost,0,dp),recurse(cost,1,dp));
    }
};

// A2 : 1D BU DP
// TC : O(N)
// SC : O(N)
class Solution2 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, 0);
        for(int i=0; i<=cost.size(); i++) {
            int w1 = i-1 >=0 ? dp[i-1] + cost[i-1] : 0;
            int w2 = i-2 >=0 ? dp[i-2] + cost[i-2] : 0;
            dp[i] = min(w1,w2);
        }
        return dp[cost.size()];
    }
};

int main() {
	Solution1 S;
	cout<<S.minCostClimbingStairs({10,15,20})<<endl;
	cout<<S.minCostClimbingStairs({1,100,1,1,1,100,1,1,100,1})<<endl;
	return 0;
}