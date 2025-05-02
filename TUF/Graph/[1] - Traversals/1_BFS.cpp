#include <iostream>
using namespace std;

// TC: O(V+E)
// SC: O(V)
class Solution {
public:
	vector<int> bfsOfGraph(int V, vector<int> adj[]) {
		vector<int> traversal;

		vector<bool> isvis(V, false);
		queue<int> q;

		q.push(0);
		isvis[0] = true;

		while (!q.empty()) {
			int cnode = q.front();
			q.pop();
			traversal.push_back(cnode);

			for (int nbr : adj[cnode]) {
				if (!isvis[nbr]) {
					q.push(nbr);
					isvis[nbr] = true;
				}
			}
		}

		return traversal;
	}
};
