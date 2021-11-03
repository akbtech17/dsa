// 2_LCSubstring.cpp
// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1
// https://ide.codingblocks.com/s/642068
#include<bits/stdc++.h>
using namespace std;

// Approach - Buttom Up
// TC - O(M*N)
// SC - O(M*N)
class Solution {
public:
    int longestCommonSubstr(string s1, string s2, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        
        int ans = 0;
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else {
                    dp[i][j] = 0;
                }
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};

int main() {
	Solution S;
	cout<<S.longestCommonSubstr("ABCDGH","ACDGHR",6,6)<<endl;
	cout<<S.longestCommonSubstr("ABC","ACB",3,3)<<endl;
	return 0;
}