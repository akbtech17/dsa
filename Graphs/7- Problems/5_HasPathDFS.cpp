// 5_HasPathDFS.cpp
// Problem Link - https://leetcode.com/problems/find-if-path-exists-in-graph/
// Code Link - https://ide.codingblocks.com/s/657965
#include<bits/stdc++.h>
using namespace std;

// Approach: DFS
// TC: O(V+E)
// SC: O(V)
class Solution {
public:
    bool recurse(vector<vector<int>> &adjList, int cnode, int dest, vector<bool> &isvis) {
        if(isvis[cnode]) return false;
        if(cnode == dest) return true;
        
        isvis[cnode] = true;
        for(auto nbr: adjList[cnode]) {
            bool ans = recurse(adjList,nbr,dest,isvis);
            if(ans) return true;
        }
        
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        // 1. make adj list
        vector<vector<int>> adjList(n);
        
        for(auto edge: edges) {
            int x = edge[0], y = edge[1];
            
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }
        
        // 2. now recurse to check if we can reach dest from src
        vector<bool> isvis(n,false);
        return recurse(adjList, src, dest, isvis);
    }
};