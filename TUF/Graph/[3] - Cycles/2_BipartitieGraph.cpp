#include <iostream>
using namespace std;

// Approach: BFS
// TC: O(V+E)
// SC: O(V)
class Solution {
public:
	bool runBFS(int src, vector<int> *adj, vector<int> &color) {
		queue<int> q;
		q.push(src);
		color[src] = 0;

		while (!q.empty()) {
			int currNode = q.front();
			q.pop();

			for (int nbr : adj[currNode]) {
				if (color[nbr] == -1) {
					q.push(nbr);
					color[nbr] = !color[currNode];
				} else if (color[nbr] == color[currNode])
					return false;
			}
		}

		return true;
	}

	bool isBipartite(int V, vector<int> adj[]) {
		vector<int> color(V, -1);

		for (int i = 0; i < V; i++) {
			if (color[i] == -1) {
				bool ans = runBFS(i, adj, color);
				if (!ans) return false;
			}
		}
		return true;
	}
};
