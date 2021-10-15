// 31_BestTimeToBuyAndSellStocks2.cpp
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// https://www.youtube.com/watch?v=HWJ9kIPpzXs
// https://ide.codingblocks.com/s/636314

#include <bits/stdc++.h>
using namespace std;

// Appraoch - 
// jitne bhi upstrokes hai, 
// upr jate smy har peak tk ka profit collect krlo
// means for each increasing substring, we should collect profits

// TC - O(N)
// SC - O(1)

// Infinte Transaction Allowed ond Atmost 1 Transaction at a time.
// But there shouldn't me any overlapping transactions
// BBSS - Not Possible
// BSBS - Good!
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bd = 0;
        int sd = 0;
        int profit = 0;
        // cant be beyond zero, 
        // as people can buy and sell the stock on the same day
        for(int j=1; j<prices.size();j++) {
        	// while the subarray is strictly increasing
        	if(prices[j] >= prices[j-1]) sd++;
        	else {
        		// jaise hi rate neeche hora hai, 
        		// profit collect krlo
        		profit += prices[sd]-prices[bd];   
        		bd = sd = j;     	
        	}
        }

        // last stroke ke baad koi dip nhi aya hoga, 
        // toh last point ke profit ko settle krna hoga!
        profit += prices[sd]-prices[bd]; 
        return profit;
    }
};

