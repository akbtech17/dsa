// 5_BestTimeToBuyAndSellStocksWithCooldown.cpp
// Problem Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// Solution Link - https://ide.codingblocks.com/s/636316
// Reference Link - https://www.youtube.com/watch?v=IGIe46xw3YY&ab_channel=takeUforward
#include <bits/stdc++.h>
using namespace std;

// A1: Memoization
// TC : O(N*2) ~ O(N), only will take the time equivalent to dp cells
// SC : O(N*2) + O(N) ~ O(N) Auxiliary Space
class Solution1 {
public:
    int helper(vector<int> &prices, vector<vector<int>> &dp, int idx=0, int canBuy=1) {
        if(idx >= prices.size()) return 0;
        if(dp[idx][canBuy] != -1) return dp[idx][canBuy];
        int profit = 0;
        if(canBuy) {
            profit = max(
                -prices[idx]+helper(prices,dp,idx+1,0),
                helper(prices,dp,idx+1,1)
            );
        }
        else {
            profit = max(
                prices[idx]+helper(prices,dp,idx+2,1),
                helper(prices,dp,idx+1,0)
            );
        }
        return dp[idx][canBuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return helper(prices,dp);
    }
};

// A2: Tabulation
// TC : O(N*2) ~ O(N), only will take the time equivalent to dp cells
// SC : O(N*2) ~ O(N)
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        
        for(int idx=n-1; idx>=0; idx--) {
            for(int canBuy=0; canBuy<=1; canBuy++) {
                int profit = 0;
                if(canBuy) {
                    profit = max(
                        -prices[idx]+dp[idx+1][0],
                        dp[idx+1][1]
                    );
                }
                else {
                    profit = max(
                        (idx+2)<=n-1 ? prices[idx]+dp[idx+2][1] : prices[idx],
                        dp[idx+1][0]
                    );
                }
                dp[idx][canBuy] = profit;
            }
        }
        return dp[0][1];
    }
};


// A3: Removing Internal Loop
// TC : O(N*2) ~ O(N)
// SC : O(N*2) ~ O(N)
class Solution3 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        
        for(int idx=n-1; idx>=0; idx--) {  
            dp[idx][1] = max(
                -prices[idx]+dp[idx+1][0],
                dp[idx+1][1]
            );
            dp[idx][0] = max(
                (idx+2)<=n-1 ? prices[idx]+dp[idx+2][1] : prices[idx],
                dp[idx+1][0]
            );
        }
        return dp[0][1];
    }
};


// A4: Space Optimization
// TC : O(N)
// SC : O(3*2) ~ O(1)
class Solution4 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> front2(2, 0);
        vector<int> front1(2, 0);
        vector<int> curr(2, 0);
        
        for(int idx=n-1; idx>=0; idx--) {  
            curr[1] = max(
                -prices[idx]+front1[0],
                front1[1]
            );
            curr[0] = max(
                (idx+2)<=n-1 ? prices[idx]+front2[1] : prices[idx],
                front1[0]
            );

            // swap the buckets
            front2 = front1;
            front1 = curr;
        }
        return curr[1];
    }
};