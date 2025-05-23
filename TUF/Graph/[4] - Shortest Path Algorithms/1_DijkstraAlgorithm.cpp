#include <iostream>
#include <set>
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
// TC: O(E*Log(V))
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

// Approach1: Using Set
// TC: O(V+E)
// SC: O(V)
class Solution {
public:
	vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
		vector<int> dist(V, 1e9);
		set<P> st;

		st.insert({0, S});
		dist[S] = 0;

		while (!st.empty()) {
			P currNode = *(st.begin());
			st.erase(st.begin());

			for (vector<int> nbrNode : adj[currNode.second]) {
				int distToNbr = nbrNode[1] + currNode.first;
				if (distToNbr < dist[nbrNode[0]]) {
					dist[nbrNode[0]] = distToNbr;
					st.insert({distToNbr, nbrNode[0]});
				}
			}
		}

		return dist;
	}
};

// Q: Why not use Queue, why PQ / Set?
// A: If we use Queue, there might be traversal of all possible path, which may end taking longer time.
//    While using PQ / Set we make sure to explore the node with less weight first (greedy - minimal first), which eliminates other / unnecessary paths which we may have to traverse if we go with Queue.

// Q: Why time complexity E*Log(V)
// 	  while(pq.empty()) - we can say it will run at max for V nodes
// 	  		pq.top() - log(max heap size)
//  		ne - no of edges connected to Node - worst case (V - 1) in dense graph
// 				pq.push() - log(max heap size)

// This can be written as below
// TC 	= V * (log(max_heap_size) + ne * log(max_heap_size))
// 		= V * ((ne+1)*log(max_heap_size))     
// 		= V * V * log (max_heap_size) as ne = V-1 in worst case
// 		= V^2 * log(V^2) as max_heap_size = V^2 is everyone is pushing everyone in PQ
// 		= 2*V^2 * log(V)
// 		= E*log(V) as E = 2 V

// E = 2V
// If all nodes are connected to all nodes, then Edges = (V-1) * V = V^2