// 4-ShortestCommonSupersequence.cpp
// https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1

#include<bits/stdc++.h>
#define vi vector<int>
#define vii vector<vi>
using namespace std;

vii dp(1001, vi(1001,-1));

int solveRecursive(string s1, string s2, int n1, int n2) {
	// base case
	if(n1 == 0 or n2 == 0) return dp[n1][n2] = 0;

	// lookup
	if(dp[n1][n2] != -1) return dp[n1][n2];

	// recursive 
	if(s1[n1-1] == s2[n2-1]) 
		return dp[n1][n2] = 1+solveRecursive(s1,s2,n1-1,n2-1); 
	else {
		return dp[n1][n2] = max(
			solveRecursive(s1,s2,n1-1,n2),  
			solveRecursive(s1,s2,n1,n2-1)
			);
	}
	return 0;
}

int solveTD(string s1, string s2) {
	return solveRecursive(s1,s2,s1.size(),s2.size());
}

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

int ShortestCommonSupersequence(string text1, string text2) {
	int lcs = solveBU(text1,text2);
	// int lcs = solveTU(text1,text2);

	int total_length = text1.size() + text2.size();

	// we have to remove lcs one time....
	// jo common hai ek baar hta denge toh shortes mil jayga
	int scs = total_length-lcs;
}

int main() {
	cout<<ShortestCommonSupersequence("abcde","ace")<<endl;
	cout<<ShortestCommonSupersequence("abc","abc")<<endl;
	cout<<ShortestCommonSupersequence("abc","def")<<endl;
	cout<<ShortestCommonSupersequence("bl","yby")<<endl;
	cout<<ShortestCommonSupersequence("oxcpqrsvwf","shmtulqrypy")<<endl;

	return 0;
}