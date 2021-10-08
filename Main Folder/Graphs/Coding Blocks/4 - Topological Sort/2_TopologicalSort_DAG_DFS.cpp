#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph {
	unordered_map<T,vector<T>> adjList;
public:
	void addEdge(T src, T dest) {
		adjList[src].push_back(dest);
		// adjList[dest].push_back(src);
	}
	void recurse(T src, unordered_map<T,bool> &isvis, list<T> &ordering) {
		// cout<<src<<" ";
		isvis[src] = true;
		for(auto nbr : adjList[src]) {
			if(isvis[nbr] == false) recurse(nbr,isvis,ordering);
		}

		// at the point of returning back
		ordering.push_front(src);
		return;
	}
	void dfs(T src) {
		unordered_map<T,bool> isvis;
		list<T> ordering;

		for(auto p : adjList) isvis[p.first] = false;
		recurse(src,isvis,ordering);

		// print the Topo Sort
		for(auto el : ordering) cout<<el<<" ";
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

	G.dfs("Python");
	return 0;
}
