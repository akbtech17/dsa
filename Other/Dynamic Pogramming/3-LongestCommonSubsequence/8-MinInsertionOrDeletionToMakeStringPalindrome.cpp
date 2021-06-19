// 8-MinDeletionToMakeStringPalindrome.cpp
// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
#include<bits/stdc++.h>
#define vi vector<int>
#define vii vector<vi>
using namespace std;


int solveBU(string s1, string s2) {
	vii dp(s1.size()+1, vi(s2.size()+1));
	int n1 = s1.size();
	int n2 = s2.size();
	for(int i=0;i<=n1;i++) {
		for(int j=0;j<=n2;j++) {
			if(i == 0 or  j == 0) dp[i][j] = 0;
		}
	}

	for(int i=1;i<=n1;i++) {
		for(int j=1;j<=n2;j++) {
			if(s1[i-1] == s2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}


	return dp[n1][n2];
}



int longestPalindromicSubsequence(string text) {
   	// return solveTD(text1,text2);
   	string text2 = text;
   	reverse(text2.begin(),text2.end());
   	return solveBU(text,text2);
}

int minOperation(string s) {
	int lps = longestPalindromicSubsequence(s);
	return s.size()-lps;
}

int main() {
	cout<<minOperation("bbbab")<<endl;
	cout<<minOperation("cbbd")<<endl;

	return 0;
}