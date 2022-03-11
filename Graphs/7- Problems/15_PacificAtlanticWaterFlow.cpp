// 15_PacificAtlanticWaterFlow.cpp
// Problem Link - https://leetcode.com/problems/pacific-atlantic-water-flow/
// Code Link - https://ide.codingblocks.com/s/658305

// Q:
// 1: The matrix is the continent with water on it and the boundaries are the oceans. Left and top being Pacific and right and bottom being the Atlantic.
// 2: The water on the continent (in the matrix) wants to flow out in the ocean. (Nature huh.)
// 3: The numbers in the matrix is the height of the water for that point.
// 4: For every point you have to ask the question. Can the water at this point and this height flow out in both the oceans under the constraints of flowing through only four(up, down, right, left) directions and flow into channels with same height or less height?
// 5: If yes you return the coordinate of that point. Else you ignore it.
#include <bits/stdc++.h>
using namespace std;

// A1: Bruteforce (TLE)
//     For each cell run bfs to check if it contributes to both the ocean or not.
//     If yes, add it to our ans.
// TC: O(N^4)
// SC: O(N^2)
class Solution1 {
public:
    bool canTouch(vector<vector<int>>& heights, int m, int n, int i, int j) {
        queue<pair<pair<int,int>,int>> q;
        vector<vector<bool>> isvis(m, vector<bool>(n, false));
        
        bool paci = false, atlanti = false;
        
        q.push({{i,j},INT_MAX});
        int cr = heights[i][j];
        
        while(!q.empty()) {
            int ci = q.front().first.first, cj = q.front().first.second;
            int pm = q.front().second;
            
            q.pop();
            
            if(ci<0 or cj<0) {
                paci = true;
                continue;
            }
            if(ci>=m or cj>=n) {
                atlanti = true;
                continue;
            }
            if(isvis[ci][cj]) continue;
            if(heights[ci][cj] > pm) continue;
            
            // if(i == 2 and j == 1) cout<<ci<<" "<<cj<<endl;
            isvis[ci][cj] = true;
            
            q.push({{ci+1,cj},heights[ci][cj]});
            q.push({{ci-1,cj},heights[ci][cj]});
            q.push({{ci,cj+1},heights[ci][cj]});
            q.push({{ci,cj-1},heights[ci][cj]});
        }
        
        return paci and atlanti;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans; 
        int m = heights.size(), n = heights[0].size();
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(canTouch(heights,m,n,i,j)) ans.push_back(vector<int>({i,j}));
            }
        }
        
        return ans;
    }
};

// A2: Multisource BFS in Reverse Order (Accepted)
//     Run BFS from each border cell of Pacific and Atlantic border cells seperately
//     and check who all cells are being reachable to the specific borders
//     take the intersection of those cells and return those cells as an answer.
// TC: O(N^2)
// SC: O(N^2)
class Solution2 {
public:
    void run_bfs(vector<vector<int>>& heights, queue<pair<int,int>> &q, vector<vector<bool>> &isvis) {
        int m = heights.size(), n = heights[0].size();
        while(!q.empty()) {
            int ci = q.front().first, cj = q.front().second;
            q.pop();
            
            vector<pair<int,int>> dir({{1,0},{-1,0},{0,1},{0,-1}});
            
            for(auto d: dir) {
                int x = ci + d.first;
                int y = cj + d.second;
                
                if(x<0 or x>=m or y<0 or y>=n or isvis[x][y]) continue;
                if(heights[x][y] < heights[ci][cj]) continue;
                
                isvis[x][y] = true;
                q.push({x,y});
            }  
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int m = heights.size(), n = heights[0].size();
        if(m == 0 or n == 0) return ans;
        
        queue<pair<int,int>> pq, aq;
        vector<vector<bool>> pvis(m, vector<bool>(n, false));
        vector<vector<bool>> avis(m, vector<bool>(n, false));
        
        // vertical border
        for(int i=0; i<m; i++) {
            pq.push({i,0});            
            pvis[i][0] = true;
            
            aq.push({i,n-1});
            avis[i][n-1] = true;
        }
        
        // horizontal border
        for(int i=0; i<n; i++) {
            pq.push({0,i});            
            pvis[0][i] = true;
            
            aq.push({m-1,i});
            avis[m-1][i] = true;
        }
    
        run_bfs(heights, pq, pvis);
        run_bfs(heights, aq, avis);
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(pvis[i][j] and avis[i][j]) 
                    ans.push_back(vector<int>({i,j}));
            }
        }
        
        return ans;
    }
};


// A3: Multisource BFS in Reverse Order (Accepted)
//     Same approach, but slightly different implementation.
// TC: O(N^2)
// SC: O(N^2)
class Solution3 {
public:
    void run_bfs(vector<vector<int>>& heights, queue<pair<pair<int,int>,int>> &q, vector<vector<bool>> &isvis) {
        int m = heights.size(), n = heights[0].size();
        while(!q.empty()) {
            int ci = q.front().first.first, cj = q.front().first.second;
            int pht = q.front().second;
            q.pop();
            
            if(ci<0 or ci>=m or cj<0 or cj>=n or isvis[ci][cj]) continue;
            if(pht > heights[ci][cj]) continue;
            
            isvis[ci][cj] = true;

            q.push({{ci+1,cj}, heights[ci][cj]});
            q.push({{ci-1,cj}, heights[ci][cj]});
            q.push({{ci,cj+1}, heights[ci][cj]});
            q.push({{ci,cj-1}, heights[ci][cj]});
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int m = heights.size(), n = heights[0].size();
        if(m == 0 or n == 0) return ans;
        
        queue<pair<pair<int,int>,int>> pq, aq;
        vector<vector<bool>> pvis(m, vector<bool>(n, false));
        vector<vector<bool>> avis(m, vector<bool>(n, false));
        
        // vertical border
        for(int i=0; i<m; i++) {
            pq.push({{i,0},INT_MIN});            
            aq.push({{i,n-1},INT_MIN});
        }
        
        // horizontal border
        for(int i=0; i<n; i++) {
            pq.push({{0,i},INT_MIN});            
            aq.push({{m-1,i},INT_MIN});
        }
    
        run_bfs(heights, pq, pvis);
        run_bfs(heights, aq, avis);
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(pvis[i][j] and avis[i][j]) 
                    ans.push_back(vector<int>({i,j}));
            }
        }
        return ans;
    }
};