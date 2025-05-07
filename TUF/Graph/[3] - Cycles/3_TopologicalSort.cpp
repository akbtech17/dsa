#include <iostream>
#include <map>
using namespace std;

// Approach: BFS or Kahn's Algo
// TC: O(V+E)
// SC: O(V)
class Solution {
public:
	vector<int> topoSort(int V, vector<int> adj[]) {
		vector<int> ans;

		map<int, int> mp; // node-indegree
		for (int u = 0; u < V; u++) {
			for (int v : adj[u]) {
				mp[v]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (mp[i] == 0) q.push(i);
		}

		while (!q.empty()) {
			int currNode = q.front();
			ans.push_back(currNode);
			q.pop();

			for (int nbr : adj[currNode]) {
				mp[nbr]--;
				if (mp[nbr] == 0) q.push(nbr);
			}
		}

		return ans;
	}
};
