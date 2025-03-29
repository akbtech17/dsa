#include <iostream>
using namespace std;

// Approach1: Recursion
// TC: O(2^(N+M))
// SC: O(N+M)
class Solution1 {
public:
	int recurse(int i1, int i2, string str1, string str2) {
		// Base Case: no elements in either of strings
		if (i1 == -1 || i2 == -1) return 0;

		// Recursive Cases
		if (str1[i1] == str2[i2])
			return 1 + recurse(i1 - 1, i2 - 1, str1, str2);

		// If don't match: 2 choices
		int choice1 = recurse(i1 - 1, i2, str1, str2);
		int choice2 = recurse(i1, i2 - 1, str1, str2);

		return max(choice1, choice2);
	}

	int lcs(string str1, string str2) {
		int l1 = str1.size(), l2 = str2.size();
		return recurse(l1 - 1, l2 - 1, str1, str2);
	}
};

// Approach2: Memoization
// TC: O(N*M)
// SC: O(N*M) + O(M+N)
class Solution2 {
public:
	int recurse(int i1, int i2, string str1, string str2,
				vector<vector<int>> &dp) {
		// Base Case: no elements in either of strings
		if (i1 == -1 || i2 == -1) return 0;
		// Lookup Case
		if (dp[i1][i2] != -1) return dp[i1][i2];

		// Recursive Cases
		if (str1[i1] == str2[i2])
			return 1 + recurse(i1 - 1, i2 - 1, str1, str2, dp);

		// If don't match: 2 choices
		int choice1 = recurse(i1 - 1, i2, str1, str2, dp);
		int choice2 = recurse(i1, i2 - 1, str1, str2, dp);

		return dp[i1][i2] = max(choice1, choice2);
	}

	int lcs(string str1, string str2) {
		int l1 = str1.size(), l2 = str2.size();
		vector<vector<int>> dp(l1, vector<int>(l2, -1));
		return recurse(l1 - 1, l2 - 1, str1, str2, dp);
	}
};

// Approach3: Tabulation
// TC: O(N*M)
// SC: O(N*M)
class Solution3 {
public:
	int lcs(string str1, string str2) {
		int l1 = str1.size(), l2 = str2.size();
		vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

		for (int i1 = 1; i1 <= l1; i1++) {
			for (int i2 = 1; i2 <= l2; i2++) {
				if (str1[i1 - 1] == str2[i2 - 1])
					dp[i1][i2] = 1 + dp[i1 - 1][i2 - 1];
				else
					dp[i1][i2] = max(dp[i1 - 1][i2], dp[i1][i2 - 1]);
			}
		}

		return dp[l1][l2];
	}
};

// Approach4: Tabulation with Space Optimization
// TC: O(N*M)
// SC: O(M)
class Solution4 {
public:
	int lcs(string str1, string str2) {
		int l1 = str1.size(), l2 = str2.size();
		vector<int> prev(l2 + 1, 0), curr(l2 + 1, 0);

		for (int i1 = 1; i1 <= l1; i1++) {
			for (int i2 = 1; i2 <= l2; i2++) {
				if (str1[i1 - 1] == str2[i2 - 1])
					curr[i2] = 1 + prev[i2 - 1];
				else
					curr[i2] = max(prev[i2], curr[i2 - 1]);
			}
			prev = curr;
		}

		return prev[l2];
	}
};
