// 2-HouseRobber.cpp
#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/house-robber/
// You are a professional robber planning to rob houses along a street. 
// Each house has a certain amount of money stashed, 
// the only constraint stopping you from robbing each of them is that 
// adjacent houses have security systems connected and it will automatically 
// contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, 
// return the maximum amount of money you can rob tonight without alerting the police.

int recurse(int *arr, int n) {
	if(n == 0) return 0;
	if(n == 1) return arr[n-1];

	int w1, w2;
	w1 = w2 = 0;

	w1 = arr[n-1] + recurse(arr,n-2);  //rob the ith house
	w2 = recurse(arr,n-1); //do not rob the ith house
	
	return max(w1,w2);
}

int recurseTD(int *arr, int n, int *dp) {
	if(n == 0) return dp[n] = 0;
	if(n == 1) return dp[n] = arr[n-1];
	
	if(dp[n] != -1) return dp[n];

	int w1, w2;
	w1 = w2 = 0;

	w1 = arr[n-1] + recurseTD(arr,n-2,dp);  //rob the ith house
	w2 = recurseTD(arr,n-1,dp); //do not rob the ith house
	
	return dp[n] = max(w1,w2);
}

int solveDP1(int *arr, int n) {
	int *dp = new int[n+1];
	memset(dp,-1,sizeof(int)*(n+1));
	return recurseTD(arr,n,dp); 
}

int solveDP2(int *arr, int n) {
	int *dp = new int[n+1];
	dp[0] = 0;

	for(int i=1;i<=n;i++) {
		//ya toh ise rob krlo,
		int w1 = arr[i-1];
		w1+= i-2>=0?dp[i-2]:0; 
		// ya ise rob na kro
		int w2 = dp[i-1];
		dp[i] = max(w1,w2);
	}
	return dp[n]; 
}

int main() {
	int nums1[] = {1,2,3,1};
	int n1 = 4;
	int nums2[] = {2,7,9,3,1};
	int n2 = 5;

	cout<<recurse(nums1,n1)<<endl;
	cout<<recurse(nums2,n2)<<endl;

	cout<<solveDP1(nums1,n1)<<endl;
	cout<<solveDP1(nums2,n2)<<endl;

	cout<<solveDP2(nums1,n1)<<endl;
	cout<<solveDP2(nums2,n2)<<endl;

	return 0;
}	