// 9_MaxAreaOfIsland.cpp
// Problem Link - https://leetcode.com/problems/max-area-of-island/
// Code Link - https://ide.codingblocks.com/s/657951
#include<bits/stdc++.h>
using namespace std;

// Approach: BFS
// TC: O(V+E)
// SC: O(V)
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mx = 0, m = grid.size(), n = grid[0].size();
        vector<vector<bool>> isvis(m, vector<bool>(n,false));
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    int cnt = 0;
                    
                    // bfs
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    
                    while(!q.empty()) {
                        int ci = q.front().first, cj = q.front().second;
                        q.pop();
                        
                        if(ci<0 or ci>=m or cj<0 or cj>=n) continue;
                        if(isvis[ci][cj] or grid[ci][cj] == 0) continue;
                        
                        cnt++;
                        grid[ci][cj] = 0;
                        isvis[ci][cj] = true;
                        
                        q.push({ci+1,cj});
                        q.push({ci-1,cj});
                        q.push({ci,cj+1});
                        q.push({ci,cj-1});
                    }
                    
                    mx = max(cnt,mx);
                }
            }
        }
        
        return mx;
    }
};