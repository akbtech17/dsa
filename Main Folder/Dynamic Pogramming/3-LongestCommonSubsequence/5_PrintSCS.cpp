// 5_PrintSCS.cpp
// https://leetcode.com/problems/shortest-common-supersequence/
// https://ide.codingblocks.com/s/642470
#include<bits/stdc++.h>
using namespace std;

// Approach1 - Top Down (Recursion + Memoisation)
// TC - O(M*N)
// SC - O(M*N)
class Solution1 {
public:
	int recurse(string s1, string s2, int n1, int n2, vector<vector<int>> &dp) {
		if(n1 == 0 or n2 == 0) return dp[n1][n2] = 0;
		if(dp[n1][n2] != -1) return dp[n1][n2];
		if(s1[n1-1] == s2[n2-1]) 
			return dp[n1][n2] = 1+recurse(s1,s2,n1-1,n2-1,dp); 
		else 
			return dp[n1][n2] = max(recurse(s1,s2,n1-1,n2,dp),recurse(s1,s2,n1,n2-1,dp));
		
		return 0;
	}
    string shortestCommonSupersequence(string s1, string s2) {
    	int m = s1.size();
		int n = s2.size();
    	vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        recurse(s1,s2,m,n,dp);
		int i = m;
		int j = n;
		string scs = "";

		while(i>0 and j>0) {
			// agar char equal hai,
			if(s1[i-1] == s2[j-1]) {
				scs+=s1[i-1];
				// toh mtlb humne diagonally travel kia hoga,
				// toh ek step diagonal me wapis lelo!
				i--;
				j--;
			}
			else {
				// vrna hum kisi max cell se aye honge!
				// lekin scs me unique char bhi consider krenge!
				if(dp[i][j-1] > dp[i-1][j]) {
					scs += s2[j-1];
					j--;
				}
				else {
					scs += s1[i-1];
					i--;
				}
			}
		}	

		// if either of one of two strings are empty 
		while(i>0) {
			scs += s1[i-1];
			i--;
		}
		while(j>0) {
			scs += s2[j-1];
			j--;
		}

		reverse(scs.begin(), scs.end());
        return scs;
	}
};

// Approach2 - Buttom Up
// TC - O(M*N)
// SC - O(M*N)
class Solution2 {
public:
    string shortestCommonSupersequence(string s1, string s2) {
		int m = s1.size();
		int n = s2.size();
		vector<vector<int>> dp(m+1, vector<int>(n+1,0));

		for(int i=1; i<=m; i++) {
			for(int j=1; j<=n; j++) {
				if(s1[i-1] == s2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
				else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}

		// printing lcs
		int i = m;
		int j = n;
		string scs = "";

		while(i>0 and j>0) {
			// agar char equal hai,
			if(s1[i-1] == s2[j-1]) {
				scs+=s1[i-1];
				// toh mtlb humne diagonally travel kia hoga,
				// toh ek step diagonal me wapis lelo!
				i--;
				j--;
			}
			else {
				// vrna hum kisi max cell se aye honge!
				// lekin scs me unique char bhi consider krenge!
				if(dp[i][j-1] > dp[i-1][j]) {
					scs += s2[j-1];
					j--;
				}
				else {
					scs += s1[i-1];
					i--;
				}
			}
		}	

		// if either of one of two strings are empty 
		while(i>0) {
			scs += s1[i-1];
			i--;
		}
		while(j>0) {
			scs += s2[j-1];
			j--;
		}

		reverse(scs.begin(), scs.end());
        return scs;
	}
};


int main() {
	Solution1 S1;
	Solution2 S2;

	cout<<S1.shortestCommonSupersequence("abac","cab")<<endl;
	cout<<S2.shortestCommonSupersequence("abac","cab")<<endl;

	cout<<S1.shortestCommonSupersequence("aaaaaaaa","aaaaaaaa")<<endl;
	cout<<S2.shortestCommonSupersequence("aaaaaaaa","aaaaaaaa")<<endl;
	
	return 0;
}