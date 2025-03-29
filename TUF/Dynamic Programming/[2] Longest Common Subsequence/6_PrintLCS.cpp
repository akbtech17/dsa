#include <iostream>
using namespace std;

// Approach: Tabulation
// TC: O(N*M)
// SC: O(N*M)
class Solution {
public:
	string printLCS(string str1, string str2) {
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
		for(int i=0; i<lcsLen; i++) ans += '$';
		int itr = lcsLen-1;
		
		// TC: O(N+M)
		int i1 = l1, i2 = l2;
		while(i1>0 && i2>0) {
			if(str1[i1-1] == str2[i2-1]) {
				ans[itr--] = str1[i1-1];
				i1--, i2--;
			}
			else if(dp[i1][i2-1] > dp[i1-1][i2]) i2--; 
			else i1--;
		}

		return ans;
	}
};

int main() {
	string str1 = "abcde", str2 = "bdgek";
	Solution sol;
	string ans = sol.printLCS(str1, str2);
	cout<<ans;

	return 0;
}