#include <iostream>
#include <map>
using namespace std;

// Approach1: Bruteforce
// TC: O(N + M)
// SC: O(1)
class Solution {
public:
	int rowWithMax1s(vector<vector<int>> &mat) {
		int ans = -1;

		int n = mat.size(), m = mat[0].size();
		int maxCount = 0;

		for (int i = 0; i < n; i++) {
			int count = 0;
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == 1) count++;
			}
			if (count > maxCount) {
				ans = i;
				maxCount = count;
			}
		}

		return ans;
	}
};

// Approach2: Binary Search
// TC: O(N * LogM)
// SC: O(1)
class Solution {
public:
	int lowerBound(vector<int> &nums) {
		int s = 0, e = nums.size() - 1;

		while (s <= e) {
			int m = (e - s) / 2 + s;

			if (nums[m] >= 1) {
				e = m - 1;
			} else {
				s = m + 1;
			}
		}

		return s;
	}

	int rowWithMax1s(vector<vector<int>> &mat) {
		int ans = -1;

		int n = mat.size(), m = mat[0].size();
		int maxCount = 0;

		for (int i = 0; i < n; i++) {
			int lowerBoundIdx = lowerBound(mat[i]);
			int count = m - lowerBoundIdx;

			if (count > maxCount) {
				ans = i;
				maxCount = count;
			}
		}

		return ans;
	}
};

// Approach3: Two Pointer
// TC: O(N + M)
// SC: O(1)
class Solution {
public:
	int rowWithMax1s(vector<vector<int>> &mat) {
		int ans = -1;

		int n = mat.size(), m = mat[0].size();
		int i = 0, j = m - 1;

		while (i < n && j >= 0) {
			if (mat[i][j] == 1) {
				ans = i;
				while (j >= 0 && mat[i][j] == 1)
					j--;
			}
			i++;
		}

		return ans;
	}
};