#include <iostream>
using namespace std;

// Approach: Tabulation with Space Optimization
// TC: O(N*M)
// SC: O(M)
class SolutionLCS {
public:
	int lcs(string str1, string str2) {
		int l1 = str1.size(), l2 = str2.size();
		vector<int> prev(l2 + 1, 0), curr(l2 + 1, 0);

		for (int i1 = 1; i1 <= l1; i1++) {
			for (int i2 = 1; i2 <= l2; i2++) {
				if (str1[i1 - 1] == str2[i2 - 1])
					curr[i2] = 1 + prev[i2 - 1];
				else
					curr[i2] = max(prev[i2], curr[i2 - 1]);
			}
			prev = curr;
		}

		return prev[l2];
	}
};

class Solution {
public:
	int minOperations(string str1, string str2) {
		int len1 = str1.size(), len2 = str2.size();

		SolutionLCS sol;
		int lcs = sol.lcs(str1, str2);

		return (len1 - lcs) + (len2 - lcs);
	}
};