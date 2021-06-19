// 4-CountSubsetWithGivenSum.cpp
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>
#define pb push_back

int solveRecursive(vi arr, int sum, int n) {
	if(sum == 0) return 1;
	if(n == 0) return 0;

	if(arr[n-1]<=sum) {
		return solveRecursive(arr,sum-arr[n-1],n-1) + solveRecursive(arr,sum,n-1);
	}
	return solveRecursive(arr,sum,n-1);
}


int recurse(vi arr, int sum, int n, vii dp) {
	if(sum == 0) return dp[n][sum] = 1;
	if(n == 0) return dp[n][sum] = 0;
	if(dp[n][sum]!=-1) return dp[n][sum];

	if(arr[n-1]<=sum) {
		return dp[n][sum] = recurse(arr,sum-arr[n-1],n-1,dp) + recurse(arr,sum,n-1,dp);
	}
	return dp[n][sum] = recurse(arr,sum,n-1,dp);
}

int solveTopDown(vi arr, int sum) {
	int n = arr.size();
	vii dp(n+1,vi(sum+1,-1));

	return recurse(arr,sum,n,dp);
}

int solveBottomUp(vi arr, int sum) {
	int n = arr.size();
	vii dp(n+1, vi(sum+1));
	
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=sum;j++) {
			if(i == 0) dp[i][j] = 0;
			if(j == 0) dp[i][j] = 1;
		}
	}

	for(int i=1;i<=n;i++) {
		for(int j=1;j<=sum;j++) {
			if(arr[i-1]<=j) {
				dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][sum];
}

void solve(vi arr, int sum) {
	cout<<solveRecursive(arr, sum, arr.size())<<endl;
	cout<<solveTopDown(arr, sum)<<endl;
	cout<<solveBottomUp(arr, sum)<<endl;
	return ;
}

int main() {
	
	solve({1, 2, 3, 3},6);
	solve({1, 1, 1, 1},1);
	solve({3, 3, 3, 3},6);

	return 0;
}