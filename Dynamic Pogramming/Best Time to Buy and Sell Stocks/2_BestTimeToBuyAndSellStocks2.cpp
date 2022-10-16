// 2_BestTimeToBuyAndSellStocks2.cpp
// Problem Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Solution Link - https://ide.codingblocks.com/s/636314
// Reference Link - https://www.youtube.com/watch?v=nGJmxkUJQGs&t=1402s&ab_channel=takeUforward

#include <bits/stdc++.h>
using namespace std;
// Infinte Transaction Allowed and Atmost 1 Transaction at a time.
// But there shouldn't me any overlapping transactions
// BBSS - Not Possible
// BSBS - Good!

// A1: Recursive
// TC : O(N^2), two possibities for each idx
// SC : O(N) Auxiliary Space
class Solution1 {
public:
    int helper(vector<int>& prices, int idx = 0, int canBuy = 1) {
        // base case 
        if(idx == prices.size()) return 0; 
        // no profit
        // in case there is some pending bought stock
        // as we are solving for the max ans, 
        // this case will automatically be rejected

        int profit = 0;
        if(canBuy) {
            profit = max(
                    -prices[idx]+helper(prices,idx+1,0), // either buy
                    0+helper(prices,idx+1,1)             // or don't buy
                );
        }
        else {
            profit = max(
                    prices[idx]+helper(prices,idx+1,1), // either sell
                    0+helper(prices,idx+1,0)            // or don't sell
                );
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return helper(prices);
    }
};

// A2: Memoization
// TC : O(N*2) ~ O(N), only will take the time equivalent to dp cells
// SC : O(N*2) + O(N) ~ O(N) Auxiliary Space
class Solution2 {
public:
    int helper(vector<int>& prices, vector<vector<int>> &dp, int idx = 0, bool canBuy = true) {
        // base case 
        if(idx == prices.size()) return 0; 
        // no profit
        // in case there is some pending bought stock
        // as we are solving for the max ans, 
        // this case will automatically be rejected
        if(dp[idx][canBuy] != -1) return dp[idx][canBuy];
        
        int profit = 0;
        if(canBuy) {
            profit = max(
                    -prices[idx]+helper(prices,dp,idx+1,0), // either buy
                    0+helper(prices,dp,idx+1,1)             // or don't buy
                );
        }
        else {
            profit = max(
                    prices[idx]+helper(prices,dp,idx+1,1), // either sell
                    0+helper(prices,dp,idx+1,0)            // or don't sell
                );
        }
        return dp[idx][canBuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return helper(prices, dp);
    }
};

// A3: Tabulation
// TC : O(N*2) ~ O(N), only will take the time equivalent to dp cells
// SC : O(N*2) ~ O(N)
class Solution3 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, 0));
        
        // base case
        dp[n][0] = dp[n][1] = 0;

        for(int idx = n-1; idx>=0; idx--) {
            for(int canBuy=0; canBuy<=1; canBuy++) {
                int profit = 0;
                if(canBuy) {
                    profit = max(
                            -prices[idx]+dp[idx+1][0], // either buy
                            0+dp[idx+1][1]             // or don't buy
                        );
                }
                else {
                    profit = max(
                            prices[idx]+dp[idx+1][1], // either sell
                            0+dp[idx+1][0]            // or don't sell
                        );
                }
                dp[idx][canBuy] = profit;
            }
        }

        // !important
        return dp[0][1];
    }
};


// A4: Space Optimization
// TC : O(N), only will take the time equivalent to dp cells
// SC : O(1)
class Solution4 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> aheadState(2,0), currState(2,0);
        for(int idx = n-1; idx>=0; idx--) {
            for(int canBuy=0; canBuy<=1; canBuy++) {
                int profit = 0;
                if(canBuy) {
                    profit = max(
                            -prices[idx]+aheadState[0], // either buy
                            0+aheadState[1]             // or don't buy
                        );
                }
                else {
                    profit = max(
                            prices[idx]+aheadState[1], // either sell
                            0+aheadState[0]            // or don't sell
                        );
                }
                currState[canBuy] = profit;
            }
            aheadState = currState; 
        }

        return currState[1];
    }
};