#include <iostream>
#include <map>
using namespace std;

// Approach1: Bruteforce Search
// TC: O(N * M)
// SC: O(1)

// Approach2: Binary Search on every row
// TC: O(N * LogM)
// SC: O(1)

// Approach3: Staircase Search
// TC: O(N + M)
// SC: O(1)
class Solution {
public:
	bool searchMatrix(vector<vector<int>> &mat, int target) {
		int n = mat.size(), m = mat[0].size();
		int i = 0, j = m - 1;

		while (i < n && j >= 0) {
			if (mat[i][j] == target)
				return true;
			else if (mat[i][j] > target)
				j--;
			else
				i++;
		}

		return false;
	}
};