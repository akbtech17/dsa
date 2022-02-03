// 1_NthCatalanNumber.cpp
// https://www.geeksforgeeks.org/program-nth-catalan-number/
// https://ide.codingblocks.com/s/642536
#include <bits/stdc++.h>
using namespace std;

// Approach1 - Recursive
// TC - O(is equivalent to nth catalan number) = O(exponential)
// SC - O(exponential)
class Solution1 {
public:
	int nthCatalanNumber(int n) {
		// base case
		if(n <= 1) return 1;

		// catalan of (n) is summation of catalan(i)*catalan(n-i-1) where 0 <= i < n
		int res = 0;
		for(int i=0; i<n; i++) {
			res += nthCatalanNumber(i)*nthCatalanNumber(n-i-1);
		}

		return res;
	}
};


// Approach2 - Top Down DP 
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
			res += nthCatalanNumber(i)*nthCatalanNumber(n-i-1);
		}

		return dp[n] = res;
	}
	int nthCatalanNumber(int n) {
		vector<int> dp(n+1,-1);
		return recurse(n,dp);
	}
};

// Approach3 - Bottom Up DP 
// TC - O(N^2)
// SC - O(N)
class Solution3 {
public:
	int nthCatalanNumber(int n) {
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

	cout<<S3.nthCatalanNumber(3)<<endl;
	cout<<S3.nthCatalanNumber(4)<<endl;
	cout<<S3.nthCatalanNumber(5)<<endl;
	cout<<S3.nthCatalanNumber(6)<<endl;
	return 0;
}