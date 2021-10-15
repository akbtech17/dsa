// 30_BestTimeToBuyAndSellStocks1.cpp
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// https://www.youtube.com/watch?v=4YjEHmw1MX0
// https://ide.codingblocks.com/s/636313

#include <bits/stdc++.h>
using namespace std;

// Appraoch - Similar to Kadane's Algorithm
// we need to find such pair of i,j
// such that i<j, p[i]<p[j] and maximize(p[j]-p[i])

// we consider each day as potential sellpoint
// ki agar is din bechta toh kitna max profit hota!

// har day ka max profit check krne ke liye, 
// we should have the least buy point at some ith day
// which is less than curr day.

// TC - O(N)
// SC - O(1)
// 1 Transaction Allowed!
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_so_far = prices[0];
        int max_profit_so_far = 0;          
        // cant be beyond zero, 
        // as people can buy and sell the stock on the same day
        for(int j=1; j<prices.size(); j++) {
        	// treat every day as a potential sell point
        	int curr_profit = prices[j] - min_so_far;
        	if(curr_profit > 0)
        		max_profit_so_far = max(max_profit_so_far,curr_profit);
        	min_so_far = min(prices[j],min_so_far);
        }
        return max_profit_so_far;
    }
};

