#include <iostream>
using namespace std;

// TC: O(V+E)
// SC: O(V+E) : Extra E space to store AdjList
class Solution {
public:
	vector<vector<int>> getAdjList(vector<vector<int>> &adjMatrix) {
		int n = adjMatrix.size(); // number of vertices
		vector<vector<int>> adjList(n);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (adjMatrix[i][j] == 1) {
					adjList[i].push_back(j);
					adjList[j].push_back(i);
				}
			}
		}

		return adjList;
	}

	void runBFS(int src, vector<vector<int>> &adjList, vector<bool> &isvis) {
		queue<int> q;
		q.push(src);
		isvis[src] = true;

		while (!q.empty()) {
			int currNode = q.front();
			q.pop();

			for (int nbr : adjList[currNode]) {
				if (!isvis[nbr]) {
					q.push(nbr);
					isvis[nbr] = true;
				}
			}
		}

		return;
	}

	int numProvinces(vector<vector<int>> adj) {
		int ans = 0;

		int n = adj.size(); // number of vertices
		vector<vector<int>> adjList = getAdjList(adj);
		vector<bool> isvis(n, false);

		for (int i = 0; i < n; i++) {
			if (!isvis[i]) {
				ans += 1;
				runBFS(i, adjList, isvis);
			}
		}

		return ans;
	}
};
