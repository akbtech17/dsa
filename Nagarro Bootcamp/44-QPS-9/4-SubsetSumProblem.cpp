// 4-SubsetSumProblem.cpp
#include<bits/stdc++.h>
using namespace std;

bool solveBU(vector<int> &nums, int sum) {
	vector<vector<bool>> dp(nums.size()+1, vector<bool>(sum+1,false));
	int n = nums.size();
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=sum;j++) {
			if(i == 0) dp[i][j] = false;
			if(j == 0) dp[i][j] = true;
			
		}
	}

	for(int i=1;i<=n;i++) {
		for(int j=1;j<=sum;j++) {
			if(j>=nums[i-1]) {
				dp[i][j] = dp[i-1][j] or dp[i-1][j-nums[i-1]];
			}
			else dp[i][j] = dp[i-1][j];
			// cout<<dp[i][j]<<" ";
		}
		// cout<<endl;
		
	}

	return dp[n][sum];
}

int main() {
	vector<int> nums({1,2,3});
	int sum = 3;

	if(solveBU(nums,sum)) cout<<"subset is possible";
	else cout<<"subset is not possible";

	return 0;
}