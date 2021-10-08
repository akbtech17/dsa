// LongestIncreasingSubsequence.cpp
// https://leetcode.com/problems/longest-increasing-subsequence/

#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
using namespace std;

// to build any subsequence, we have to consider 
// two option for every postion
// either include
// or exclude

//now increasing subsequence
// if we are standing the jth element
// 1 - > we will check if the prev ele in ss is less than jth element, then we have two choice
// 1.1 -> either include jth or leave
// 2-> but if we have prev element greater or euqal to jth, we dont consider the jth ele

// let f(i,j) denotes = len of LIS of arr[j+1...N] where every el > arr[i]
// 1 - > f(i,j) = max(f(i,j+1),1+f(j,j+1));
// 2 - > f(i,j) = f(i,j);

// int recurse(vector<int> nums, int pre = INT_MIN, int i=0) {
// 	if(i==nums.size()-1) {
// 		return 1;
// 	}
// 	if(nums[i] > pre) {
// 		return max(1+recurse(nums,nums[0],i+1),recurse(nums,pre,i+1));
// 	}
// 	return recurse(nums,pre,i+1);
// }

// int lengthOfLIS(vector<int> nums, int pre = INT_MIN, int i=0) {
// 	return recurse(nums,pre,i);
// }

int recurse(vector<int> nums, vector<vector<int>> memo, int i, int j) {
	// base case
	if(j>nums.size()) return memo[i][j] = 0;
	// lookup case
	if(memo[i][j] != -1) return memo[i][j];

	if(nums[j]<=nums[i]) {
		return memo[i][j] = recurse(nums,memo,i,j+1);
	}
	// else
	return memo[i][j] = max(recurse(nums,memo,i,j+1),1+recurse(nums,memo,j,j+1));

}

int lengthOfLIS(vector<int> nums, int pre = INT_MIN, int i=0) {
	nums.insert(nums.begin(),INT_MIN);
	vector<vector<int>> memo(nums.size()+1,vector<int>(nums.size()+1,-1));
	return recurse(nums,memo,0,1);
}

// dp[i][j] = {max(1+dp[j][j+1],dp[i][j+1]) if A[j] > A[i]}
// dp[i][j] = else dp[i][j+1] 

// int bottumUp(vector<int> nums) {
// 	vector<vector<int> dp(nums.size()+1, vector<int>(nums.size()+1));

// 	// fill rightmost to leftmost
// 	// can fill either top or bottom, it doesnt matter


// }

int main() {
	cout<<lengthOfLIS({10,9,2,5,3,7,101,18})<<endl;
	cout<<lengthOfLIS({0,1,0,3,2,3})<<endl;
	cout<<lengthOfLIS({7,7,7,7,7,7,7})<<endl;
	
	return 0;
}