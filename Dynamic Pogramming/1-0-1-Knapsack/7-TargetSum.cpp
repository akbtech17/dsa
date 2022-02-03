// 7-TargetSum.cpp
// https://leetcode.com/problems/target-sum/

// s1-s2 = target
// s+s2 = tsum
// 2s1 = tsum+target
// s1 = (tsum+target)/2

#include<bits/stdc++.h>
#define vi vector<int>
#define vii vector<vi>
using namespace std;

int subsetSum(vi arr, int sum) {
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
			// handle zero case seperately
			if(arr[i-1] == 0) dp[i][j] = dp[i-1][j];
			else if(j<arr[i-1]){
				dp[i][j] = dp[i-1][j];
			}
			else  {
				dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
			}
			
		}
	}

	return dp[n][sum];
}

int findTargetSumWays(vector<int> nums, int target) {
	// s1-s2 = target
	// s+s2 = tsum
	// 2s1 = tsum+target
	// s1 = (tsum+target)/2

	int tsum = 0;
	int n = nums.size();
	int count_zero = 0;

	for(int i=0;i<n;i++) {
		tsum+=nums[i];
		if(nums[i] == 0) count_zero=count_zero+1;
	}

	if(target > tsum) return 0;
	if((target+tsum)%2 != 0) return 0;

	int sum = (tsum+target)/2;
	// we have to consider zeroes subset seperately
	return pow(2,count_zero) * subsetSum(nums,sum);
}

int main() {
	cout<<findTargetSumWays({1,0},1);
	return 0;
}