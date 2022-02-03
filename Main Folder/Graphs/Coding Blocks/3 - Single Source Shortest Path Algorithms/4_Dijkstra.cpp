// 16_Dijkstra.cpp - shortest path from source to all other nodes
// Question - https://practice.geeksforgeeks.org/problems/handshakes1303/1
// Code - 
// Resource - https://www.youtube.com/watch?v=jbhuqIASjoM&t=1129s
#include <bits/stdc++.h>
using namespace std;

// Approach: Using BFS with PQ
// Type of Graph: Weighted, Undirected and Connected
// Given: No Negative Cycle will be present
// TC: O(V*V) 
// SC: O(V)

// custom comparator for pq to sort wrt to dist, min heap
class MyComp {
public:
    bool operator()(pair<int,int> const& p1, pair<int,int> const& p2) {
        return p1.second > p2.second;        
    }
};

class Solution {
public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {

        // define pq, to get node with the least dist cost at any point of time
        priority_queue<pair<int,int>, vector<pair<int,int>>, MyComp> pq;
        
        // initially, mark dist from source to each node as INFINITY
        vector<int> dist(V,INT_MAX);
        
        // push the source vertex
        pq.push({S,0});
        dist[S] = 0;
        
        // iterate in bfs fashion
        while(!pq.empty()) {
            int cnode = pq.top().first;
            int cdist = pq.top().second;
            pq.pop();
            
            for(auto nbrs: adj[cnode]) {
                int nnode = nbrs[0];
                int nweight = nbrs[1];
                
                int dist_so_far = dist[nnode];

                // if the curr cost is less than the 
                // orev cost, we will update accordingly
                // and also push the associated node 
                // with updated cost
                if(cdist+nweight < dist[nnode]) {
                    dist[nnode] = cdist+nweight;
                    pq.push({nnode,dist[nnode]});
                }
            }
        }
        
        return dist;
    }
};