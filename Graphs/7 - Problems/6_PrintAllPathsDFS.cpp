// 6_PrintAllPathsDFS.cpp
// Problem Link - https://leetcode.com/problems/all-paths-from-source-to-target/
// Code Link - 
#include <bits/stdc++.h>
using namespace std;

// Appraoch: DFS 
// TC: O(V+E)
// SC: O(V)
class Solution {
    vector<vector<int>> paths;
public:
    void dfs(vector<vector<int>> &graph, vector<bool> &isvis, int cnode, vector<int> path) {
        isvis[cnode] = true;
        path.push_back(cnode);
        
        // if reached dest
        if(cnode == graph.size()-1) {
            paths.push_back(path);
        }
        
        for(auto nbr: graph[cnode]) {
            if(!isvis[nbr]) dfs(graph, isvis, nbr, path);
        }
        
        // backtracking
        isvis[cnode] = false;
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<bool> isvis(graph.size(), false);
        vector<int> path;
        dfs(graph,isvis,0,path);
        
        return paths;
    }
};