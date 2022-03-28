// 28_IsGraphBipartite.cpp
// Problem Link - https://leetcode.com/problems/is-graph-bipartite/
// Code Link - 
// Resource Link - https://www.youtube.com/watch?v=nbgaEu-pvkU&ab_channel=takeUforward
#include <bits/stdc++.h>
using namespace std;

// Approach: Using BFS Traversal
// TC: O(N+E) N is the time taken for visiting N nodes and E is for traveling through adjacent nodes.
// SC: O(N+E) + O(N) + O(N) Space for adj list, color array and queue. 

// -1 => unvis
//  0 => red color
//  1 => blue color
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        
        for(int i=0; i<n; i++) {
            if(color[i] == -1) {
                // start bfs
                queue<int> q;
                q.push(i);
                color[i] = 0; // start with red color
                
                while(!q.empty()) {
                    int cnode = q.front();
                    int ccolor = color[cnode];
                    q.pop();
                    
                    for(auto nbr: graph[cnode]) {
                        if(color[nbr] == -1) {
                            // unvis
                            color[nbr] = ccolor == 0 ? 1 : 0;
                            q.push(nbr);
                        }
                        else {
                        	// if contradicts the cond, return false
                            if(color[nbr] == ccolor) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};