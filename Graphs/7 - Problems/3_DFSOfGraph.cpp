// 3_DFSOfGraph.cpp
// Problem Link - https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1#
// Code Link - https://ide.codingblocks.com/s/657947
#include<bits/stdc++.h>
using namespace std;

// Approach: DFS
// TC: O(V+E)
// SC: O(V)
class Solution {
    vector<int> dfs;
  public:
    void recurse(vector<int> adj[], int cnode, vector<bool> &isvis) {
        if(isvis[cnode]) return;
        
        dfs.push_back(cnode);
        isvis[cnode] = true;
        
        for(auto nbr: adj[cnode]) recurse(adj,nbr,isvis);
        return;
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> isvis(V,false);
        recurse(adj,0,isvis);
        return dfs;
    }
};