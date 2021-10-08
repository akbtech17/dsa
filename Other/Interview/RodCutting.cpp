// RodCutting.cpp
#include<bits/stdc++.h>
using namespace std;

int maxProfit(int n, int *price, int *dp) {
	// base case
	if(n <= 0) return dp[n] = 0;
	// 
	// recursive case
	int mx = INT_MIN;
	for(int i=1;i<=8;i++) {
		mx = max(mx,price[i-1]+maxProfit(n-i,price));
	}

	return mx;
}


int main() {
	int price[] = {1,5,8,9,10,17,17,20};

	cout<<maxProfit(8,price)<<endl;
	cout<<maxProfit(24,price)<<endl;

	return 0;
}