// 2_NumberOfUniqueBST.cpp
// https://leetcode.com/problems/unique-binary-search-trees/
// https://ide.codingblocks.com/s/642537
#include <bits/stdc++.h>
using namespace std;

// Approach1 - Recursive (TLE)
// TC - O(is equivalent to nth catalan number) = O(exponential)
// SC - O(exponential)
class Solution1 {
public:
	int numTrees(int n) {
		// base case
		if(n <= 1) return 1;

		// catalan of (n) is summation of catalan(i)*catalan(n-i-1) where 0 <= i < n
		int res = 0;
		for(int i=0; i<n; i++) {
			res += numTrees(i)*numTrees(n-i-1);
		}

		return res;
	}
};


// Approach2 - Top Down DP (TLE)
// TC - O(N^2)
// SC - O(N)
class Solution2 {
public:
	int recurse(int n, vector<int> &dp) {
		// base case
		if(n <= 1) return dp[n] = 1;
		
		// lookup case
		if(dp[n]!=-1) return dp[n];
		
		// catalan of (n) is summation of catalan(i)*catalan(n-i-1) where 0 <= i < n
		int res = 0;
		for(int i=0; i<n; i++) {
			res += numTrees(i)*numTrees(n-i-1);
		}

		return dp[n] = res;
	}
	int numTrees(int n) {
		vector<int> dp(n+1,-1);
		return recurse(n,dp);
	}
};

// Approach3 - Bottom Up DP (accepted)
// TC - O(N^2)
// SC - O(N)
class Solution3 {
public:
	int numTrees(int n) {
		vector<int> dp(n+1,0);
		
		for(int j=0; j<=n; j++) {
			if(j<=1) dp[j] = 1;
			else {
				for(int i=0; i<j; i++) {
					dp[j] += dp[i]*dp[j-i-1];
				}
			}
		}
		return dp[n];
	}
};


int main() {
	Solution3 S3;

	cout<<S3.numTrees(3)<<endl;
	cout<<S3.numTrees(4)<<endl;
	cout<<S3.numTrees(5)<<endl;
	cout<<S3.numTrees(6)<<endl;
	return 0;
}