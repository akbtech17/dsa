// 36_ClimbingStairs.cpp
// https://leetcode.com/problems/climbing-stairs/
// https://ide.codingblocks.com/s/639612

// Approach - BU DP
// total ways to reach the current step will be
// dp[i-1] + dp[i-2] as we can reach the current step from
// (i-1)th step and (i-2)th step

// TC - O(N)
// SC - O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
    	// n is given >= 1
        if(n <= 2) return n; 
        
        int ans = 0;
        int n1 = 1;
        int n2 = 2;
        for(int i=3; i<=n; i++) {
            ans = n1+n2;
            n1 = n2;
            n2 = ans;
        }
        
        return ans;
    }
};

int main() {
	Solution S;
	cout<<S.climbStairs(2)<<endl;
	cout<<S.climbStairs(3)<<endl;

	return 0;
}