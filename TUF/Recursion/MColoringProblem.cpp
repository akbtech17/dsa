#include <iostream>
using namespace std;

// Approach: Recursion + Backtracking
// TC: O(M^N)
// SC: O(N)
class Solution {
public:
	bool isPossible(int node, int color, vector<vector<int>> &adjList,
					vector<int> &colors) {
		for (int nbr : adjList[node]) {
			if (colors[nbr] == color) return false;
		}
		return true;
	}

	bool recurse(int node, vector<vector<int>> &adjList, vector<int> &colors,
				 int m, int n) {
		// base case
		if (node == n) return true;

		// recursive case
		for (int color = 1; color <= m; color++) {
			if (isPossible(node, color, adjList, colors)) {
				colors[node] = color;
				if (recurse(node + 1, adjList, colors, m, n)) return true;
				colors[node] = -1;
			}
		}
		// no color can be assgined
		return false;
	}

	bool graphColoring(vector<vector<int>> &edges, int m, int n) {
		vector<vector<int>> adjList(n);

		for (vector<int> edge : edges) {
			adjList[edge[0]].push_back(edge[1]);
			adjList[edge[1]].push_back(edge[0]);
		}

		vector<int> colors(n, -1);

		return recurse(0, adjList, colors, m, n);
	}
};