// 6-PartitionToKEqualSumSubsets.cpp
// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

#include<bits/stdc++.h>
#define vi vector<int>
#define vii vector<vi>
using namespace std;


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

bool canPartitionKSubsets(vector<int>& nums, int k) {
	int tsum = 0;
	for(auto el : nums) tsum += el;
	if(tsum%k !=0) return false;
	int sum = tsum/k;
	return solveBottomUp(nums,sum) == k ? true : false;
}

int main() {
	vi nums({4,3,2,3,5,2,1});
	int k = 4;
	cout<<canPartitionKSubsets(nums,k)<<endl;
	return 0;
}