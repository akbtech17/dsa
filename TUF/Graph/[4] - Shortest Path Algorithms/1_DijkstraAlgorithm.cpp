#include <iostream>
#define P pair<int, int>
using namespace std;

// Problem Statement
// Given: 	Wighted Undirected Graph of V vertices
// 			Source Node
// Find: 	Shortest distance b/w Source Node to all other Nodes
//			If vertext is not reachable, distance will be 10^9

// Dijkstra's Algorithm is used in connected graphs (undirected as well as
// directed) whenever it is required to find out the shortest distance from the
// source node to every other node.

// Note - The graph must only have non-negative edge weights.

// Approach1: Using Priority Queue - Min Heap
// TC: O(V+E)*Log(V)
// SC: O(V)
class Solution {
public:
	vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
		vector<int> dist(V, 1e9);
		priority_queue<P, vector<P>, greater<P>> pq;

		pq.push({0, S});
		dist[S] = 0;

		while (!pq.empty()) {
			P currNode = pq.top();
			pq.pop();

			for (vector<int> nbrNode : adj[currNode.second]) {
				int distToNbr = nbrNode[1] + currNode.first;
				if (distToNbr < dist[nbrNode[0]]) {
					dist[nbrNode[0]] = distToNbr;
					pq.push({distToNbr, nbrNode[0]});
				}
			}
		}

		return dist;
	}
};