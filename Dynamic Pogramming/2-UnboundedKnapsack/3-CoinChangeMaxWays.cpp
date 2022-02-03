// 3-CoinChangeMaxWays.cpp
// https://leetcode.com/problems/coin-change-2/
#include<bits/stdc++.h>
using namespace std;

int solveBU(vector<int> val, int n, int w) {
	vector<vector<int>> dp(n+1, vector<int> (w+1));

	for(int i=0;i<=n;i++) {
		for(int j=0;j<=w;j++) {
			if(i == 0) dp[i][j] = 0;
			if(j == 0) dp[i][j] = 1;
		}
	}

	for(int i=1;i<=n;i++) {
		for(int j=1;j<=w;j++) {
			if(val[i-1]<=j) {
				dp[i][j] = dp[i][j-val[i-1]] + dp[i-1][j];
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
	return dp[n][w];
}

int knapSack(int N, int W, vector<int> val){
	return solveBU(val,N,W);
}


int change(int amount, vector<int> coins) {
 	int W = amount;
 	int N = coins.size();  
 	return knapSack(N,W,coins);     
}

int main() {
	cout<<change(5,{1,2,5});
	cout<<change(10,{10});
	return 0;
}

