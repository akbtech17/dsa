// 25_ShortestPathWithAlternatingColors.cpp
// Problem Link - 
// Code Link - 
#include <bits/stdc++.h>
using namespace std;

// Appraoch: BFS 
// TC: O(V+E)
// SC: O(V)
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // 0 - red color edge
        // 1 - blue color edge
        vector<vector<pair<int,int>>> adjList(n); // nbr,color
        for(auto e: redEdges) adjList[e[0]].push_back({e[1],0});
        for(auto e: blueEdges) adjList[e[0]].push_back({e[1],1});
        
        // make isvis array
        vector<vector<bool>> isvis(n, vector<bool>(2, false));
        
        // queue
        queue<pair<int,int>> q; // node, color
        q.push({0,0});
        q.push({0,1});
        
        // vis cost
        vector<int> ans(n,INT_MAX);
        ans[0] = 0;
        isvis[0][0] = 1;
        isvis[0][1] = 1;
        
        int dist = 0;
        
        while(!q.empty()) {
            dist++;
            int qs = q.size();
            for(int i=0; i<qs; i++) {
                auto [cnode,ccolor] = q.front();
                q.pop();
                
                int opcolor = ccolor == 0 ? 1 : 0;
                for(auto nbr: adjList[cnode]) {
                    if(nbr.second == opcolor and !isvis[nbr.first][opcolor]) {
                        q.push({nbr.first,opcolor});
                        isvis[nbr.first][opcolor] = true;
                        ans[nbr.first] = min(ans[nbr.first],dist);
                    }
                }
            }
        }
        
        for(auto &el: ans) {
            el = el == INT_MAX ? -1 : el;
        }
        return ans;
    }
};