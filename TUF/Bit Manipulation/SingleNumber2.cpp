#include <iostream>
using namespace std;

// Approach 1: Bruteforce - Using FreMap
// TC: O(N)
// SC: O(N)

// Approach 2: Using Bit Level Operations
// TC: O(32N)
// SC: O(1)
class Solution2 {
public:
	int singleNumber(vector<int> &nums) {
		int ans = 0;

		for (int bitIdx = 0; bitIdx < 32; bitIdx++) {
			int setBitsCnt = 0;
			for (int num : nums) {
				if (num & (1 << bitIdx)) setBitsCnt++;
			}
			if ((setBitsCnt % 3) == 1) ans = ans | (1 << bitIdx);
		}

		return ans;
	}
};

// Approach 3: Sort + Logic
// TC: O(NLogN)
// SC: O(1)
class Solution3 {
public:
	int singleNumber(vector<int> &nums) {
		int n = nums.size();

		sort(nums.begin(), nums.end());

		for (int i = 1; i < n; i += 3) {
			if (nums[i - 1] != nums[i]) return nums[i - 1];
		}
		return nums[n - 1];
	}
};