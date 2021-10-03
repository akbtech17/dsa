// 3_MinimumPathSum.cpp
// https://leetcode.com/problems/minimum-path-sum/

// TC - 
// SC - 

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>

class Solution {
    int ans = 0;
public:
    int recurse(vii grid, int m, int n, vii dp) {
        // base case
        // if(m < 0 or n < 0) return INT_MAX;
        if(m == 0 and n == 0) return dp[m][n] = grid[0][0];
        // lookup case
        if(dp[m][n] != -1) return dp[m][n];
        
        int w1 = INT_MAX;
        int w2 = INT_MAX;
        if(m-1 >= 0) w1 = recurse(grid,m-1,n,dp);
        if(n-1 >= 0) w2 = recurse(grid,m,n-1,dp);
        
        return dp[m][n] = grid[m][n] + min(w1,w2);
    }  

    int bottomUp(vii grid, int m, int n) {
        vii dp(m+1,vi(n+1,0));
        cout<<"m:"<<m<<"n:"<<n<<endl;
        // base cases
        for(int i=0; i<=m; i++) {
            for(int j=0; j<=n; j++) {
                if(i == 0 and j == 0) {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int w1, w2;
                w1=w2=INT_MAX;
                if(i-1 >= 0) w1 = dp[i-1][j];
                if(j-1 >= 0) w2 = dp[i][j-1];
                dp[i][j] = min(w1,w2)+grid[i][j];
            }
        }
        for(auto v: dp) {
            for(auto el : v) {
                cout<<el<<" ";
            }
            cout<<endl;
        }
        if(m == -1 and n == -1) return 0;
        return dp[m][n];
    }
    int minPathSum(vector<vector<int>> grid) {
        vii dp(grid.size()+1,vi(grid[0].size()+1,-1));
        // return recurse(grid,grid.size()-1,grid[0].size()-1,dp);
        return bottomUp(grid,grid.size()-1,grid[0].size()-1);
    }
};

int main () {
	Solution S;
    // cout<<S.minPathSum({{1,2,3},{4,5,6}})<<endl;
    cout<<S.minPathSum({{1}})<<endl;
	// cout<<S.minPathSum({{1,3,1},{1,5,1},{4,2,1}})<<endl;

	return 0;
}