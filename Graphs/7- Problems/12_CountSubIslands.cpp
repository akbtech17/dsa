// 12_CountSubIslands.cpp
// Problem Link - https://leetcode.com/problems/count-sub-islands/
// Code Link - https://ide.codingblocks.com/s/658000
#include<bits/stdc++.h>
using namespace std;

// Approach: BFS
// TC: O(V+E)
// SC: O(V)
class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0;
        int m = grid1.size(), n = grid1[0].size();
        
        vector<vector<bool>> isvis(m, vector<bool>(n, false));
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid2[i][j] == 1) {
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    
                    bool cond = true;
                    
                    while(!q.empty()) {
                        int ci = q.front().first, cj =  q.front().second;
                        q.pop();
                        
                        if(ci<0 or ci>=m or cj<0 or cj>=n) continue;
                        if(isvis[ci][cj] or grid2[ci][cj] == 0) continue;
                        
                        if(grid1[ci][cj]!=1) cond = false;
                        
                        isvis[ci][cj] = true;
                        grid2[ci][cj] = 0;
                        
                        q.push({ci+1,cj});
                        q.push({ci,cj+1});
                        q.push({ci-1,cj});
                        q.push({ci,cj-1});
                    }
                    
                    if(cond) ans++;
                }
            }
        }
        
        
        return ans;
    }
};