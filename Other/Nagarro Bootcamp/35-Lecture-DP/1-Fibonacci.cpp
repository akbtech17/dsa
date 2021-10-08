// 1-Fibonacci.cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;

// recursive
//tc - O(2^n)

int fib(int n) {
	if(n == 0 or n == 1) return n;
	return fib(n-1) + fib(n-2);
}

// recursive + dp -> dp
//top-down
//tc - O(n)

int fibDP(int n, int *dp) {
	if(n == 0 or n == 1) {
		return dp[n] = n;
	}
	if(dp[n] != -1) return dp[n];
	return dp[n] = fibDP(n-1,dp) + fibDP(n-2,dp);
}

int findFib(int n) {
	int *arr = new int[n+1];
	memset(arr,-1,sizeof(int)*(n+1));
	// for(int i=0;i<n;i++) cout<<arr[i]<<" ";
	// for(int i=0;i<=n;i++) arr[i] = -1;
	return fibDP(n,arr);
}

//bottom up
//tc - O(n)
int findFib2(int n) {
	int *dp = new int[n+1];
	dp[0] = 0;
	dp[1] = 1;

	for(int i=2;i<=n;i++) {
		dp[i] = dp[i-1]+dp[i-2];
	}

	return dp[n];
}

int32_t main() {
	cout<<findFib2(0)<<endl;
	cout<<findFib2(1)<<endl;
	cout<<findFib2(2)<<endl;
	cout<<findFib2(3)<<endl;
	cout<<findFib2(100)<<endl;

	return 0;
}