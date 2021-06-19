// 3-EqualSumPartition.cpp
// https://leetcode.com/problems/partition-equal-subset-sum/
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>
#define pb push_back

bool recurse(vi nums, int sum, int n, vii dp) {
	if(sum == 0) return dp[n][sum] = 1;
	if(n == 0) return dp[n][sum] = 0;
	if(dp[n][sum] != -1) return dp[n][sum];

	if(nums[n-1]<=sum) 
		return dp[n][sum] = dp[n-1][sum] or dp[n-1][sum-nums[n-1]];
	return dp[n][sum] = dp[n-1][sum];
}

bool solveByTopDown(vector<int>& nums) {
	int total_sum = 0;
	for(auto el: nums) total_sum += el;
	if((total_sum%2) != 0) return false;
	
	int n = nums.size();
	total_sum /= 2;
	vector<vector<bool>> dp(n+1,vector<bool>(total_sum+1));
}

// bottom up
bool canPartition(vector<int>& nums) {
	int total_sum = 0;
	for(auto el: nums) total_sum += el;
	if((total_sum%2) != 0) return false;
	
	int n = nums.size();
	total_sum /= 2;
	vector<vector<bool>> dp(n+1,vector<bool>(total_sum+1));

	for(int i=0;i<=n;i++) {
		for(int j=0;j<=total_sum;j++) {
			if(i == 0) dp[i][j] = false;
			if(j == 0) dp[i][j] = true;
		}
	}

	for(int i=1;i<=n;i++) {
		for(int j=1;j<=total_sum;j++) {
			if(nums[i-1]<=j) dp[i][j] = dp[i-1][j] or dp[i-1][j-nums[i-1]];
			else dp[i][j] = dp[i-1][j];
		}
	}		
	return dp[n][total_sum];
}

void solve(vi arr) {
	if(canPartition(arr)) cout<<"yes\n";
	else cout<<"no\n";

	if(solveByTopDown(arr)) cout<<"yes\n";
	else cout<<"no\n";
	return;
}

int main() {
	vi arr({1, 5, 11, 5	});
	vi arr2({1, 5, 3});
	vi arr3({1, 1});
	solve(arr);
	solve(arr2);
	solve(arr3);
	return 0;
}