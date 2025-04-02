#include <iostream>
#include <map>
using namespace std;

// Approach1: Bruteforce
// TC: O(N^2)
// SC: O(1)
class Solution1 {
public:
	int subarraysWithXorK(vector<int> &nums, int k) {
		int count = 0;
		int n = nums.size();

		for (int i = 0; i < n; i++) {
			int xorr = 0;
			for (int j = i; j < n; j++) {
				xorr ^= nums[j];
				if (xorr == k) count++;
			}
		}

		return count;
	}
};

// Approach2: Based on observation and something like CumSum Approach
// TC: O(N) + O(NLogN)
// SC: O(N)
class Solution2 {
public:
	int subarraysWithXorK(vector<int> &nums, int k) {
		int count = 0;
		int n = nums.size();
		int xorr = 0;

		map<int, int> mp;
		// imp case
		mp[0] = 1;

		for (int i = 0; i < n; i++) {
			xorr ^= nums[i];
			int x = xorr ^ k;
			count += mp[x];

			mp[xorr]++;
		}

		return count;
	}
};