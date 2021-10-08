// 5-EqualSumPartition.cpp


#include<bits/stdc++.h>
using namespace std;


bool canPartition(vector<int> &nums) {
	int n = nums.size();
	int sum = 0;
	for(int i=0;i<n;i++) sum += nums[i];
	if(sum % 2 != 0) return false;
	sum /= 2;
	vector<vector<bool>> dp(nums.size()+1, vector<bool>(sum+1,false));
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
	// vector<int> nums({1,5,11,5});
	vector<int> nums({1,2,3,5});

	if(canPartition(nums)) cout<<"subset is possible";
	else cout<<"subset is not possible";

	return 0;
}



