// 1-NStairs.cpp

// There are n stairs, a person standing at the bottom wants to reach the top.
// The person can climb either k stairs at a time. 
// Count the number of ways, the person can reach the top

// f(n) - denotes number of ways to climb n stairs
// to reach Nth stair, i can either com from N-kth stair,
// where k [1,2,3];
// so if we have the value of f(n-1), f(n-2), f(n-3)
// total ways to reach Nth stair will be
// 1+w1+w2+w3

// for base case take the ex when N=1
// we will call on f(n-1), f(0) = 1
// and theortically also we have 1 way, hence proved XD


#include<bits/stdc++.h>
using namespace std;

int waysToClimb(int n, int k) {
	// base case - if there is no step to climb, means standing on the groud floor
	if(n == 0) 
		return 1; // there will be one way;

	// recusive
	int ways = 0;
	for(int j=1;j<=k;j++) {
		if(j<=n) {
			// number of ways to climb  n-jth stair
			ways += waysToClimb(n-j,k);
		}
	}
	return ways;
}

int waysToClimb2(int n, int k, vector<int> &dp) {
	// base case - if there is no step to climb, means standing on the groud floor
	if(n == 0) 
		return dp[n] = 1; // there will be one way;
	//lookup
	if(dp[n]!=-1) return dp[n];

	// recusive
	int ways = 0;
	for(int j=1;j<=k;j++) {
		if(j<=n) {
			// number of ways to climb  n-jth stair
			ways += waysToClimb2(n-j,k,dp);
		}
	}
	return dp[n] = ways;
}


int waysToClimbTD(int n, int k) {
	vector<int> dp(n+1,-1);
	return waysToClimb2(n,k,dp);
}

// bottom up
// tabulization
int waysToClimbBU(int n, int k) {
	vector<int> dp(n+1,0);
	dp[0] = 1;

	for(int i=1;i<=n;i++) {
		for(int j=1;j<=k;j++) {
			if(i-j>=0) {
				dp[i] += dp[i-j];
			}
		}
	}
	return dp[n];
}

int main() {

	cout<<waysToClimb(2,3)<<endl;
	cout<<waysToClimb(4,3)<<endl;

	cout<<waysToClimbTD(2,3)<<endl;
	cout<<waysToClimbTD(4,3)<<endl;

	cout<<waysToClimbBU(2,3)<<endl;
	cout<<waysToClimbBU(4,3)<<endl;
	return 0;
}