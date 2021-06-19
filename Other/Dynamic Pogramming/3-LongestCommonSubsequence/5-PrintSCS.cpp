// 5-PrintSCS.cpp
// https://leetcode.com/problems/shortest-common-supersequence/
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

string solveTD(string s1, string s2) {
	solveRecursive(s1,s2,s1.size(),s2.size());
	int n1 = s1.size();
	int n2 = s2.size();
	// ab dp table bhar chuki hogi
	// print SCS
	int i = n1;
	int j = n2;
	string scs = "";

	while(i>0 and j>0) {
		if(s1[i-1] == s2[j-1]) {
			scs+=s1[i-1];
			// toh mtlb hum iske prev diagonal wale element se aye honge
			// so
			i--;
			j--;
		}
		else {
			// hum kisi max se aye honge
			if(dp[i][j-1] > dp[i-1][j]) {
				// we have to consider unique char too
				scs+=s2[j-1];
				j--;
			}
			else {
				// we have to consider unique char too
				scs+=s1[i-1];
				i--;
			}
		}
	}
	// if either of one of two strings are empty 
	while(i>0) {
		scs+=s1[i-1];
		i--;
	}
	while(j>0) {
		scs+=s2[j-1];
		j--;
	}

	reverse(scs.begin(),scs.end());
	return scs;

}

string solveBU(string s1, string s2) {
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

	// print SCS
	int i = n1;
	int j = n2;
	string scs = "";

	while(i>0 and j>0) {
		if(s1[i-1] == s2[j-1]) {
			scs+=s1[i-1];
			// toh mtlb hum iske prev diagonal wale element se aye honge
			// so
			i--;
			j--;
		}
		else {
			// hum kisi max se aye honge
			if(dp[i][j-1] > dp[i-1][j]) {
				// we have to consider unique char too
				scs+=s2[j-1];
				j--;
			}
			else {
				// we have to consider unique char too
				scs+=s1[i-1];
				i--;
			}
		}
	}
	// if either of one of two strings are empty 
	while(i>0) {
		scs+=s1[i-1];
		i--;
	}
	while(j>0) {
		scs+=s2[j-1];
		j--;
	}

	reverse(scs.begin(),scs.end());
	return scs;
}

string printSCS(string text1, string text2) {
   	return solveTD(text1,text2);
   	// return solveBU(text1,text2);

}

int main() {
	cout<<printSCS("abcde","ace")<<endl;
	cout<<printSCS("abc","abc")<<endl;
	cout<<printSCS("abc","")<<endl;
	cout<<printSCS("bl","yby")<<endl;
	cout<<printSCS("oxcpqrsvwf","shmtulqrypy")<<endl;

	return 0;
}