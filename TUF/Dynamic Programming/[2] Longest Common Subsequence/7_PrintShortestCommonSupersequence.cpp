#include <iostream>
using namespace std;

// Approach: Tabulation
// TC: O(N*M) + O(N+M)
// SC: O(N*M)
class Solution {
public:
	string shortestCommonSupersequence(string str1, string str2) {
		int l1 = str1.size(), l2 = str2.size();
		vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

		for (int i1 = 1; i1 <= l1; i1++) {
			for (int i2 = 1; i2 <= l2; i2++) {
				if (str1[i1 - 1] == str2[i2 - 1])
					dp[i1][i2] = 1 + dp[i1 - 1][i2 - 1];
				else
					dp[i1][i2] = max(dp[i1 - 1][i2], dp[i1][i2 - 1]);
			}
		}

		int lcsLen = dp[l1][l2];
		string ans = "";

		// TC: O(N+M)
		int i1 = l1, i2 = l2;
		while (i1 > 0 && i2 > 0) {
			if (str1[i1 - 1] == str2[i2 - 1]) {
				ans += str1[i1 - 1];
				i1--, i2--;
			} else if (dp[i1][i2 - 1] > dp[i1 - 1][i2]) {
				ans += str2[i2 - 1];
				i2--;
			} else {
				ans += str1[i1 - 1];
				i1--;
			}
		}

		while (i1 > 0) {
			ans += str1[i1 - 1];
			i1--;
		}

		while (i2 > 0) {
			ans += str2[i2 - 1];
			i2--;
		}

		reverse(ans.begin(), ans.end());
		return ans;
	}
};

int main() {
	string str1 = "abcde", str2 = "bdgek";
	Solution sol;
	string ans = sol.shortestCommonSupersequence(str1, str2);
	cout << ans;

	return 0;
}