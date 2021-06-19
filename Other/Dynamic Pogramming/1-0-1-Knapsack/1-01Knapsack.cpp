// 1-01Knapsack.cpp
// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back

int recurse(vi value, vi weight, int n, int W) {
	// base condition
	if(n == 0 or W == 0) return 0;

	// recursvie condtion
	int w1,w2,w3;
	w1 = w2 = w3 = 0;
	if(weight[n-1] > W) {
		w1 = recurse(value,weight,n-1,W);
		return w1;
	}
	else {
		w2 = value[n-1] + recurse(value,weight,n-1,W-weight[n-1]);
		w3 = recurse(value,weight,n-1,W);
	}
	return max(w2,w3);
}

int td(vi value, vi weight, int n, int W, int **dp) {
	// base condition
	if(n==0 or W == 0) return dp[n][W] = 0;

	// lookup case
	if(dp[n][W]!=-1) return dp[n][W];

	// recursvie condtion
	int w1,w2,w3;
	w1 = w2 = w3 = 0;
	if(weight[n-1] > W) {
		w1 = recurse(value,weight,n-1,W);
		return dp[n][W] = w1;
	}
	else {
		w2 = value[n-1] + recurse(value,weight,n-1,W-weight[n-1]);
		w3 = recurse(value,weight,n-1,W);
	}
	return dp[n][W] = max(w2,w3);
}

int bu(vi value, vi weight, int n, int W) {
	// create memoization table
	int **dp = new int*[n+1];
	for(int i=0;i<n+1;i++) {
		dp[i] = new int[W+1];
	}
	// initialization of base case
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=W;j++) {
			if(i == 0 or j == 0)
				dp[i][j] = 0;
		}
	}

	// fill the table
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=W;j++) {
			// dp[i][j] = ?
			if(weight[i]<=j) {
				// either include
				int w1 = dp[i-1][j-weight[i]] + value[i];
				// or not
				int w2 = dp[i-1][j];
				dp[i][j] = max(w1,w2);
			} 
			else {
				// not include
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][W];
}

int main() {
	vi value({60,100,120});
	vi weight({10,20,30});
	int n = 3;
	int W = 50;

	// recursive
	cout<<recurse(value,weight,n,W)<<endl;

	// top-down
	int **dp = new int*[n+1];
	for(int i=0;i<=n;i++) {
		dp[i] = new int[W+1];
		memset(dp[i], -1, sizeof(int)*(W+1));
	}
	cout<<td(value,weight,n,W,dp)<<endl;

	// bottom-up
	cout<<bu(value,weight,n,W)<<endl;

	return 0;
}