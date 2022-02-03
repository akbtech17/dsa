// UniquePaths3.cpp
// https://leetcode.com/problems/unique-paths-iii/
// https://ide.codingblocks.com/s/642039

// Approach - DFS
// TC - O(M*N*4)
// SC - O(M*N)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recurse(int i, int j, vector<vector<int>> &grid, pair<int,int> end,vector<vector<bool>> isvis, int cnt) {
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or grid[i][j] == -1 or isvis[i][j] == true) return 0;
        if(i == end.first and j == end.second) {
            if(cnt == 0) return 1;
            return 0;
        }
        
        isvis[i][j] = true;
        
        return recurse(i+1,j,grid,end,isvis,cnt-1) + 
            recurse(i-1,j,grid,end,isvis,cnt-1) + 
            recurse(i,j+1,grid,end,isvis,cnt-1) + 
            recurse(i,j-1,grid,end,isvis,cnt-1);
    }
    int uniquePathsIII(vector<vector<int>> grid) {
        pair<int,int> start, end;
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) start = {i,j};
                if(grid[i][j] == 2) end = {i,j};
                if(grid[i][j] == 0) cnt++;
            }
        }
        vector<vector<bool>> isvis(m+1, vector<bool>(n+1,false));
        return recurse(start.first, start.second, grid, end, isvis, cnt+1);
    }
};

int main() {
	Solution S;
    cout<<S.uniquePathsIII({{1,0,0,0},{0,0,0,0},{0,0,2,-1}});
    cout<<S.uniquePathsIII({{1,0,0,0},{0,0,0,0},{0,0,0,2}});
	cout<<S.uniquePathsIII({{0,1},{2,0}});

	return 0;
}