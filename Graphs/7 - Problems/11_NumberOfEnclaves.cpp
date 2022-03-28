// 11_NumberOfEnclaves.cpp
// Problem Link - https://leetcode.com/problems/number-of-enclaves/
// Code Link - https://ide.codingblocks.com/s/657999
#include<bits/stdc++.h>
using namespace std;

// Approach: BFS
// TC: O(V+E)
// SC: O(V)
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<bool>> isvis(m, vector<bool>(n, false));
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    bool is_boundary_touched = false;
                    int cnt = 0;
                    
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    
                    while(!q.empty()) {
                        int ci = q.front().first, cj = q.front().second;
                        q.pop();
                        
                        if(ci<0 or cj<0 or ci>=m or cj>=n) continue;
                        if(grid[ci][cj] == 0 or isvis[ci][cj]) continue;
                        
                        if(ci == 0 or cj == 0 or ci == m-1 or cj == n-1) {
                            is_boundary_touched = true;
                        }
                        cnt++;
                        isvis[ci][cj] = true;
                        
                        q.push({ci+1,cj});
                        q.push({ci-1,cj});
                        q.push({ci,cj+1});
                        q.push({ci,cj-1});
                    }
                    
                    if(!is_boundary_touched) ans += cnt;
                }
            }
        }
        
        return ans;
    }
};