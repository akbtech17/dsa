// 2-MinStepsToReach.cpp
#include<bits/stdc++.h>
using namespace std;

//recursive
//tc - O(3^n)
int minSteps(int n) {
	//base case
	if(n == 1) return 0;

	//recursive case
	int w1,w2,w3;
	w1=w2=w3=INT_MAX;
	w1 = minSteps(n-1);
	if(n%2 == 0) w2 = minSteps(n/2);
	if(n%3 == 0) w3 = minSteps(n/3);
	return 1+min(w1,min(w2,w3));
}

//recursive+memo
//tc - O(n)
int minSteps2(int n, int* dp) {
	//base case
	if(n == 1) return dp[n] = 0;
	if(dp[n] != -1) return dp[n];
	//recursive case
	int w1,w2,w3;
	w1=w2=w3=INT_MAX;
	w1 = minSteps2(n-1,dp);
	if(n%2 == 0) w2 = minSteps2(n/2,dp);
	if(n%3 == 0) w3 = minSteps2(n/3,dp);

	return dp[n] = 1+min(w1,min(w2,w3));
}

int minStepsTD(int n) {
	int *dp = new int[n+1];
	for(int i=0;i<=n;i++) {
		dp[i] = -1;
	}
	return minSteps2(n,dp);
}

//Bottom Up
//tc - O(n)
int minStepsBU(int n) {
	int *dp = new int[n+1];
	dp[0] = 0;
	dp[1] = 0;

	for(int i=2;i<=n;i++) {
		int w1,w2,w3;
		w1=w2=w3=INT_MAX;
		w1 = dp[i-1];
		if(n%2==0) w2 = dp[i/2];
		if(n%3==0) w3 = dp[i/3];

		dp[i] = 1+min(w1,min(w2,w3));
	}
	return dp[n];
}

int main() {
	cout<<minStepsTD(20)<<endl;
	cout<<minStepsBU(20)<<endl;

	return 0;
}