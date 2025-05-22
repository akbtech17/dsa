#include <iostream>
#include <map>
using namespace std;

// Approach: Topological Sort using BFS
// We know a fact that topological sort are only applicable to DAG
// If we apply it on DCG, the toposort result will never be equivalent to no of
// nodes Note - It will not work with DFS topological sort algo, unless we are
// explicity checking for back edges

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

// Approach: DFS
// With vis track, we need to track path too, if the vis node is in the same
// path again, that means cycle is there. It is bit different with TopoSort,
// forget that - we are applying simple DFS with path vis array :) DFS TopoSort
// will not work, due to not tracking of backedges

// TC: O(V+E)
// SC: O(V)
class Solution {
public:
	bool dfs(int node, vector<int> *adj, vector<bool> &isvis,
			 vector<bool> &pathVisited) {
		isvis[node] = true;
		pathVisited[node] = true;

		for (int nbr : adj[node]) {
			if (isvis[nbr] == false) {
				bool hasCycle = dfs(nbr, adj, isvis, pathVisited);
				if (hasCycle) return true;
			} else {
				if (pathVisited[nbr]) return true;
			}
		}

		// bactrack
		pathVisited[node] = false;
		return false;
	}

	bool isCyclic(int V, vector<int> adj[]) {
		vector<bool> isvis(V, false);
		vector<bool> pathVisited(V, false);

		for (int i = 0; i < V; i++) {
			if (!isvis[i]) {
				// If a cycle is found, return true
				if (dfs(i, adj, isvis, pathVisited)) return true;
			}
		}

		return false;
	}
};
