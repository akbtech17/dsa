// 14_01Matrix.cpp
// Problem Link - https://leetcode.com/problems/01-matrix/
// Code Link - https://ide.codingblocks.com/s/658304
#include<bits/stdc++.h>
using namespace std;

// Q: Find the distance of the nearest 0 for each cell.

// A1: Bruteforce (TLE)
//     For each 1 cell run bfs to find the nearest 0 cell, and save the answer.
// TC: O(N^4)
// SC: O(N^2)

// A2: Multisource BFS in Reverse Order (Accepted)
//     From 0 cells run bfs, and update the ans for each 1 cell.
// TC: O(N^2)
// SC: O(N^2)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<bool>> isvis(m, vector<bool>(n, false));
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] == 0) {
                    q.push({{i,j},0});
                }
            }
        }
        
        while(!q.empty()) {
            int ci = q.front().first.first, cj = q.front().first.second;
            int cdist = q.front().second;
            q.pop();
            
            if(ci<0 or ci>=m or cj<0 or cj>=n) continue;
            if(isvis[ci][cj]) continue;
            
            isvis[ci][cj] = true;
            mat[ci][cj] = cdist;
            
            q.push({{ci+1,cj},cdist+1});
            q.push({{ci-1,cj},cdist+1});
            q.push({{ci,cj+1},cdist+1});
            q.push({{ci,cj-1},cdist+1});
        }
        
        return mat;
    }
};