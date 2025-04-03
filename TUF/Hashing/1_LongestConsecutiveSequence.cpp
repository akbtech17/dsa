#include <iostream>
#include <unordered_set>
using namespace std;

// Approach1: Bruteforce
// TC: O(NLogN) + O(N)
// SC: O(1)
class Solution1 {
public:
	int longestConsecutive(vector<int> &nums) {
		int maxLen = 1;
		sort(nums.begin(), nums.end());

		int currLen = 1, i = 1;
		while (i < nums.size()) {
			if (nums[i - 1] + 1 == nums[i])
				currLen++;
			else if (nums[i - 1] == nums[i]) {
				i++;
				continue;
			} else
				currLen = 1;
			i++;
			maxLen = max(currLen, maxLen);
		}

		return maxLen;
	}
};

// TC: O(3N)
// SC: (N)
class Solution2 {
public:
	int longestConsecutive(vector<int> &nums) {
		int maxLen = 1;
		unordered_set<int> st;

		for (int num : nums)
			st.insert(num);

		for (int num : st) {
			// If the element is starting sequence
			if (st.find(num - 1) == st.end()) {
				int x = num;
				int cnt = 1;

				while (st.find(x + 1) != st.end()) {
					x++;
					cnt++;
				}

				maxLen = max(cnt, maxLen);
			}
		}

		return maxLen;
	}
};