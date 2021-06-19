// 2-SubsetSum.cpp
// https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back

bool recurse(vi arr, int sum, int n) {
	// base condition
	if(sum == 0) return true;
	if(n == 0) return false;

	// recursvie condtion
	if(arr[n-1] <= sum) {
		return recurse(arr,sum,n-1) or recurse(arr,sum-arr[n-1],n-1);
	}
	return recurse(arr,sum,n-1);
}

bool td(vi arr, int sum, int n, vector<vi> dp) {
	// base condition
	if(sum == 0) return dp[n][sum] = 1;
	if(n == 0) return dp[n][sum] = 0;
	// lookup case
	if(dp[n][sum] != -1) return dp[n][sum];
	// recursvie condtion
	if(arr[n-1] <= sum) {
		return dp[n][sum] = td(arr,sum,n-1,dp) or td(arr,sum-arr[n-1],n-1,dp);
	}
	return dp[n][sum] = td(arr,sum,n-1,dp);
}

bool bu(vi arr, int sum, int n) {
	// create memoization table
	vector<vi> dp(n+1, vi(sum+1));

	for(int i=0;i<=n;i++) {
		for(int j=0;j<=n;j++) {
			if(i == 0) dp[i][j] = 0;
			if(j == 0) dp[i][j] = 1;
		}
	}
	// fill the table
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=sum;j++) {
			if(arr[i-1]<=j) {
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-arr[i-1]]);
			}
			else dp[i][j] = dp[i-1][j];
		}
	}

	return dp[n][sum];
}

int main() {
	vi arr({3, 34, 4, 12, 5, 2});
	int sum = 9;
	int n = arr.size();

	vi arr2({3, 34, 4, 12, 5, 2});
	int sum2 = 30;
	int n2 = arr.size();


	cout<<bu(arr,sum, n)<<endl;
	cout<<bu(arr2,sum2, n2)<<endl;

	vector<vi> dp(n+1, vi(sum+1,-1));
	vector<vi> dp2(n2+1, vi(sum2+1,-1));

	cout<<td(arr,sum,n,dp)<<endl;
	cout<<td(arr2,sum2,n2,dp2)<<endl;

	cout<<recurse(arr,sum,n)<<endl;
	cout<<recurse(arr2,sum2,n2)<<endl;

	return 0;
}