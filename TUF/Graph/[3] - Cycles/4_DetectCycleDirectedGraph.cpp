#include <iostream>
#include <map>
using namespace std;

// Approach: Topological Sort using BFS
// TC: O(V+E)
// SC: O(V)
class Solution {
public:
	vector<int> topologicalSort(int V, vector<int> *adj) {
		vector<int> topoSort;

		unordered_map<int, int> indegree;
		for (int i = 0; i < V; i++) {
			for (int j : adj[i])
				indegree[j]++;
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) q.push(i);
		}

		while (!q.empty()) {
			int node = q.front();
			topoSort.push_back(node);
			q.pop();

			for (int nbr : adj[node]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0) {
					q.push(nbr);
				}
			}
		}

		return topoSort;
	}

	bool isCyclic(int V, vector<int> adj[]) {
		vector<int> topoSort = topologicalSort(V, adj);
		return topoSort.size() != V;
	}
};
