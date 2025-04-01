#include <iostream>
using namespace std;

// Approach1: Bruteforce
// TC: O(N^2)
// SC: O(1)
class Solution {
public:
	long long int numberOfInversions(vector<int> nums) {
		long long int inversions = 0;
		int n = nums.size();

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (nums[i] > nums[j]) inversions++;
			}
		}

		return inversions;
	}
};

// Approach2: Merge Sort
// TC: O(NLogN)
// SC: O(N)
class Solution {
public:
	long long int merge(vector<int> &nums, int s, int m, int e) {
		long long int inversions = 0;
		vector<int> temp;
		int start1 = s, start2 = m + 1, end1 = m, end2 = e;

		while (start1 <= end1 && start2 <= end2) {
			if (nums[start1] > nums[start2]) {
				temp.push_back(nums[start2++]);
				inversions += (end1 - start1 + 1);
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

		return inversions;
	}

	long long int mergeSort(vector<int> &nums, int s, int e) {
		long long int count = 0;
		// Base Case
		if (s >= e) return count;

		// Recurisve Cases
		int m = s + (e - s) / 2;
		count += mergeSort(nums, s, m);
		count += mergeSort(nums, m + 1, e);

		count += merge(nums, s, m, e);

		return count;
	}

	long long int numberOfInversions(vector<int> nums) {
		int n = nums.size();
		long long int inversions = mergeSort(nums, 0, n - 1);
		return inversions;
	}
};