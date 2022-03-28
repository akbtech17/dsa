// 2_CycleDetectionInUGusingDFS.cpp
// Problem Link - https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// Code Link - https://ide.codingblocks.com/s/659880
// Resource Link - https://www.youtube.com/watch?v=Y9NFqI6Pzd4&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=9&ab_channel=takeUforward
#include <bits/stdc++.h>
using namespace std;

// Approach: Using DFS
// TC: O(N+E) N is the time taken for visiting N nodes and E is for traveling through adjacent nodes.
// SC: O(N+E) + O(N) + O(N) Space for adj list, isvis array and aux. 
class Solution {
public:
    bool checkCycleDFS(int cnode, int cpar, vector<int> *adjList, vector<bool> &isvis) {
        isvis[cnode] = true;
        
        bool ans = false;
        for(auto nbr: adjList[cnode]) {
            if(!isvis[nbr]) {
                ans = ans or checkCycleDFS(nbr,cnode,adjList,isvis);
            }
            else {
                if(nbr!=cpar) return true;
            }
        }
        return ans;
    }
    bool isCycle(int V, vector<int> adjList[]) {
        vector<bool> isvis(V, false);
        for(int i=0; i<V; i++) {
            if(!isvis[i]) 
                if(checkCycleDFS(i,-1,adjList,isvis)) return true;
        }
        return false;
    }
};