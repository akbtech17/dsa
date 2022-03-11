// 16_ShortestPathInBinaryMatrix.cpp
// Problem Link - https://leetcode.com/problems/shortest-path-in-binary-matrix/
// Code Link - https://ide.codingblocks.com/s/658306
#include <bits/stdc++.h>
using namespace std;

// Approach: Bruteforce BFS
// TC: O(N^2)
// SC: O(N^2)
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), sht_pth = 0;        
        vector<vector<bool>> isvis(m, vector<bool>(n,false));
        
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},1});
        
        while(!q.empty()) {
            int ci = q.front().first.first, cj = q.front().first.second;
            int cdist = q.front().second;
            q.pop();
            
            if(ci<0 or ci>=m or cj<0 or cj>=n) continue;
            if(grid[ci][cj] != 0 or isvis[ci][cj]) continue;
            
           
            isvis[ci][cj] = true;
            
            if(ci == m-1 and cj == n-1) return cdist;
            
            q.push({{ci+1,cj},cdist+1});
            q.push({{ci-1,cj},cdist+1});
            q.push({{ci,cj+1},cdist+1});
            q.push({{ci,cj-1},cdist+1});
            
            q.push({{ci+1,cj+1},cdist+1});
            q.push({{ci+1,cj-1},cdist+1});
            q.push({{ci-1,cj+1},cdist+1});
            q.push({{ci-1,cj-1},cdist+1});
        }       
        return -1;
    }
};