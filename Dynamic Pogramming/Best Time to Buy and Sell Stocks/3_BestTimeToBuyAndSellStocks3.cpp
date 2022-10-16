// 3_BestTimeToBuyAndSellStocks3.cpp
// Problem Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// Solution Link - https://ide.codingblocks.com/s/676031
// Reference Link - https://www.youtube.com/watch?v=-uQGzhYj8BQ&t=1307s&ab_channel=takeUforward
#include<bits/stdc++.h>
using namespace std;

// A1: Recursive
// TC : O(N^2), two possibities for each idx
// SC : O(N) Auxiliary Space
class Solution1 {
public:
    int helper(vector<int>& prices, int idx = 0, int canBuy=1, int cap=2) {
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
    int maxProfit(vector<int>& prices) {
        return helper(prices);
    }
};

// A2: Memoization
// TC : O(N*2*3)
// SC : O(N*2*3) + O(N) Auxiliary Space
class Solution2 {
public:
    int helper(vector<int>& prices,vector<vector<vector<int>>> &dp, int idx = 0, int canBuy=1, int cap=2) {
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
    int maxProfit(vector<int>& prices) {
    	int n = prices.size();

    	vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
        return helper(prices,dp);
    }
};

// A3: Tabulation
// TC : O(N*2*3)
// SC : O(N*2*3) 
class Solution3 {
public:
    int maxProfit(vector<int>& prices) {
    	int n = prices.size();
    	vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));

    	for(int idx=n-1; idx>=0; idx--) {
    		for(int canBuy=0; canBuy<=1; canBuy++) {
    			for(int cap=1; cap<=2; cap++) {
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
        return dp[0][1][2];
    }
};


// A4: Space Optimization
// TC : O(N*2*3) ~ O(N)
// SC : O(2*2*3) ~ O(1)
class Solution4 {
public:
    int maxProfit(vector<int>& prices) {
    	int n = prices.size();
    	vector<vector<int>> after(2, vector<int>(3,0));
    	vector<vector<int>> curr(2, vector<int>(3,0));

    	for(int idx=n-1; idx>=0; idx--) {
    		for(int canBuy=0; canBuy<=1; canBuy++) {
    			for(int cap=1; cap<=2; cap++) {
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
        return curr[1][2];
    }
};




// -----------------------------------------------------------------------------------------------------------------------
class Solution5 {
public:
    // tNo 0: buy
    // tNo 1: sell
    // tNo 3: buy
    // tNo 4: sell
    int helper(vector<int> &prices, vector<vector<int>> &dp, int idx, int tNo) {
        if(idx == prices.size() or tNo == 4) return 0;
        if(dp[idx][tNo]!=-1) return dp[idx][tNo];
        
        int profit = 0;
        if(tNo % 2 == 0) {
            // can buy or ignore
            profit = max(
                -prices[idx]+helper(prices,dp,idx+1,tNo+1),
                0+helper(prices,dp,idx+1,tNo)
            );
        }
        else {
            // can sell or ignore
            profit = max(
                prices[idx]+helper(prices,dp,idx+1,tNo+1),
                0+helper(prices,dp,idx+1,tNo)
            );
        }
        return dp[idx][tNo] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(4,-1));
    	return helper(prices,dp,0,0);
    }
};


class Solution6 {
public:
    // tNo 0: buy
    // tNo 1: sell
    // tNo 3: buy
    // tNo 4: sell
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(4,0));
        
        for(int idx=n-1; idx>=0; idx--) {
            for(int tNo=0; tNo<=3; tNo++) {
                int profit = 0;
                if(tNo % 2 == 0) {
                    // can buy or ignore
                    profit = max(
                        tNo+1<=3 ? -prices[idx]+dp[idx+1][tNo+1] : -prices[idx],
                        0+dp[idx+1][tNo]
                    );
                }
                else {
                    // can sell or ignore
                    profit = max(
                        tNo+1<=3 ? prices[idx]+dp[idx+1][tNo+1] : prices[idx],
                        0+dp[idx+1][tNo]
                    );
                }
                dp[idx][tNo] = profit;
            }
        }
        
    	return dp[0][0];
    }
};

// A5: Space Optimization
// TC : O(N*4) ~ O(N)
// SC : O(2*4) ~ O(1)
class Solution7 {
public:
    // tNo 0: buy
    // tNo 1: sell
    // tNo 3: buy
    // tNo 4: sell
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(4,0);        
        vector<int> curr(4,0);

        for(int idx=n-1; idx>=0; idx--) {
            for(int tNo=0; tNo<=3; tNo++) {
                int profit = 0;
                if(tNo % 2 == 0) {
                    // can buy or ignore
                    profit = max(
                        tNo+1<=3 ? -prices[idx]+ahead[tNo+1] : -prices[idx],
                        0+ahead[tNo]
                    );
                }
                else {
                    // can sell or ignore
                    profit = max(
                        tNo+1<=3 ? prices[idx]+ahead[tNo+1] : prices[idx],
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