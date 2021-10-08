// 1-Dearrangements.cpp
#include<bits/stdc++.h>
using namespace std;

// Question - We are given N numbers
// N = 6 => 1,2,3,4,5,6
// we have to arrange these numbers such 
// that no number is in its correct place

// eg
// 1,2,3
// 1,3,2
// 2,3,1
// 2,1,3
// 3,2,1
// 3,1,2

// Question in other words - 
// If there are N houses and N invitations,
// we have to tell the number of ways in which we can send invitations
// to all houses, such that no invitation goes to correct house

// Bruteforce - Generate all possible permutations( equals to N fact)
// check for each permutation, by matching with the org array,
// if all numbers are not in their org place
// cnt++
// return cnt
// TC (n! * n) where 
// O(n) is to check the valid dearrangements
// O(!n) no of permutaitons

// eg
// 1,2,3
// 1,3,2
// 2,3,1 <- ans
// 2,1,3 
// 3,2,1
// 3,1,2 <- ans

// Recursive
// Suppose we have to place 1 in other position
// choices are n-1, => 2,3,4,5,6
// suppose we decide to put one in ith postion where i => [2,6]
// now there will be two cases, when we puth in 1 in ith place

// 1-> ith element will go in 1s place	
// then there will be only n-2 elements left to arrange
// so invitations left = n-2
// houses left = n-2
// so problem reduce to f(n-2)

// 2-> ith element will not go in 1s place
// so invitations left = n-1
// houses left = n-1
// so problem reduce to f(n-1)

// total ways = (n-1) * (1+2)
// we will multiply n-1 because for invitaion one we have
// explored only for one position, that is ith
// but there are such n-1 positions

// if n == 0, ans = 0
// if n == 0, ans = 0
// if n == 2, ans = 1

int recurse(int n) {
	//base case
	if(n == 0 or n == 1) return 0;
	if(n == 2) return 1;

	//rcurse
	int w1 = recurse(n-2); //when 1st ele goes to ith pos
	int w2 = recurse(n-1); //when 1st ele does not goes to ith pos

	int ans = (n-1) * (w1+w2); //find ways for all n-1 possiblities
	return ans;
}

int recurseTD(int n, int *dp) {
	//base case
	if(n == 0 or n == 1) return dp[n] = 0;
	if(n == 2) return dp[n] = 1;
	//if it is already been calc
	if(dp[n] != -1) return dp[n];

	//rcurse
	int w1 = recurseTD(n-2,dp); //when 1st ele goes to ith pos
	int w2 = recurseTD(n-1,dp); //when 1st ele does not goes to ith pos

	int ans = (n-1) * (w1+w2); //find ways for all n-1 possiblities
	return dp[n] = ans;
}

int recurseBU(int n) {
	int *dp = new int[n+1];
	dp[0] = dp[1] = 0;
	dp[2] = 1;

	for(int i=3;i<=n;i++){
		dp[i] = (i-1)*(dp[i-1]+dp[i-2]);
	}
	return dp[n];
}

int main() {
	cout<<recurse(1)<<endl;
	cout<<recurse(2)<<endl;
	cout<<recurse(3)<<endl;
	cout<<recurse(4)<<endl;

	int dp[1000];
	memset(dp,-1,sizeof(dp));

	cout<<recurseTD(1,dp)<<endl;
	cout<<recurseTD(2,dp)<<endl;
	cout<<recurseTD(3,dp)<<endl;
	cout<<recurseTD(4,dp)<<endl;

	cout<<recurseBU(1)<<endl;
	cout<<recurseBU(2)<<endl;
	cout<<recurseBU(3)<<endl;
	cout<<recurseBU(4)<<endl;

	return 0;
}



