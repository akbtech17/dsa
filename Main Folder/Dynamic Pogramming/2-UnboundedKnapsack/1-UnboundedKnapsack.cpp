// 1-UnboundedKnapsack.cpp
#include<bits/stdc++.h>
using namespace std;

int recurse(int *val, int *wt, int n, int w, int **dp) {
	// base case
	if(w == 0 or n == 0) return 0;
	// lookup case
	if(dp[n][w] != -1) return dp[n][w];

	// recursive case
	if(wt[n-1]<=w) {
		return dp[n][w] = max(
			val[n-1] + recurse(val,wt,n,w-wt[n-1],dp),
			recurse(val,wt,n-1,w,dp)
		);
	}
	return dp[n][w] = recurse(val,wt,n-1,w,dp);
}

int solveTD(int val[] ,int wt[], int n, int w) {
	int **dp = new int*[n+1];
	for(int i=0;i<=n;i++) {
		dp[i] = new int[w+1];
		memset(dp[i],-1,sizeof(int)*(w+1));
	}

	return recurse(val,wt,n,w,dp);
}

int solveBU(int val[] ,int wt[], int n, int w) {
	int **dp = new int*[n+1];
	for(int i=0;i<=n;i++) {
		dp[i] = new int[w+1];
	}

	for(int i=0;i<=n;i++) {
		for(int j=0;j<=w;j++) {
			if(i == 0 or j == 0) dp[i][j] = 0; 
		}
	}

	for(int i=1;i<=n;i++) {
		for(int j=1;j<=w;j++) {
			if(wt[i-1]<=j) {
				dp[i][j] = max(
						val[i-1] + dp[i][j-wt[i-1]],
						dp[i-1][j]
					);
			}
			else dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][w];
}

int knapSack(int N, int W, int val[], int wt[]){
        // code here
	// return solveTD(val,wt,N,W);
	return solveBU(val,wt,N,W);
}

int main() {
	int val[] = {1,4,5,7};
	int wt[] = {1,3,4,5};
	cout<<knapSack(4,8,val,wt);
	return 0;
}