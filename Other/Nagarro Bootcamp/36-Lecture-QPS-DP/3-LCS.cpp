// 3-LCS.cpp

// burteforfce
// generate all possible subs of s1
// (2^N1) subs
// and among them check for each subs if it is common to 
// s2 string, which would take N time
// tc (2^N1)N2


// Recursive
// take two itr i,j for s1,s2 respectively
// f(i,j) => lcs of s1[i...n1-1] and s2[j...n2-1]
// if ith char matches, then we can surely add it in our common
// subsequence, so ans = 1+lcs(i+1,j+1);
// if it dowsnot matches, 
// 1-> ith char may match with (j+1)th char
// so lcs(i,j+1)
// 2-> jth char may match with (i+1)th char
// so lcs(i+1,j)
// so ans = max(1,2);


#include<bits/stdc++.h>
using namespace std;

// recursive
int lcs(string &s1, string &s2, int i=0, int j=0) {
	// base case
	// if any one of the string becomes empty, 
	// lcs will 0
	if(i == s1.size() or j == s2.size()) return 0;

	//recursive intution
	if(s1[i] == s2[j]) {
		return 1+lcs(s1,s2,i+1,j+1);
	}
	
	int w1, w2;
	w1=w2=0;
	w1 = lcs(s1,s2,i,j+1);
	w2 = lcs(s1,s2,i+1,j);
	return max(w1,w2);
}

// top-down
int lcs2(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
	// base case
	// if any one of the string becomes empty, 
	// lcs will 0
	if(i == s1.length() or j == s2.length()) return dp[i][j] = 0;
	//lookup
	if(dp[i][j]!= -1) return dp[i][j];
	//recursive intution
	if(s1[i] == s2[j]) {
		return dp[i][j] = 1+lcs2(s1,s2,i+1,j+1,dp);
	}
	
	int w1, w2;
	w1=w2=0;
	w1 = lcs2(s1,s2,i,j+1, dp);
	w2 = lcs2(s1,s2,i+1,j, dp);
	return dp[i][j] = max(w1,w2);
}	

int lcsTD(string s1, string s2) {
	vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1,-1));
	return lcs2(s1,s2,0,0,dp);
}

int lcsBU(string s1, string s2) {
	vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1,0));
	int n1 = s1.length();
	int n2 = s2.length();

	for(int i=1;i<=n1;i++) {
		for(int j=1;j<=n2;j++) {
			if(s1[i] == s2[j]) dp[i][j] = 1+dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}


	return dp[n1][n2];
}


int main() {
	string s1 = "abcd";
	string s2 = "abdeg";

	cout<<lcs(s1,s2)<<endl;
	cout<<lcsTD(s1,s2)<<endl;
	cout<<lcsBU(s1,s2)<<endl;

	return 0;
}