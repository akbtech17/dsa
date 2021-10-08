// 7-StockSpanProblem.cpp
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include<bits/stdc++.h>
using namespace std;


vector<int> greatestElementInRight(vector<int>);

// we need to find such pair of i,j
// i<j, p[i]<p[j] and maximize(p[j]-p[i])
// tc - linear
// sc - linear
int maxProfit(vector<int>& prices) {
   	// for every price if we knew the nge in right
   	// we could easily make diff and update our ans
	int gprofit = 0;
	vector<int> nge = greatestElementInRight(prices);

	// for(auto el : nge) cout<<el<<" ";
	// 	cout<<endl;

	// iterate the prices 
	for(int i=0;i<prices.size();i++) {
		int buy = prices[i];
		int sell = nge[i];
		if(sell == -1) continue;
		int profit = sell-buy;
		gprofit = max(gprofit,profit);
	}

	return gprofit;
}

vector<int> greatestElementInRight(vector<int> v) {
	int gsf = INT_MIN;
	vector<int> ans(v.size(),-1);

	// iterate from right
	for(int i=v.size()-1; i>=0; i--) {
		// get ans
		if(gsf>v[i]) ans[i] = gsf;
		// update gsf
		gsf = max(gsf,v[i]);
	}

	return ans;
}


// tc - linear
// sc - constant

int maxProfit2(vector<int>& prices) {
   	int profit = 0;
   	int minPriceTillNow = INT_MAX;
   	int n = prices.size();
   	
   	for(int i=0;i<n;i++) {
   		if(prices[i]<minPriceTillNow) {
   			// you buy the stock
   			minPriceTillNow = prices[i];
   		}
   		else {
   			// other wise you sell
   			int cprofit = prices[i]-minPriceTillNow;
   			profit = max(cprofit, profit);
   		}
   	}
	return profit;
}

int main() {
	vector<int> p1({7,1,5,3,6,4});
	vector<int> p2({7,6,4,3,1});

	cout<<maxProfit(p1)<<endl;
	cout<<maxProfit(p2)<<endl;

	cout<<maxProfit2(p1)<<endl;
	cout<<maxProfit2(p2)<<endl;

	return 0;
}