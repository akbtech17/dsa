// 2_PerfectSquares.cpp
// https://leetcode.com/problems/perfect-squares/
// https://ide.codingblocks.com/s/635763

// Approach - BU 1D DP
// TC - O(N)
// SC - O(N)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        for(int num=1; num<=n; num++) {
            for(int i=1; i*i<=num; i++) {
                dp[num] = min(dp[num],1+dp[num-(i*i)]);
            }
        }
        return dp[n];
    }
};

int main() {
	Solution S;
	cout<<S.numSquares(12)<<endl;
	cout<<S.numSquares(13)<<endl;
	cout<<S.numSquares(40)<<endl;

	return 0;
}