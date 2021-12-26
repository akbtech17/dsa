// 3_TopologicalSort_DAG_BFS.cpp
#include <bits/stdc++.h>
using namespace std;

// Approach - BFS + Indegree Concept 
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
	vector<T> getTopologicalOrder() {
		vector<T> ts;
		

		for(auto p: adjList) {
			for(auto vertex: p.second) indegree[vertex]++;
		}

		queue<T> q;
		for(auto p: indegree) {
			if(p.second == 0) q.push(p.first);
		}


		while(!q.empty()) {
			T curr = q.front();
			q.pop();
			ts.push_back(curr);
			for(auto nbrs: adjList[curr]) {
				indegree[nbrs]--;
				if(indegree[nbrs] == 0) q.push(nbrs);
			}
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