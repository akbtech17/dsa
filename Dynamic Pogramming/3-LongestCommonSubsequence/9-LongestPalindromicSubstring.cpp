// 9-LongestPalindromicSubstring.cpp
// https://leetcode.com/problems/longest-palindromic-substring/
#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
	int n = s.size();
	vector<vector<bool>> dp(n,vector<bool> (n));

	int max_len = 0;
	int st = -1;
	
	for(int i=0;i<n;i++) {
		if(i == 0) {
			st = i;
			max_len = 1;
		}
		dp[i][i] = true;
	}
	
	for(int i=0;i<n-1;i++) {
		if(s[i] == s[i+1]) {
			dp[i][i+1] = true;
			st = i;
			max_len = 2;
		}
		else dp[i][i+1] = false;
	}

	for(int k=2;k<n;k++) {
		int i = 0;
		int j = k;

		while(i<n and j<n) {
			if(s[i] == s[j] and dp[i+1][j-1] == true) {
				dp[i][j] = true;
				if(j-i+1 > max_len) {
					max_len = j-i+1;
					st = i;
				}			
			}
			else dp[i][j] = false;
			i++;
			j++;
		}
	}

	// for(int i=0;i<n;i++) {
	// 	for(int j=0;j<n;j++) {
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	return st == -1 ? "" : s.substr(st,max_len);
}

int main() {
	cout<<longestPalindrome("babad")<<endl;
	cout<<longestPalindrome("geeks")<<endl;
	cout<<longestPalindrome("cbbd")<<endl;
	cout<<longestPalindrome("a")<<endl;
	cout<<longestPalindrome("ac")<<endl;
	cout<<longestPalindrome("abvreba")<<endl;

	return 0;
} 

