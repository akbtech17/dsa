// 1_LCS.cpp
// https://leetcode.com/problems/longest-common-subsequence/
// https://ide.codingblocks.com/s/642033

#include<bits/stdc++.h>
using namespace std;

// Approach1 - Top Down (Recursion + Memoisation)
// TC - O(M*N)
// SC - O(M*N)
class Solution1 {
public:
	int recurse(string s1, string s2, int n1, int n2, vector<vector<int>> &dp) {
		// 1. base case
		if(n1 == 0 or n2 == 0) return dp[n1][n2] = 0;

		// 2. lookup case 
		if(dp[n1][n2] != -1) return dp[n1][n2];

		// 3. recursive cases
		if(s1[n1-1] == s2[n2-1]) 
			return dp[n1][n2] = 1+recurse(s1,s2,n1-1,n2-1,dp); 
		else 
			return dp[n1][n2] = max(recurse(s1,s2,n1-1,n2,dp),recurse(s1,s2,n1,n2-1,dp));
		
		return 0;
	}
    int longestCommonSubsequence(string s1, string s2) {
    	vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1,-1));
        return recurse(s1,s2,s1.size(),s2.size(),dp);
	}
};

// Approach2 - Buttom Up
// TC - O(M*N)
// SC - O(M*N)
class Solution2 {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[m][n];
    }
};

int main() {
	Solution1 S1;
	Solution2 S2;
	
	cout<<S1.longestCommonSubsequence("abcde","ace")<<endl;
	cout<<S1.longestCommonSubsequence("abc","abc")<<endl;
	cout<<S1.longestCommonSubsequence("abc","def")<<endl;
	cout<<S1.longestCommonSubsequence("bl","yby")<<endl;
	cout<<S1.longestCommonSubsequence("oxcpqrsvwf","shmtulqrypy")<<endl;

	cout<<S2.longestCommonSubsequence("abcde","ace")<<endl;
	cout<<S2.longestCommonSubsequence("abc","abc")<<endl;
	cout<<S2.longestCommonSubsequence("abc","def")<<endl;
	cout<<S2.longestCommonSubsequence("bl","yby")<<endl;
	cout<<S2.longestCommonSubsequence("oxcpqrsvwf","shmtulqrypy")<<endl;

	return 0;
}