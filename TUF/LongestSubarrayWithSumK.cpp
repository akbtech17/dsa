#include <iostream>
#include <map>
using namespace std;

// Approach1: Bruteforce
// TC: O(N^2)
// SC: O(1)
class Solution {
public:
	int longestSubarray(vector<int> &nums, int k) {
		int maxLen = 0;
		int n = nums.size();

		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = i; j < n; j++) {
				sum += nums[j];
				if (sum == k) {
					maxLen = max(j - i + 1, maxLen);
				}
			}
		}

		return maxLen;
	}
};

// Approach2: Optimized (Positive + Negative)
// TC: O(N * LogN)
// SC: O(N)
class Solution {
public:
	int longestSubarray(vector<int> &nums, int k) {
		int maxLen = 0;

		map<long long, int> mp;
		long long prefixSum = 0;

		int n = nums.size();
		for (int i = 0; i < n; i++) {
			// preSum2 - preSum1 = K
			// preSum1 = preSum2 - K
			prefixSum += nums[i];

			if (prefixSum == k) {
				maxLen = max(i + 1, maxLen);
			} else if (mp.find(prefixSum - k) != mp.end()) {
				int len = i - mp[prefixSum - k];
				maxLen = max(len, maxLen);
			}

			// this check if extremely imp
			if (mp.find(prefixSum) == mp.end()) mp[prefixSum] = i;
		}

		return maxLen;
	}
};

// Approach2: Optimized Sliding Window (Only Positive)
// TC: O(2N)
// SC: O(1)
class Solution {
public:
	int longestSubarray(vector<int> &nums, int k) {
		int maxLen = 0;

		int i = 0, j = 0;
		int n = nums.size();
		long long sum = 0;

		while (j < n) {
			sum += nums[j];

			while (sum > k && i <= j) {
				sum -= nums[i];
				i++;
			}

			if (sum == k) {
				int len = j - i + 1;
				maxLen = max(len, maxLen);
			}
			j++;
		}

		return maxLen;
	}
};
