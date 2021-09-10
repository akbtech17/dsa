// 3_SumOfDisOfAllNodes.cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
	vector<vector<int>> adjList;   // adjecency list
	vector<int> res;               // stores the sum of distance to all nodes in the subtree
	vector<int> count;             // stores the total count of nodes in tge subtree

public:
	void dfs(int root, int pre) {
		for(auto nbr : adjList[root]) {
			if(nbr == pre) continue;
			dfs(nbr,root);
			count[root] += count[root];
			res[root] += res[root] + count[root];
		}
	}
    vector<int> sumOfDistancesInTree(int V, vector<vector<int>>& edges) {
        // creating adjecencyList from the EdgeList
        adjList.resize(V);
        for(auto edge : edges) {
        	int x = edge[0];
        	int y = edge[1];
        	// we will treat the edge as Undirected Edge
        	adjList[x].push_back(y);
        	adjList[y].push_back(x);
        }
    }
};