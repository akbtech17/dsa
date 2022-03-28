// 17_ShortestBridge.cpp
// Problem Link - https://leetcode.com/problems/shortest-bridge/
// Code Link - https://ide.codingblocks.com/s/658508
#include <bits/stdc++.h>
using namespace std;

// Approach: 2 BFS Calls
// TC: O(N^2)
// SC: O(N^2)
class Solution {
public: 
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<pair<int,int>,int>> qq;
        vector<vector<bool>> isviss(m, vector<bool>(n, false));
        
        bool island_found = false;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    // run bfs
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    
                    vector<vector<bool>> isvis(m, vector<bool>(n, false));
                    
                    while(!q.empty()) {
                        int ci = q.front().first, cj = q.front().second;
                        q.pop();
                        
                        if(ci<0 or ci>=m or cj<0 or cj>=n) continue;
                        if(isvis[ci][cj] or grid[ci][cj] == 0) continue;
                        
                        qq.push({{ci,cj},0});
                        isviss[ci][cj] = true;
                        isvis[ci][cj] = true;
                        
                        q.push({ci+1,cj});
                        q.push({ci-1,cj});
                        q.push({ci,cj+1});
                        q.push({ci,cj-1});
                    }
                    island_found = true;
                    break;
                }
            }
            if(island_found) break;
        }
        
        
        
        while(!qq.empty()) {
            int ci = qq.front().first.first, cj = qq.front().first.second;
            int cdist = qq.front().second;

            qq.pop();
            
            vector<pair<int,int>> dir({{1,0},{-1,0},{0,1},{0,-1}});
            
            for(auto d: dir) {
                int x = ci + d.first, y = cj + d.second;
                if(x<0 or x>=m or y<0 or y>=n) continue;
                if(isviss[x][y]) continue;
                
                if(grid[x][y] == 1) return cdist;
                
                qq.push({{x,y},cdist+1});
                isviss[x][y] = true;
            }
        }
        return 0;
    }
};