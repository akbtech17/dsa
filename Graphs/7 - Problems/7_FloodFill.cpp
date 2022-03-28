// 7_FloodFill.cpp
// Problem Link - https://leetcode.com/problems/flood-fill/
// Code Link - https://ide.codingblocks.com/s/657948
#include<bits/stdc++.h>
using namespace std;

// Approach: BFS
// TC: O(V+E)
// SC: O(V)
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size(), n = image[0].size();
        vector<vector<bool>> isvis(m, vector<bool>(n,false));
        
        queue<pair<int,int>> q;
        int pc = image[sr][sc];
        q.push({sr,sc});
        
        while(!q.empty()) {
            int i = q.front().first, j = q.front().second;
            q.pop();
            
            // check bounds
            if(i<0 or i>=image.size() or j<0 or j>=image[0].size()) continue;
            if(isvis[i][j]) continue;
            if(image[i][j] != pc) continue;
            
            // change color
            image[i][j] = newColor;
            isvis[i][j] = true;
            // push_its_neighbors
            q.push({i-1,j});
            q.push({i+1,j});
            q.push({i,j-1});
            q.push({i,j+1});

        }
        return image;
    }
};