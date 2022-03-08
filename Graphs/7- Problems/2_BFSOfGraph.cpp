// 2_BFSOfGraph.cpp
// Problem Link - https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
// Code Link - https://ide.codingblocks.com/s/657945
#include<bits/stdc++.h>
using namespace std;

// Approach: BFS
// TC: O(V+E)
// SC: O(V)
class Solution {
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfs;
        vector<bool> isvis(V,false);
        
        queue<int> q;
        q.push(0);
        
        while(!q.empty()) {
            int cnode = q.front();
            q.pop();
            
            if(isvis[cnode]) continue;
            
            isvis[cnode] = true;
            bfs.push_back(cnode);
            
            for(auto nbr: adj[cnode]) q.push(nbr);
        }
        
        return bfs;
    }
};