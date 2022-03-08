// 8_NumberOfIslands.cpp
// Problem Link - https://leetcode.com/problems/number-of-islands/
// Code Link - https://ide.codingblocks.com/s/657949
#include<bits/stdc++.h>
using namespace std;

// Approach: BFS
// TC: O(V+E)
// SC: O(V)
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0, m = grid.size(), n = grid[0].size();
        vector<vector<bool>> isvis(m,vector<bool>(n,false));
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '1' and !isvis[i][j]) {
                    cnt++;
                    
                    // BFS
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    
                    while(!q.empty()) {
                        int ci = q.front().first, cj = q.front().second;
                        q.pop();
                        
                        if(ci<0 or ci>=m or cj<0 or cj>=n) continue;
                        if(grid[ci][cj] == '0' or isvis[ci][cj]) continue;
                        
                        grid[ci][cj] = '0';
                        isvis[ci][cj] = true;
                        
                        q.push({ci+1,cj});                       
                        q.push({ci-1,cj});
                        q.push({ci,cj+1});
                        q.push({ci,cj-1});

                    }
                }        
            }
        }
        
        return cnt;
    }
};