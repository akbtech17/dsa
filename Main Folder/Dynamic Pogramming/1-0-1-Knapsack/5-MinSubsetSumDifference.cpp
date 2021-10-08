// 5-MinSubsetSumDifference.cpp
// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1#
#include<bits/stdc++.h>
using namespace std;


// there are no zeroes in this problem...as elements

// so we have to find the s1,s2 st
// min(s1-s2)
// if we have s1 = s1
// then s2 = sum-s1
// or s2-s1 => min(sum-2s1) 
// so we have to max one set
// if sum = 10, we have possible sum for s1 is 0...10/2(5)


int subsetSum(int n, int arr[], int sum) {
	bool **dp = new bool*[n+1];
	for(int i=0;i<=n;i++) {
		dp[i] = new bool[sum+1];
	} 

	for(int i=0;i<=n;i++) {
		for(int j=0;j<=sum;j++) {
			if(i == 0) dp[i][j] = false;
			if(j == 0) dp[i][j] = true;
		}
	}

	for(int i=1;i<=n;i++) {
		for(int j=1;j<=sum;j++) {
			if(arr[i-1]<=j) dp[i][j] = dp[i-1][j-arr[i-1]] or dp[i-1][j];
			else dp[i][j] = dp[i-1][j];
		}
	}

	for(int j=sum/2;j>=0;j--){
	       if(dp[n][j]) return j;
	}

	return -1;
}

int minDifference(int arr[], int n)  { 
	int tsum=0;
	for(int i=0;i<n;i++) tsum+=arr[i];
	int i = subsetSum(n,arr,tsum);
	return tsum-2*i;
	
} 

int main() {
	// int n = 4, arr[] = {1,6,11,5};
	int n = 2, arr[] = {1,4};
	cout<<minDifference(arr, n)<<endl;

	return 0;
}