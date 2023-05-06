// 9_UniquePaths.cpp
// Problem Link - https://leetcode.com/problems/unique-paths/
// Code Link - 
// Reference Link - 
#include<bits/stdc++.h>
using namespace std;

// A1 : 
// TC : O(M*N)
// SC : O(M*N)
class Solution {
public:
    int recurse(int m, int n, vector<vector<int>> &dp) {
        // Base Case
        if(m == 1 and n == 1) return dp[m][n] = 1;
        // LookUp Case
        if(dp[m][n] != -1) return dp[m][n];
        
        // Recursive Cases
        int w1=0, w2=0;
        if(m-1 >= 1) w1 = recurse(m-1,n,dp);
        if(n-1 >= 1) w2 = recurse(m,n-1,dp);
        
        return dp[m][n] = w1+w2;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return recurse(m,n,dp);
    }
};

int main() {
	Solution S;
	cout<<S.uniquePaths(3,7)<<endl;
	return 0;
}