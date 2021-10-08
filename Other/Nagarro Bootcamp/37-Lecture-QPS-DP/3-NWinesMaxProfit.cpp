// 3-NWinesMaxProfit.cpp

// Given n wines in a row, with integers denoting the cost of each wine respectively. 
// Each year you can sale the first or the last wine in the row. 
// However, the price of wines increases over time. 
// Let the initial profits from the wines be P1, P2, P3…Pn. 
// On the Yth year, the profit from the ith wine will be Y*Pi. 
// For each year, your task is to print “beg” or “end” denoting 
// whether first or last wine should be sold. 
// Also, calculate the maximum profit from all the wines.

#include<bits/stdc++.h>
using namespace std;

int maxProfit(int *price, int s, int e, int year = 1) {
	if(s>e) return 0;

	int w1,w2;
	w1=w2=0;

	w1 = (price[s]*year) + maxProfit(price,s+1,e,year+1);
	w2 = (price[e]*year) + maxProfit(price,s,e-1,year+1);

	return max(w1,w2);
}

int maxProfit2(int *price, int s, int e, int year, vector<vector<int>> &dp) {
	// base case
	if(s>e) return dp[s][e] = 0;
	// lookup case
	if(dp[s][e] != -1) return dp[s][e];

	// recursive
	int w1,w2;
	w1=w2=0;

	w1 = (price[s]*year) + maxProfit(price,s+1,e,year+1);
	w2 = (price[e]*year) + maxProfit(price,s,e-1,year+1);

	return dp[s][e] = max(w1,w2);
}

int solveTD(int *price, int s, int e) {
	vector<vector<int>> dp(e+1,vector<int>(e+1,-1));
	return maxProfit2(price,s,e,1,dp);
}  

int solveBU(int *price, int n) {
	// init 0
	// inderectly handles the base case, when i>j
	vector<vector<int>> dp(n,vector<int>(n,0));
	
	// fill the main diagonal
	for(int i=0;i<n;i++) {
		dp[i][i] = price[i]*n;
	}
	
	// fill the remaining element - diagonal by diagonal
	for(int it=1; it<n; it++) {
		int y = n-it;
		for(int i=0;i<y;i++) {
			int j = it+i;
			dp[i][j] = max(price[i]*y+dp[i+1][j],price[j]*y+dp[i][j-1]);
		}
	}
	
	return dp[0][n-1]; 
}  

int main() {
	int price[] = { 2, 4, 6, 2, 5 };
  	int n = sizeof(price) / sizeof(price[0]);

  	cout<<maxProfit(price,0, n-1, 1)<<endl;
  	cout<<solveTD(price,0, n-1)<<endl;
  	cout<<solveBU(price,n)<<endl;

  	return 0;

}