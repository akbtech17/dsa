// 1_PrintAdjacencyList.cpp
// Problem Link - https://practice.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1#
// Code Link - https://ide.codingblocks.com/s/657943
#include<bits/stdc++.h>
using namespace std;

// Approach: Traverse the given adj list, and clone it.
// TC: O(V+E)
// SC: O(V+E)
class Solution {
public:
    vector<vector<int>> printGraph(int V, vector<int> adj[]) {
        vector<vector<int>> clone(V);
        for(int i=0; i<V; i++) {
            clone[i].push_back(i);   // imp
            for(auto nbr: adj[i]) clone[i].push_back(nbr);
        } 
        return clone;
    }
};