// 18_NearestExitFromEntranceInMaze.cpp
// Problem Link - https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
// Code Link - https://ide.codingblocks.com/s/658509
#include <bits/stdc++.h>
using namespace std;

// Approach: Multisource BFS 
// TC: O(MN)
// SC: O(MN)
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<pair<int,int>,int>> q;
        
        int m = maze.size(), n = maze[0].size();
        vector<vector<bool>> isvis(m, vector<bool>(n, false));
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i==entrance[0] and j==entrance[1]) continue;
                if(i == 0 or i == m-1 or j == 0 or j == n-1) q.push({{i,j},0});       
            }
        }
        
        while(!q.empty()) {
            int ci = q.front().first.first, cj = q.front().first.second;
            int cdist = q.front().second;
            q.pop();
            
            if(ci<0 or ci>=m or cj<0 or cj>=n) continue;
            if(isvis[ci][cj] or maze[ci][cj] == '+') continue;
            
            if(ci == entrance[0] and cj == entrance[1]) return cdist;
            
            isvis[ci][cj] = true;
            
            q.push({{ci+1,cj},cdist+1});
            q.push({{ci-1,cj},cdist+1});
            q.push({{ci,cj+1},cdist+1});
            q.push({{ci,cj-1},cdist+1});
        }
        
        return -1;
    }
};