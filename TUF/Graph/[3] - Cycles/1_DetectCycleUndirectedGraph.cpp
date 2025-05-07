#include <iostream>
using namespace std;

// Approach: BFS
// TC: O(V+E)
// SC: O(V)
class Solution {
public:
	bool bfs(int src, int V, vector<int> *adj, vector<bool> &isvis) {
		queue<pair<int, int>> q; // node-parent

		q.push({src, -1});
		isvis[src] = true;

		while (!q.empty()) {
			pair<int, int> currNode = q.front();
			q.pop();

			for (int nbr : adj[currNode.first]) {
				if (!isvis[nbr]) {
					isvis[nbr] = true;
					q.push({nbr, currNode.first});
				} else if (currNode.second != nbr)
					return true;
			}
		}

		return false;
	}

	bool isCycle(int V, vector<int> adj[]) {
		vector<bool> isvis(V, false);

		for (int i = 0; i < V; i++) {
			if (!isvis[i] && bfs(i, V, adj, isvis)) return true;
		}

		return false;
	}
};

// Approach: DFS
// TC: O(V+E)
// SC: O(V)
class Solution {
public:
	bool dfs(int src, int parent, vector<int> *adj, vector<bool> &isvis) {
		isvis[src] = true;

		for (int nbr : adj[src]) {
			if (!isvis[nbr]) {
				if (dfs(nbr, src, adj, isvis)) return true;
			} else if (parent != nbr)
				return true;
		}

		return false;
	}

	bool isCycle(int V, vector<int> adj[]) {
		vector<bool> isvis(V, false);

		for (int i = 0; i < V; i++) {
			if (!isvis[i] && dfs(i, -1, adj, isvis)) return true;
		}

		return false;
	}
};