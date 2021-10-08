// 2-RodCutting.cpp

// Given a rod of length n inches and an array of prices that contains prices 
// of all pieces of size smaller than n. Determine the maximum value obtainable 
// by cutting up the rod and selling the pieces. For example, 
// if length of the rod is 8 and the values of different pieces 
// are given as following, then the maximum obtainable value is 22 
// (by cutting in two pieces of lengths 2 and 6) 

// length   | 1   2   3   4   5   6   7   8  
// --------------------------------------------
// price    | 1   5   8   9  10  17  17  20

// And if the prices are as following, then the maximum obtainable value is 24 
// (by cutting in eight pieces of length 1) 


// length   | 1   2   3   4   5   6   7   8  
// --------------------------------------------
// price    | 3   5   8   9  10  17  17  20

#include<bits/stdc++.h>
using namespace std;

// tc n^len 
int maxProfit(int len, int *length, int *price, int n) {
	// base case
	if(len == 0) return 0;

	// recurse
	int profit = 0;
	for(int i=0;i<n;i++) {
		if(len-length[i]>=0) {
			profit = max(profit,price[i]+maxProfit(len-length[i],length,price,n));
		}
	}
	return profit;
}

int maxProfit(int len, int *length, int *price, int n, vector<int> &dp) {
	// base case
	if(len == 0) return dp[len] = 0;
	// lookup
	if(dp[len] != -1) return dp[len];

	// recurse
	int profit = 0;
	for(int i=0;i<n;i++) {
		if(len-length[i]>=0) {
			profit = max(profit,price[i]+maxProfit(len-length[i],length,price,n));
		}
	}
	return dp[len] = profit;
}

int solveTD(int len, int *length, int *price, int n) {
	vector<int> dp(len+1, -1);
	return maxProfit(len,length,price,n,dp);
}

int solveBU(int len, int *length, int *price, int n) {
	vector<int> dp(len+1, 0);

	for(int i=1;i<=len;i++) {
		for(int j=0;j<n;j++) {
			if(i-length[j]>=0) {
				dp[i] = max(dp[i], price[j] + dp[i-length[j]]);
			}
		}
	}

	return dp[len];
}



int main() {
	int length[] = {1,2,3,4,5,6,7,8};
	int price[] = {1,5,8,9,10,17,17,20};
	int n = 8;

	int length2[] = {1,2,3,4,5,6,7,8};
	int price2[] = {3,5,8,9,10,17,17,20};
	int n2 = 8;

	cout<<maxProfit(8,length,price,n)<<endl;
	cout<<maxProfit(8,length2,price2,n2)<<endl;
	
	cout<<solveTD(8,length,price,n)<<endl;
	cout<<solveTD(8,length2,price2,n2)<<endl;

	cout<<solveBU(8,length,price,n)<<endl;
	cout<<solveBU(8,length2,price2,n2)<<endl;
	
	return 0;
}