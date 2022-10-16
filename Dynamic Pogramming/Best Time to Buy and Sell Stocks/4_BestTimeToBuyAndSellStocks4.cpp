// 4_BestTimeToBuyAndSellStocks4.cpp
// Problem Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// Solution Link - https://ide.codingblocks.com/s/676030
// Reference Link - https://www.youtube.com/watch?v=IV1dHbk5CDc&ab_channel=takeUforward
#include<bits/stdc++.h>
using namespace std;

// A1: Recursive
// TC : O(N^(K*2))
// SC : O(N) Auxiliary Space
class Solution1 {
public:
    int helper(vector<int>& prices, int idx, int canBuy, int cap) {
        // base case - no profit
        if(idx == prices.size() or cap == 0) return 0; 
     	
        int profit = 0;
        if(canBuy) {
            profit = max(
                    -prices[idx]+helper(prices,idx+1,0,cap), // either buy
                    0+helper(prices,idx+1,1,cap)             // or don't buy
                );
        }
        else {
            profit = max(
                    prices[idx]+helper(prices,idx+1,1,cap-1), // either sell
                    0+helper(prices,idx+1,0,cap)              // or don't sell
                );
        }
        return profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        return helper(prices,0,1,k);
    }
};

// A2: Memoization
// TC : O(N*K*2)
// SC : O(N*K*2) + O(N) Auxiliary Space
class Solution2 {
public:
    int helper(vector<int>& prices,vector<vector<vector<int>>> &dp, int idx, int canBuy, int cap) {
        // base case - no profit
        if(idx == prices.size() or cap == 0) return 0; 
     	// lookup case
     	if(dp[idx][canBuy][cap] != -1) return dp[idx][canBuy][cap];

        int profit = 0;
        if(canBuy) {
            profit = max(
                    -prices[idx]+helper(prices,dp,idx+1,0,cap), // either buy
                    0+helper(prices,dp,idx+1,1,cap)             // or don't buy
                );
        }
        else {
            profit = max(
                    prices[idx]+helper(prices,dp,idx+1,1,cap-1), // either sell
                    0+helper(prices,dp,idx+1,0,cap)              // or don't sell
                );
        }
        return dp[idx][canBuy][cap] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
    	int n = prices.size();

    	vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1,-1)));
        return helper(prices,dp,0,1,k);
    }
};

// A3: Tabulation
// TC : O(N*2*K)
// SC : O(N*2*K) 
class Solution3 {
public:
    int maxProfit(int k, vector<int>& prices) {
    	int n = prices.size();
    	vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1,0)));

    	for(int idx=n-1; idx>=0; idx--) {
    		for(int canBuy=0; canBuy<=1; canBuy++) {
    			for(int cap=1; cap<=k; cap++) {
    				int profit = 0;
			        if(canBuy) {
			            profit = max(
			                    -prices[idx]+dp[idx+1][0][cap], // either buy
			                    0+dp[idx+1][1][cap]             // or don't buy
			                );
			        }
			        else {
			            profit = max(
			                    prices[idx]+dp[idx+1][1][cap-1], // either sell
			                    0+dp[idx+1][0][cap]              // or don't sell
			                );
			        }
			        dp[idx][canBuy][cap] = profit;
			    }
			}
    	}
        return dp[0][1][k];
    }
};


// A4: Space Optimization
// TC : O(N*K*2) ~ O(NK)
// SC : O(2*K*2) ~ O(K)
class Solution4 {
public:
    int maxProfit(int k, vector<int>& prices) {
    	int n = prices.size();
    	vector<vector<int>> after(2, vector<int>(k+1,0));
    	vector<vector<int>> curr(2, vector<int>(k+1,0));

    	for(int idx=n-1; idx>=0; idx--) {
    		for(int canBuy=0; canBuy<=1; canBuy++) {
    			for(int cap=1; cap<=k; cap++) {
    				int profit = 0;
			        if(canBuy) {
			            profit = max(
			                    -prices[idx]+after[0][cap], // either buy
			                    0+after[1][cap]             // or don't buy
			                );
			        }
			        else {
			            profit = max(
			                    prices[idx]+after[1][cap-1], // either sell
			                    0+after[0][cap]              // or don't sell
			                );
			        }
			        curr[canBuy][cap] = profit;
			    }
			}
			after = curr;
    	}
        return curr[1][k];
    }
};

// A4: Space Optimization
// TC : O(N*K*2) ~ O(NK)
// SC : O(2*K) ~ O(K)
class Solution5 {
public:
    int maxProfit(int k, vector<int>& prices) {
    	int n = prices.size();
        vector<int> ahead(2*k,0);        
        vector<int> curr(2*k,0);

        for(int idx=n-1; idx>=0; idx--) {
            for(int tNo=0; tNo<2*k; tNo++) {
                int profit = 0;
                if(tNo % 2 == 0) {
                    // can buy or ignore
                    profit = max(
                        tNo+1<2*k ? -prices[idx]+ahead[tNo+1] : -prices[idx],
                        0+ahead[tNo]
                    );
                }
                else {
                    // can sell or ignore
                    profit = max(
                        tNo+1<2*k ? prices[idx]+ahead[tNo+1] : prices[idx],
                        0+ahead[tNo]
                    );
                }
                curr[tNo] = profit;
            }
            ahead = curr;
        }
        
    	return curr[0];
    }
};