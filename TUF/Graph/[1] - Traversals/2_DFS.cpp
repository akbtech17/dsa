#include <iostream>
using namespace std;

// TC: O(V+E)
// SC: O(V)
class Solution {
public:
	void recurse(int node, int V, vector<int> adj[], vector<bool> &isvis,
				 vector<int> &traversal) {
		// Recursive Case
		isvis[node] = true;
		traversal.push_back(node);

		for (int nbr : adj[node]) {
			if (!isvis[nbr]) recurse(nbr, V, adj, isvis, traversal);
		}

		return;
	}

	vector<int> dfsOfGraph(int V, vector<int> adj[]) {
		vector<int> traversal;

		vector<bool> isvis(V, false);
		recurse(0, V, adj, isvis, traversal);

		return traversal;
	}
};
