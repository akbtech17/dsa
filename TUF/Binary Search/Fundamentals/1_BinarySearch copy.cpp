#include <iostream>
using namespace std;

// Approach1 - Iterative
class Solution1 {
public:
	// TC: O(LogN)
	// SC: O(1)
	int search(vector<int> &nums, int target) {
		int n = nums.size();
		int s = 0, e = n - 1;

		while (s <= e) {
			int m = (s + e) / 2;
			if (nums[m] == target)
				return m;
			else if (nums[m] < target)
				s = m + 1;
			else
				e = m - 1;
		}

		return -1;
	}
};

// Approach2 - Recursive
class Solution2 {
public:
	// TC: O(LogN)
	// SC: O(LogN)
	int recurse(vector<int> &nums, int s, int e, int target) {
		// Base Case
		if (s > e) return -1;

		// Recursive Cases
		int m = s + (e - s) / 2; // better way to calc mid
		if (nums[m] == target)
			return m;
		else if (nums[m] < target)
			return recurse(nums, m + 1, e, target);

		return recurse(nums, s, m - 1, target);
	}

	int search(vector<int> &nums, int target) {
		int n = nums.size();
		return recurse(nums, 0, n - 1, target);
	}
};