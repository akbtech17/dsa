// 3_PrintLCS.cpp
// https://www.geeksforgeeks.org/printing-longest-common-subsequence/
// https://ide.codingblocks.com/s/642189
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
    void printLCS(string s1, string s2) {
    	int m = s1.size();
		int n = s2.size();
    	vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        recurse(s1,s2,m,n,dp);
		int i = m;
		int j = n;
		string lcs = "";

		while(i>0 and j>0) {
			// agar char equal hai,
			if(s1[i-1] == s2[j-1]) {
				lcs+=s1[i-1];
				// toh mtlb humne diagonally travel kia hoga,
				// toh ek step diagonal me wapis lelo!
				i--;
				j--;
			}
			else {
				// vrna hum kisi max cell se aye honge!
				if(dp[i][j-1] > dp[i-1][j]) j--;
				else i--;
			}
		}	

		reverse(lcs.begin(), lcs.end());
		cout<<"S1 : "<<lcs<<endl;
	}
};

// Approach2 - Buttom Up
// TC - O(M*N)
// SC - O(M*N)
class Solution2 {
public:
    void printLCS(string s1, string s2) {
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
		string lcs = "";

		while(i>0 and j>0) {
			// agar char equal hai,
			if(s1[i-1] == s2[j-1]) {
				lcs+=s1[i-1];
				// toh mtlb humne diagonally travel kia hoga,
				// toh ek step diagonal me wapis lelo!
				i--;
				j--;
			}
			else {
				// vrna hum kisi max cell se aye honge!
				if(dp[i][j-1] > dp[i-1][j]) j--;
				else i--;
			}
		}	

		reverse(lcs.begin(), lcs.end());
		cout<<"S2 : "<<lcs<<endl;
	}
};


int main() {
	Solution1 S1;
	Solution2 S2;

	S1.printLCS("ABCDGH","ADH");
	S2.printLCS("ABCDGH","ADH");

	S1.printLCS("AGGTAB","GXTXAYB");
	S2.printLCS("AGGTAB","GXTXAYB");
	
	S1.printLCS("abcde","ace");
	S2.printLCS("abcde","ace");
	
	S1.printLCS("abc","abc");
	S2.printLCS("abc","abc");
	
	S1.printLCS("abc","def");
	S2.printLCS("abc","def");
	
	S1.printLCS("bl","yby");
	S2.printLCS("bl","yby");
	
	S1.printLCS("oxcpqrsvwf","shmtulqrypy");
	S2.printLCS("oxcpqrsvwf","shmtulqrypy");

	return 0;
}