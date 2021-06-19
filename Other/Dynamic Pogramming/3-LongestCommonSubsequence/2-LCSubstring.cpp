// 2-LCSubstring.cpp
// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1
#include<bits/stdc++.h>
#define vi vector<int>
#define vii vector<vi>
using namespace std;

vii dp(1001, vi(1001,-1));

// int solveRecursive(string s1, string s2, int n1, int n2,int ans=0) {
// 	// base case
// 	if(n1 == 0 or n2 == 0) return dp[n1][n2] = 0;

// 	// lookup
// 	if(dp[n1][n2] != -1) return dp[n1][n2];

// 	// recursive 
// 	if(s1[n1-1] == s2[n2-1]) {
// 		dp[n1][n2] = 1+solveRecursive(s1,s2,n1-1,n2-1,ans); 
// 		ans = max(dp[n1][n2],ans);
// 	}
// 	else {
// 		//if not equal mark 0
// 		return dp[n1][n2] = 0;
// 	}
// 	return ans;
// }

// int solveTD(string s1, string s2) {
// 	return solveRecursive(s1,s2,s1.size(),s2.size());
// }

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
			else dp[i][j] = 0; //if not equal mark 0
		}
	}

	// traverse the array and return the max value
	int ans = 0;
	for(int i=0;i<=n1;i++) {
		for(int j=0;j<=n2;j++) {
			ans = max(ans, dp[i][j]);
		}
	}
	return ans;
}

int longestCommonSubstring(string text1, string text2) {
   	// return solveTD(text1,text2);
   	return solveBU(text1,text2);

}

int main() {
	cout<<longestCommonSubstring("abcde","ace")<<endl;
	cout<<longestCommonSubstring("abc","abc")<<endl;
	cout<<longestCommonSubstring("abc","def")<<endl;
	cout<<longestCommonSubstring("bl","yby")<<endl;
	cout<<longestCommonSubstring("oxcpqrsvwf","shmtulqrypy")<<endl;

	return 0;
}