// 32_BestTimeToBuyAndSellStocksWithCooldown.cpp
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// https://www.youtube.com/watch?v=GY0O57llkKQ&t=58s
// https://ide.codingblocks.com/s/636316

#include <bits/stdc++.h>
using namespace std;

// Appraoch 
// TC - O(N)
// SC - O(1)

// Infinte Transaction Allowed ond Atmost 1 Transaction at a time.
// But there shouldn't me any overlapping transactions
// BBSS - Not Possible
// BSBS - Good!
// Cooldown should be there, before next transaction

// 1. BSP - Bought State Profit
//          State with 1 Extra Stock (bsb, bsbsb, ...)
// 2. SSP - Sold State Profit
//          State with balanced transaction (...bs, bscbs...)
// 3. CSP - Cooldown State Profit
//          State with Cooldown (bsc, bsbsc,)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int obsp = -prices[0];
        int ossp = 0;
        int ocsp = 0;

        for(int i=1; i<prices.size(); i++) {
            int nbsp, nssp, ncsp;
            nbsp = nssp = ncsp = 0;

            // nbsp pe kaha se aa skte hai
            // 1. ya obsp
            // 2. ya ocsp pe aaj naya buy krlete hai
            nbsp = max(obsp, ocsp-prices[i]);


            // nssp pe kaha se aa skte hai
            // 1. ya ossp
            // 2. ya obsp pe aaj sell krlete hai
            nssp = max(ossp, obsp+prices[i]);

            // ncsp pe kaha se aa skte hai
            // 1. ya ocsp
            // 2. ya ossp
            ncsp = max(ocsp, ossp);

            obsp = nbsp;
            ossp = nssp;
            ocsp = ncsp;
        }

        return ossp;
    }
};