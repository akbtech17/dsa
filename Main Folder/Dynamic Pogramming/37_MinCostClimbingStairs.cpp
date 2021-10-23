// 37_MinCostClimbingStairs.cpp
// https://leetcode.com/problems/min-cost-climbing-stairs/
// https://ide.codingblocks.com/s/639613

// Approach - 1D BU DP
// TC - O(N)
// SC - O(N)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int> cost) {
        // cost.size() >= 2
        int n = cost.size();

        // dp[i] => cost of reaching to the (i+1)th step, 
        vector<int> dp(n+1,0);

        // base cases
        dp[0] = cost[0];
        dp[1] = cost[1];

        // we will start the loop from the 3rd step
        for(int i=2; i<=n; i++) {
        	// we can climb the ith step by coming from either
        	// 1. (i-1)th step
        	// 2. (i-2)th step
        	int c1 = INT_MAX, c2 = INT_MAX;
        	if(i-1>=0) c1 = dp[i-1];
        	if(i-2>=0) c2 = dp[i-2];
        	dp[i] = min(c1,c2);

            // we dont have to add the cost of the last step
            if(i != n) dp[i] += cost[i];
        }
        return dp[n];
    }
};

int main() {
	Solution S;
	cout<<S.minCostClimbingStairs({10,15,20})<<endl;
	cout<<S.minCostClimbingStairs({1,100,1,1,1,100,1,1,100,1})<<endl;

	return 0;
}