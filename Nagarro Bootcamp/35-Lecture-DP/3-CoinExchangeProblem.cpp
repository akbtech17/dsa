// 3-CoinExchangeProblem.cpp
#include<bits/stdc++.h>
using namespace std;

//tc - O(m^n)
int minCoins(int  money, int *deno, int n) {
	if(money == 0) return 0;

	int ans = INT_MAX;
	for(int i=0;i<n;i++) {
		if(deno[i]<=money) {
			int chotaAns = minCoins(money-deno[i], deno, n);
			if(chotaAns != -1) ans = min(ans,1+chotaAns);
		}
	}
	return ans==INT_MAX? -1 : ans;
}


//tc - O(m*n)
int minCoins2(int money, int *deno, int n, int *dp) {
	if(money == 0) return dp[money] = 0;
	if(dp[money]!=-1) return dp[money];

	int ans = INT_MAX;
	for(int i=0;i<n;i++) {
		if(deno[i]<=money) {
			int chotaAns = minCoins(money-deno[i], deno, n);
			if(chotaAns != INT_MAX) ans = min(ans,1+chotaAns);
		}
	}
	return dp[money] = ans;
}

int minCoinsTD(int money, int*deno, int n) {
	int *dp = new int[money+1];
	memset(dp,-1,sizeof(int)*(money+1));
	return minCoins2(money,deno,n,dp);
}

//tc - O(m*n)
int minCoinsBU(int money, int*deno, int n) {
	int *dp = new int[money+1];
	dp[0] = 0;
	for(int i=1;i<=money;i++) {
		dp[i] = INT_MAX;
		for(int j=0;j<n;j++) {
			if(deno[j]<=i) {
				int change = dp[i-deno[j]];
				dp[i] = min(dp[i],change+1);
			}
		}
	}
	return dp[money];
}

int main() {
	int deno[3] = {1,7,10};
	int n = 3;
	cout<<minCoins(15,deno,n)<<endl;
	cout<<minCoinsTD(15,deno,n)<<endl;
	cout<<minCoinsBU(15,deno,n)<<endl;

	return 0;
}