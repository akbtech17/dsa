// 54_CherryPickup2.cpp
// Question - https://leetcode.com/problems/cherry-pickup-ii/
// Code - 
#include <bits/stdc++.h>
using namespace std;

// Approach: Recursion + Memoisation
// Build recurse(i,c1,c2) function to 
// return the max collected cherries 
// when our robots have crossed the ith row

// TC - O(MN)
// SC - O(MNN)
class Solution {
public:
    int recurse(vector<vector<int>> &grid, int m, int n, vector<vector<vector<int>>> &dp, int i, int c1, int c2) {
        if(c1 >= n or c2 >= n or c1<0 or c2<0) return 0;
        if(i >= m) 
            return 0;
        if(dp[i][c1][c2] != -1) return dp[i][c1][c2];
        
    
        int curr = (c1 == c2) ? grid[i][c1] : grid[i][c1] + grid[i][c2];
        
        int cs1 = recurse(grid,m,n,dp,i+1,c1-1,c2-1); 	// LL
        int cs2 = recurse(grid,m,n,dp,i+1,c1,c2-1); 	// DL
        int cs3 = recurse(grid,m,n,dp,i+1,c1+1,c2-1); 	// RL
        int cs4 = recurse(grid,m,n,dp,i+1,c1-1,c2); 	// LD
        int cs5 = recurse(grid,m,n,dp,i+1,c1,c2); 		// DD
        int cs6 = recurse(grid,m,n,dp,i+1,c1+1,c2); 	// RD
        int cs7 = recurse(grid,m,n,dp,i+1,c1-1,c2+1); 	// LR
        int cs8 = recurse(grid,m,n,dp,i+1,c1,c2+1); 	// DR
        int cs9 = recurse(grid,m,n,dp,i+1,c1+1,c2+1); 	// RR
        
        int mx = max(max(max(max(cs1,cs2),max(cs3,cs4)), max(max(cs5,cs6),max(cs7,cs8))),cs9);
        mx = mx<0 ? 0 : mx;
        return dp[i][c1][c2] = curr+mx;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>> (n+1, vector<int>(n+1,-1)));
        return recurse(grid,m,n,dp,0,0,n-1);
    }
};

int main() {

}