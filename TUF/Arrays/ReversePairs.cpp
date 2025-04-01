#include <iostream>
using namespace std;

// Approach1: Bruteforce
// TC: O(N^2)
// SC: O(1)
class Solution {
public:
	int solve1(vector<int> &nums) {
		int n = nums.size(), count = 0;

		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (nums[i] > (nums[j] * 2)) count++;
			}
		}

		return count;
	}

	int reversePairs(vector<int> &nums) {
		return solve1(nums);
	}
};

// Approach2: Merge Sort derived from Count Inversions Problem
// TC: O(NLogN)
// SC: O(N)
class Solution {
public:
	void merge(vector<int> &nums, int s, int m, int e) {
		vector<int> temp;
		int start1 = s, start2 = m + 1, end1 = m, end2 = e;

		while (start1 <= end1 && start2 <= end2) {
			if (nums[start1] > nums[start2]) {
				temp.push_back(nums[start2++]);
			} else {
				temp.push_back(nums[start1++]);
			}
		}

		while (start1 <= end1)
			temp.push_back(nums[start1++]);
		while (start2 <= end2)
			temp.push_back(nums[start2++]);

		for (int i = 0; i < temp.size(); i++) {
			nums[s++] = temp[i];
		}

		return;
	}

	int countInversions(vector<int> &nums, int s, int m, int e) {
		int count = 0;
		int start1 = s, start2 = m + 1, end1 = m, end2 = e;

		while (start1 <= end1 && start2 <= end2) {
			if (nums[start1] > (1ll * 2 * nums[start2])) {
				count += (end1 - start1) + 1;
				start2++;
			} else
				start1++;
		}

		return count;
	}

	int mergeSort(vector<int> &nums, int s, int e) {
		int count = 0;
		// Base Case
		if (s >= e) return count;

		// Recurisve Cases
		int m = s + (e - s) / 2;
		int c1 = mergeSort(nums, s, m);
		int c2 = mergeSort(nums, m + 1, e);

		count = countInversions(nums, s, m, e);
		merge(nums, s, m, e);

		return count + c1 + c2;
	}

	int reversePairs(vector<int> &nums) {
		int n = nums.size();
		int inversions = mergeSort(nums, 0, n - 1);
		return inversions;
	}
};