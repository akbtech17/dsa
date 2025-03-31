#include <iostream>
using namespace std;

// Approach1: Recusion
// TC: O(2^N)
// SC: O(N)
class Solution {
public:
	int climbStairs(int n) {
		// Base Case
		if (n == 0 || n == 1) return 1;

		// Recursive Case
		return climbStairs(n - 1) + climbStairs(n - 2);
	}
};

// Approach2: Memoization
// TC: O(N)
// SC: O(N) + O(N)
class Solution2 {
public:
	int recurse(int n, vector<int> &dp) {
		// Base Case
		if (n == 0 || n == 1) return dp[n] = 1;
		// Lookup Case
		if (dp[n] != -1) return dp[n];

		// Recusive Case
		return dp[n] = recurse(n - 1, dp) + recurse(n - 2, dp);
	}

	int climbStairs(int n) {
		vector<int> dp(n + 1, -1);
		return recurse(n, dp);
	}
};

// Approach3: Tabulation
// TC: O(N)
// SC: O(N)
class Solution3 {
public:
	int climbStairs(int n) {
		vector<int> dp(n + 1, 0);

		for (int i = 0; i <= n; i++) {
			// Base Case
			if (i == 0 || i == 1) dp[i] = 1;
			// Recusive Case
			else
				dp[i] = dp[i - 1] + dp[i - 2];
		}

		return dp[n];
	}
};

// Approach4: Tabulation + Space Optimization
// TC: O(N)
// SC: O(1)
class Solution4 {
public:
	int climbStairs(int n) {
		int pprev = 1, prev = 1;

		for (int i = 2; i <= n; i++) {
			int ans = pprev + prev;

			pprev = prev;
			prev = ans;
		}

		return prev;
	}
};