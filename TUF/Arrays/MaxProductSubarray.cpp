#include <iostream>
using namespace std;

// Approach1: Bruteforce with some optimization
// TC: O(N^2)
// SC: O(1)
class Solution1 {
public:
	int maxProduct(vector<int> &nums) {
		int ans = INT_MIN;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			int prod = 1;
			for (int j = i; j < n; j++) {
				prod *= nums[j];
				ans = max(prod, ans);
			}
		}
		return ans;
	}
};

// Approach2: 
// If all elements are +ve, ans will be mul of all elements
// If all elements are -ve (even) with some +ve, again same
// if there are -ve (odd) then we exclude any 1 neg and ans will be either on suffix or prefix
// If 0, again ans will be either on left or right
// TC: O(N)
// SC: O(1)
class Solution2 {
public:
	int maxProduct(vector<int> &nums) {
		int ans = INT_MIN;
		int n = nums.size();

		int prefix = 1, suffix = 1;

		for (int i = 0; i < n; i++) {
			// reset the suffix/prefix when 0 is met
			if (prefix == 0) prefix = 1;
			if (suffix == 0) suffix = 1;

			// update mutiplications
			prefix *= nums[i];
			suffix *= nums[n - i - 1];

			ans = max(ans, max(prefix, suffix));
		}
		return ans;
	}
};