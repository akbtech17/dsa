// 16_Dijkstra.cpp - shortest path from source to all other nodes
// Question - https://practice.geeksforgeeks.org/problems/handshakes1303/1
// Code - https://ide.codingblocks.com/s/653979
// Resource - https://www.youtube.com/watch?v=jbhuqIASjoM&t=1129s
#include <bits/stdc++.h>
using namespace std;

// Approach: Using BFS with PQ
// Type of Graph: Weighted, Undirected and Connected (UWG)
// Given: No Negative Cycle will be present
// TC: O((N+E)logN) 
// SC: O(2N)

class Solution {
public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {

        // define pq, to get node with the least distTo cost at any point of time {distTo,node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        // initially, mark distTo from source to each node as INFINITY
        vector<int> distTo(V,INT_MAX);
        
        // push the source vertex
        pq.push({0,S});
        distTo[S] = 0;
        
        // traverse the adj list,
        while(!pq.empty()) {
            int cdist = pq.top().first;
            int cnode = pq.top().second;
            pq.pop();
            
            for(auto nbrs: adj[cnode]) {
                int nnode = nbrs[0];
                int ndist = nbrs[1];
                

                // if the curr cost is less than the 
                // prev cost, we will update accordingly
                // and also push the associated node 
                // with updated cost
                if(cdist+ndist < distTo[nnode]) {
                    distTo[nnode] = cdist+ndist;
                    pq.push({distTo[nnode],nnode});
                }
            }
        }
        
        return distTo;
    }
};