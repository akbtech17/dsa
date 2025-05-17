#include <iostream>
#include <map>
using namespace std;

// Approach1: Bruteforce
// TC: O(NM + NM*Log(NM))
// SC: O(NM)
class Solution {
public:
	int findMedian(vector<vector<int>> &matrix) {
		vector<int> nums;

		for (auto row : matrix) {
			for (auto num : row)
				nums.push_back(num);
		}
		sort(nums.begin(), nums.end());
		int n = nums.size();

		return nums[n / 2];
	}
};