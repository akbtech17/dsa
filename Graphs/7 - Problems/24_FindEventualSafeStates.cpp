// 24_FindEventualSafeStates.cpp
// Problem Link - https://leetcode.com/problems/find-eventual-safe-states/
// Code Link - https://ide.codingblocks.com/s/659882
// Resource Link - https://www.youtube.com/watch?v=4ymVOCiQBtw&t=682s&ab_channel=HelloWorld
#include <bits/stdc++.h>
using namespace std;

// Approach: Using DFS Cycle Check in Directed Graph
// TC: O(N+E) N is the time taken for visiting N nodes and E is for traveling through adjacent nodes.
// SC: O(N+E) + O(N) + O(N) + O(N) + O(N) Space for adj list, isvis array, dfsvis array, is_part_of_cycle array and aux. 
class Solution {
public:
    bool checkCycleDFS(int cnode, vector<vector<int>> &adjList, vector<bool> &isvis, vector<bool> &dfsvis, vector<bool> &is_part_of_cycle) {
        isvis[cnode] = true;
        dfsvis[cnode] = true;

        for(auto nbr: adjList[cnode]) {
            if(!isvis[nbr]) {
                if(checkCycleDFS(nbr, adjList, isvis,dfsvis,is_part_of_cycle)) 
                    return is_part_of_cycle[cnode] = true;
            }
            
            else if(isvis[nbr] and dfsvis[nbr]) 
                return is_part_of_cycle[cnode] = true;

        }
        
        // backtracking step
        dfsvis[cnode] = false;
        return false;
    }
    
    vector<int> eventuhttps://ide.codingblocks.com/s/659882alSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> isvis(n, false), dfsvis(n, false), is_part_of_cycle(n, false);
        vector<int> ans;
        
        for(int i=0; i<n; i++) {
            if(!isvis[i]) {
                checkCycleDFS(i,graph,isvis,dfsvis,is_part_of_cycle); 
            }
        }
        
        for(int i=0; i<n; i++) if(!is_part_of_cycle[i]) ans.push_back(i);
        return ans;
    }
};