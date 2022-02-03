// 53_CherryPickup1.cpp
// Question - https://leetcode.com/problems/cherry-pickup/
// Code - 
// Resource - https://www.youtube.com/watch?v=ZV0sUzfA7Eg&t=1195s
#include <bits/stdc++.h>
using namespace std;

// A1 - 
// collect max cherries while going down + 
// collect max cherries while comming back
// valid? - NO, it will FAIL!


// A2 - 
// collect OPTIMAL number of cherries while going down + 
// collect OPTIMAL number of cherries while comming back
// YES it will work!

// A2:Bruteforce - 
// Explore every path from TL->BR
//   and for each path, explore every path from BR->TL
// the max pair will be our ans
// TC - O{(All Path TL->BR) X (All Path BR->TL)}
// SC - O(MN)

// A3 -
// instead of travelling in two direction, 
// travel using 2 persons only in single direction (ie, TL->BR)


// A3: Recursive
// TC - 
// SC - 
class Solution1 {
public:
	int recurse(vector<vector<int>> &grid, int n, int i1=0, int j1=0, int i2 = 0, int j2 = 0) {
		// base case
        if(i1 == n or i2 == n or j1 == n or j2 == n or grid[i1][j1] == -1 or grid[i2][j2] == -1) 
            return INT_MIN;
        
        if(i1 == n-1 and j1 == n-1) return grid[n-1][n-1];
        if(i2 == n-1 and j2 == n-1) return grid[n-1][n-1];

        
        // recursive cases
        int curr_cherries = 0;
        if(i1 == i2 and j1 == j2) {
            curr_cherries += grid[i1][j1];
        }
        else {
            curr_cherries += grid[i1][j1];            
            curr_cherries += grid[i2][j2];
        }
        
        // there can be 4 cases - 
        int c1 = recurse(grid,n,i1+1,j1,i2+1,j2);     // vv   
        int c2 = recurse(grid,n,i1,j1+1,i2,j2+1);     // hh       
        int c3 = recurse(grid,n,i1+1,j1,i2,j2+1);     // vh       
        int c4 = recurse(grid,n,i1,j1+1,i2+1,j2);     // hv 
        
        return curr_cherries + max(max(c1,c2),max(c3,c4));
	}
    int cherryPickup(vector<vector<int>>& grid) {
        int ans = recurse(grid,grid.size());
    	return  ans < 0 ? 0 : ans;
    }
};


// A3: Recursive + Memoisation (Top Down DP)
// TC - 
// SC - 
class Solution2 {
public:
	int recurse(vector<vector<int>> &grid, int n, vector<vector<vector<vector<int>>>> &dp ,int i1=0, int j1=0, int i2 = 0, int j2 = 0) {
		// base case
        if(i1 == n or i2 == n or j1 == n or j2 == n or grid[i1][j1] == -1 or grid[i2][j2] == -1) 
            return dp[i1][j1][i2][j2] = INT_MIN;
        
        if(i1 == n-1 and j1 == n-1) return dp[i1][j1][i2][j2] = grid[n-1][n-1];
        if(i2 == n-1 and j2 == n-1) return dp[i1][j1][i2][j2] = grid[n-1][n-1];

        // lookup case 
        if(dp[i1][j1][i2][j2] != -1) return dp[i1][j1][i2][j2];
        
        // recursive cases
        int curr_cherries = 0;
        if(i1 == i2 and j1 == j2) {
            curr_cherries += grid[i1][j1];
        }
        else {
            curr_cherries += grid[i1][j1];            
            curr_cherries += grid[i2][j2];
        }
        
        // there can be 4 cases - 
        int c1 = recurse(grid,n,dp,i1+1,j1,i2+1,j2);     // vv   
        int c2 = recurse(grid,n,dp,i1,j1+1,i2,j2+1);     // hh       
        int c3 = recurse(grid,n,dp,i1+1,j1,i2,j2+1);     // vh       
        int c4 = recurse(grid,n,dp,i1,j1+1,i2+1,j2);     // hv 
        
        return dp[i1][j1][i2][j2] = curr_cherries + max(max(c1,c2),max(c3,c4));
	}
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size()+1;
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n,-1))));
        int ans = recurse(grid,n-1,dp);
    	return  ans < 0 ? 0 : ans;
    }
};