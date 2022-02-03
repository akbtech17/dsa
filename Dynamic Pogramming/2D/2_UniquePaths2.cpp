// 2_UniquePaths2.cpp
// https://leetcode.com/problems/unique-paths-ii/

// TC - O(M*N)
// SC - O(M*N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recurse(int m, int n, vector<vector<int>>& mat, vector<vector<int>> &dp) {
        // Base Case
        if(m == 1 and n == 1) 
            // important!
            return dp[m][n] = mat[m-1][n-1] == 1 ? 0 : 1;
        // LookUp Case
        if(dp[m][n] != -1) return dp[m][n];
        // Check for Obsstacles
        if(mat[m-1][n-1] == 1) return dp[m][n] = 0;
        // Recursive Cases
        int w1=0, w2=0;
        if(m-1 >= 1) w1 = recurse(m-1,n,mat,dp);
        if(n-1 >= 1) w2 = recurse(m,n-1,mat,dp);
        
        return dp[m][n] = w1+w2;
    }
    int uniquePathsWithObstacles(vector<vector<int>> obstacleGrid) {
        int m = obstacleGrid.size();        
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return recurse(m,n,obstacleGrid,dp);
    }
};

int main() {
	Solution S;
	cout<<S.uniquePathsWithObstacles({{0,0,0},{0,1,0},{0,0,0}})<<endl;
	return 0;
}