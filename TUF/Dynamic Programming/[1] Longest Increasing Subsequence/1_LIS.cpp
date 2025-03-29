#include <iostream>
using namespace std;

// Approach1: Recursion
// TC: O(2^N)
// SC: O(N)
class Solution1 {
public:
	int recurse(int i, int prevIdx, vector<int> &nums) {
		// Base Case
		if (i >= nums.size()) return 0;

		// Recursive Cases
		int dontTake = recurse(i + 1, prevIdx, nums);
		int take = 0;

		if (prevIdx == -1 || nums[prevIdx] < nums[i]) {
			take = 1 + recurse(i + 1, i, nums);
		}

		return max(dontTake, take);
	}

	int LIS(vector<int> &nums) {
		return recurse(0, -1, nums);
	}
};

// Approach2: Memoization
// TC: O(N^2)
// SC: O(N)
class Solution2 {
public:
	int recurse(int i, int prevIdx, vector<int> &nums,
				vector<vector<int>> &dp) {
		// Base Case
		if (i >= nums.size()) return 0;
		// Lookup Case
		if (dp[i][prevIdx + 1] != -1) return dp[i][prevIdx + 1];

		// Recursive Case
		int dontTake = recurse(i + 1, prevIdx, nums, dp);

		int take = 0;
		if (prevIdx == -1 || nums[prevIdx] < nums[i])
			take = 1 + recurse(i + 1, i, nums, dp);

		return dp[i][prevIdx + 1] = max(dontTake, take);
	}

	int lengthOfLIS(vector<int> &nums) {
		int n = nums.size();
		vector<vector<int>> dp(n, vector<int>(n + 1, -1));
		return recurse(0, -1, nums, dp);
	}
};