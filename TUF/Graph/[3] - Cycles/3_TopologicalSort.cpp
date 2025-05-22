#include <iostream>
#include <map>
using namespace std;

// TopoSort only works in DAG - Directed Acyclic Graph

// Approach: BFS or Kahn's Algo
// Below solution using BFS for TopSort can also be used to detect cycles in Direct Graphs but not the DFS soltution will work same.

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

// Approach: DFS
// TC: O(V+E)
// SC: O(V)
class Solution {
public:
	void dfs(int node, vector<int> *adj, vector<bool> &isvis, stack<int> &stk) {
		isvis[node] = true;

		for (int nbr : adj[node]) {
			if (isvis[nbr] == false) dfs(nbr, adj, isvis, stk);
		}

		// once the outdegrees of the currNode is processed
		stk.push(node);
	}

	vector<int> topoSort(int V, vector<int> adj[]) {
		vector<int> ans;
		vector<bool> isvis(V, false);
		stack<int> stk;

		for (int i = 0; i < V; i++) {
			if (isvis[i] == false) {
				dfs(i, adj, isvis, stk);
			}
		}

		while (!stk.empty()) {
			int node = stk.top();
			stk.pop();

			ans.push_back(node);
		}

		return ans;
	}
};
