#include <iostream>
#include <set>
#define P pair<int, int>
using namespace std;

// Approach1: Using Priority Queue - Min Heap
// TC: O(E*Log(V))
// SC: O(V)
class Solution {
public:
	vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {
		vector<int> path;

		// 1. Prepare adjList
		vector<vector<P>> adjList(n + 1);
		for (vector<int> edge : edges) {
			adjList[edge[0]].push_back({edge[1], edge[2]});
			adjList[edge[1]].push_back({edge[0], edge[2]});
		}

		// 2. Run Dijkstra's Algorithm
		vector<int> dist(n + 1, 1e9);
		vector<int> parent(n + 1);
		priority_queue<P, vector<P>, greater<P>> pq;

		// Initially parent of each node will be node itself
		for (int i = 1; i <= n; i++)
			parent[i] = i;

		pq.push({0, 1});
		dist[1] = 0;

		while (!pq.empty()) {
			P currNode = pq.top();
			pq.pop();

			for (P nbrNode : adjList[currNode.second]) {
				int distToNbr = currNode.first + nbrNode.second;
				if (distToNbr < dist[nbrNode.first]) {
					dist[nbrNode.first] = distToNbr;
					pq.push({distToNbr, nbrNode.first});
					parent[nbrNode.first] = currNode.second;
				}
			}
		}

		// 3. Check if target node is not rechable
		if (dist[n] == 1e9) return {-1};

		// 4. Extract the path from parent array
		int node = n;
		while (node != parent[node]) {
			path.push_back(node);
			node = parent[node];
		}
		path.push_back(node);

		reverse(path.begin(), path.end());
		path.insert(path.begin(), dist[n]);

		return path;
	}
};