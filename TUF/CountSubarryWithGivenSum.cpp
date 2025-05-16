#include <iostream>
#include <map>
using namespace std;

// Approach1: Bruteforce
// TC: O(N^2)
// SC: O(1)
class Solution {
public:
	int subarraySum(vector<int> &nums, int k) {
		int count = 0;
		int n = nums.size();

		for (int i = 0; i < n; i++) {
			long long sum = 0;
			for (int j = i; j < n; j++) {
				sum += nums[j];
				if (sum == k) {
					count++;
				}
			}
		}

		return count;
	}
};

// Approach2: Optimized (Positive + Negative)
// TC: O(N * LogN)
// SC: O(N)
class Solution {
public:
	int subarraySum(vector<int> &nums, int k) {
		int count = 0;

		map<long long, int> mp;
		long long prefixSum = 0;
		int n = nums.size();

		for (int i = 0; i < n; i++) {
			prefixSum += nums[i];
			if (prefixSum == k) {
				count++;
			}
			long long rem = prefixSum - k;
			if (mp.find(rem) != mp.end()) {
				count += mp[rem];
			}

			mp[prefixSum]++;
		}

		return count;
	}
};