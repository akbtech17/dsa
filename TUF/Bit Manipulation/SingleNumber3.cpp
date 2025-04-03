#include <iostream>
using namespace std;

// Approach1: Bruteforce
// TC: O(N^2) checking freq for each element
// SC: O(1)

// Approach2: Bruteforce
// TC: O(N)
// SC: O(N) using map

// Approach3: Optimized using Bit Manipulation Theory
// TC: O(N) + O(N)
// SC: O(1)
class Solution3 {
public:
	vector<int> singleNumber(vector<int> &nums) {
		int xorr = 0;
		for (int num : nums)
			xorr ^= num;

		// bitmask for rightmost diff bit
		int mask = (xorr & (xorr - 1)) ^ xorr;
		int set_1 = 0;
		int set_0 = 0;

		for (int num : nums) {
			if ((num & mask) != 0)
				set_1 ^= num;
			else
				set_0 ^= num;
		}

		if (set_1 < set_0) return {set_1, set_0};
		return {set_0, set_1};
	}
};