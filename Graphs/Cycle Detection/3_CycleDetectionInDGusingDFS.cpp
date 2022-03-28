// 3_CycleDetectionInDGusingDFS.cpp
// Problem Link - https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/#
// Code Link - https://ide.codingblocks.com/s/659881
// Resource Link - https://www.youtube.com/watch?v=uzVUw90ZFIg&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=12&ab_channel=takeUforward
#include <bits/stdc++.h>
using namespace std;

// Approach: Using DFS
// TC: O(N+E) N is the time taken for visiting N nodes and E is for traveling through adjacent nodes.
// SC: O(N+E) + O(N) + O(N) + O(N) Space for adj list, isvis array, dfsvis array and aux. 
class Solution {
public:
    bool checkCycleDFS(int cnode, vector<int>* adjList, vector<bool> &isvis, vector<bool> &dfsvis) {
        isvis[cnode] = true;
        dfsvis[cnode] = true;
        
        for(auto nbr: adjList[cnode]) {
            if(!isvis[nbr]) {
            	if(checkCycleDFS(nbr, adjList, isvis,dfsvis)) 
            		return true;
            }
            else {
                if(dfsvis[nbr]) return true;
            }
        }
        
        // backtracking
        dfsvis[cnode] = false;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> isvis(V, false);
        for(int i=0; i<V; i++) 
            if(!isvis[i]) {
                vector<bool> dfsvis(V,false);
                if(checkCycleDFS(i,adj,isvis,dfsvis))
                    return true;
            }
        return false;
    }
};