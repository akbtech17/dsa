// 1_CycleDetectionInUGusingBFS.cpp
// Problem Link -  https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// Code Link - https://ide.codingblocks.com/s/659879
// Resource Link - https://www.youtube.com/watch?v=A8ko93TyOns&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=8&ab_channel=takeUforward
#include <bits/stdc++.h>
using namespace std;

// Approach: Using BFS
// TC: O(N+E) N is the time taken for visiting N nodes and E is for traveling through adjacent nodes.
// SC: O(N+E) + O(N) + O(N) Space for adj list, queue and isvis array 
class Solution {
public:
    bool checkCycleBFS(int cnode, vector<int> *adjList, vector<bool> &isvis) {
        queue<pair<int,int>> q;
        q.push({cnode, -1});   // node-parent
        isvis[cnode] = true;
        
        while(!q.empty()) {
            int cnode = q.front().first, cpar = q.front().second;
            q.pop();
            
            for(auto nbr: adjList[cnode]) {
                if(!isvis[nbr]) {
                    isvis[nbr] = true;
                    q.push({nbr,cnode});
                }
                else {
                    if(nbr != cpar) return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adjList[]) {
        vector<bool> isvis(V, false);
        for(int i=0; i<V; i++) {
            if(!isvis[i]) 
                if(checkCycleBFS(i,adjList,isvis)) return true;
        }
        return false;
    }
};