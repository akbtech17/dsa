// 6_BestTimeToBuyAndSellStockWithTransactionFee.cpp
// Problem Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
// Solution Link - https://ide.codingblocks.com/s/676028
// Reference Link - https://www.youtube.com/watch?v=k4eK-vEmnKg&ab_channel=takeUforward
#include <bits/stdc++.h>
using namespace std;

// Approach : Similar to BTTBASS 2
// TC : O(N)
// SC : O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> aheadState(2,0), currState(2,0);
        for(int idx = n-1; idx>=0; idx--) {
            currState[1] = max(
                -prices[idx]+aheadState[0], // either buy
                0+aheadState[1]             // or don't buy
            );
            currState[0] = max(
                prices[idx]+aheadState[1]-fee, // either sell
                0+aheadState[0]                // or don't sell
            );
                
            aheadState = currState; 
        }
        return currState[1];
    }
};