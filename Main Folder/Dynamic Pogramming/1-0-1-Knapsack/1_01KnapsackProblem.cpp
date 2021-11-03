// 1_01Knapsack.cpp
// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#
// https://ide.codingblocks.com/s/642126

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>
#define pb push_back

// Approach1 - 
// TC - O(2^N)
// SC - O(2^N)
class Solution1 {
public:
	int recurse(int value[], int weight[], int n, int W) {
		// base condition
		if(n == 0 or W == 0) return 0;

		// recursvie condtion
		int w1,w2,w3;
		w1 = w2 = w3 = 0;
		if(weight[n-1] > W) {
			w1 = recurse(value,weight,n-1,W);
			return w1;
		}
		else {
			w2 = value[n-1] + recurse(value,weight,n-1,W-weight[n-1]);
			w3 = recurse(value,weight,n-1,W);
		}
		return max(w2,w3);
	}
    int knapSack(int W, int wt[], int val[], int n) { 
       	return recurse(val,wt,n,W);
    }
};


// Approach2 - 
// TC - O(N*W)
// SC - O(N*W)
class Solution2 {
public:
	int recurse(int value[], int weight[], int n, int W, vii &dp) {
		// base condition
		if(n==0 or W == 0) return dp[n][W] = 0;

		// lookup case
		if(dp[n][W]!=-1) return dp[n][W];

		// recursvie condtion
		int w1,w2,w3;
		w1 = w2 = w3 = 0;
		if(weight[n-1] > W) {
			w1 = recurse(value,weight,n-1,W,dp);
			return dp[n][W] = w1;
		}
		else {
			w2 = value[n-1] + recurse(value,weight,n-1,W-weight[n-1],dp);
			w3 = recurse(value,weight,n-1,W,dp);
		}
		return dp[n][W] = max(w2,w3);
	}
    int knapSack(int W, int wt[], int val[], int n) {
    	vii dp(n+1, vi(W+1,-1));
       	return recurse(val,wt,n,W,dp);
    }
};


// Approach3 - 
// TC - O(N*W)
// SC - O(N*W)
class Solution3 {
public:
	int solve(int value[], int weight[], int n, int W) {
		// create memoization table
		vii dp(n+1, vi(W+1,0));
		
		// fill the table
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=W; j++) {
				// dp[i][j] = ?
				if(weight[i-1]<=j) {
					// either include
					int w1 = dp[i-1][j-weight[i-1]] + value[i-1];
					// or not
					int w2 = dp[i-1][j];
					dp[i][j] = max(w1,w2);
				} 
				else {
					// not include
					dp[i][j] = dp[i-1][j];
				}
			}
		}
		return dp[n][W];
	}
    int knapSack(int W, int wt[], int val[], int n) {
    	return solve(val,wt,n,W);
    }
};


int main() {
	int value[] = {60,100,120};
	int weight[] = {10,20,30};
	int n = 3;
	int W = 50;

	// 1. Recursive
	Solution1 S1;
	cout<<S1.knapSack(W,weight,value,n)<<endl;

	// 2. Top Down
	Solution2 S2;
	cout<<S2.knapSack(W,weight,value,n)<<endl;

	// 3. Bottom Up
	Solution3 S3;
	cout<<S3.knapSack(W,weight,value,n)<<endl;

	return 0;
}