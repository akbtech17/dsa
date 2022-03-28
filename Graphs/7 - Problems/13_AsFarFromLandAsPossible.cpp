// 13_AsFarFromLandAsPossible.cpp
// Problem Link - https://leetcode.com/problems/as-far-from-land-as-possible/
// Code Link - https://ide.codingblocks.com/s/658302
// Resource Link - https://www.youtube.com/watch?v=yV-b0amHNVM&ab_channel=Pepcoding
#include<bits/stdc++.h>
using namespace std;

// Q: Find a water cell such that its distance to the nearest land cell is maximized.
//    Manhattan Distance is the same distance found by BFS 4 direction traversal.
// A1: Bruteforce (TLE)
//     For each water cell run bfs and find the nearest land cell, and maximize the answer.
// TC: O(N^4)
// SC: O(N^2)
class Solution1 {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = -1;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 0) {
                    // run bfs
                    queue<pair<pair<int,int>,int>> q;
                    vector<vector<bool>> isvis(m, vector<bool>(n, false));
                    
                    q.push({{i,j},0});
                    
                    while(!q.empty()) {
                        int ci = q.front().first.first, cj = q.front().first.second;
                        int cdist = q.front().second;
                        q.pop();
                        
                        if(ci<0 or ci>=m or cj<0 or cj>=n) continue;
                        if(isvis[ci][cj]) continue;
                        
                        cdist++;
                        if(grid[ci][cj] == 1) {
                            ans = max(cdist-1,ans);
                            break;
                        }
                        
                        q.push({{ci+1,cj},cdist});
                        q.push({{ci-1,cj},cdist});
                        q.push({{ci,cj+1},cdist});
                        q.push({{ci,cj-1},cdist});
                    }
                }
            }
        }
        
        return ans;
    }
};

// A2: Multisource BFS in Reverse Order (Accepted)
//     From all land cells try to find the farthest water cell node.
// TC: O(N^2)
// SC: O(N^2)
class Solution2 {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        
        queue<pair<pair<int,int>,int>> q;
        vector<vector<bool>> isvis(m, vector<bool>(n, false));
        
        // 1. push all land nodes
        for(int i=0; i<m; i++) 
            for(int j=0; j<n; j++) 
                if(grid[i][j] == 1) q.push({{i,j},0});
        
        // 2. start bfs
        while(!q.empty()) {
            int ci = q.front().first.first, cj = q.front().first.second;
            int cdist = q.front().second;
            
            q.pop();
                        
            if(ci<0 or ci>=m or cj<0 or cj>=n) continue;
            if(isvis[ci][cj]) continue;
            
            ans = max(ans,cdist);
            isvis[ci][cj] = true;
            
            q.push({{ci+1,cj},cdist+1});
            q.push({{ci-1,cj},cdist+1});
            q.push({{ci,cj+1},cdist+1});
            q.push({{ci,cj-1},cdist+1});
        }
        
        return ans == 0 ? -1 : ans;
    }
};