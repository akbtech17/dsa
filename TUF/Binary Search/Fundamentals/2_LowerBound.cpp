#include <iostream>
using namespace std;

// Approach1 - Iterative
class Solution1 {
public:
	// TC: O(LogN)
	// SC: O(1)
	int lowerBound(vector<int> &nums, int target) {
		int n = nums.size();
		int s = 0, e = n - 1;

		while (s <= e) {
			int m = s + (e - s) / 2;

			if (nums[m] >= target)
				e = m - 1;
			else
				s = m + 1;
		}

		return s;
	}
};

// Approach2 - Recursive
class Solution2 {
public:
	// TC: O(LogN)
	// SC: O(LogN)
	int helper(vector<int> &nums, int s, int e, int target) {
		// Base Case
		if (s > e) return s;

		// Recursive Cases
		int m = s + (e - s) / 2;
		if (nums[m] >= target) return helper(nums, s, m - 1, target);
		return helper(nums, m + 1, e, target);
	}

	int lowerBound(vector<int> &nums, int target) {
		return helper(nums, 0, nums.size() - 1, target);
	}
};