// 4-CoinChangProblemMinCoins.cpp
// https://leetcode.com/problems/coin-change/
#include<bits/stdc++.h>
using namespace std;

int solveBU(vector<int> val, int n, int w) {
	vector<vector<int>> dp(n+1, vector<int> (w+1));

	for(int i=0;i<=n;i++) {
		for(int j=0;j<=w;j++) {
			// if no coins in the bag, then there we need inf no of coins to 
			// fulfill sum
			if(i == 0) dp[i][j] = INT_MAX-1;
			// if sum is 0
			if(j == 0) dp[i][j] = 0;
			// filling the second row
		}
	}

	// filling the second row
	for(int j=1;j<=w;j++) {
		if(j%val[0] == 0) dp[1][j] = j/val[0];
		else dp[1][j] = INT_MAX-1;
	}

	for(int i=2;i<=n;i++) {
		for(int j=1;j<=w;j++) {
			if(val[i-1]<=j) {
				dp[i][j] = min(1+dp[i][j-val[i-1]] , dp[i-1][j]);
			}
			else dp[i][j] = dp[i-1][j];
		}
	}

	// for(int i=0;i<=n;i++) {
	// 	for(int j=0;j<=w;j++) {
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	return dp[n][w] == INT_MAX-1 ? -1 : dp[n][w];
}

int knapSack(int N, int W, vector<int> val){
	return solveBU(val,N,W);
}


int coinChange(vector<int> coins, int amount) {
 	int W = amount;
 	int N = coins.size();  
 	return knapSack(N,W,coins);     
}

int main() {
	cout<<coinChange({1,2,5},11)<<endl;
	cout<<coinChange({1,2,3},5)<<endl;
	cout<<coinChange({3},2)<<endl;
	return 0;
}

