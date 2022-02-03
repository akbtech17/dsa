// 2_TopologicalSort_DAG_DFS.cpp
#include <bits/stdc++.h>
using namespace std;

// Approach - DFS + Indegree Concept 
// TC - O(V+E)
// SC - O(V+E)
template<typename T>
class Graph {
	unordered_map<T,vector<T>> adjList;
	unordered_map<T,int> indegree;
public:
	void addEdge(T src, T dest) {
		adjList[src].push_back(dest);
		indegree[src] = 0;
		indegree[dest] = 0;
		return;
	}
	void dfs(T src, vector<T> &ts) {
		ts.push_back(src);
		for(auto nbrs: adjList[src]) {
			indegree[nbrs]--;
			if(indegree[nbrs] == 0) dfs(nbrs,ts);
		}
		return;
	}
	vector<T> getTopologicalOrder() {
		vector<T> ts;
		
		for(auto p: adjList) {
			for(auto v: p.second) indegree[v]++;
		}

		vector<T> src;
		for(auto p: indegree) {
			if(p.second == 0) src.push_back(p.first);
		}

		for(auto s: src) {
			dfs(s,ts);
		}

		return ts;
	}
};

int main() {
	Graph<string> G;
	G.addEdge("Python","DataProcessing");
	G.addEdge("Python","PyTorch");
	G.addEdge("DataProcessing","ML");
	G.addEdge("PyTorch","DL");
	G.addEdge("ML","DL");
	G.addEdge("DataSet","FaceRecog");
	G.addEdge("DL","FaceRecog");

	vector<string> ts = G.getTopologicalOrder();
	for(auto str: ts) cout<<str<<endl;
	return 0;
}
