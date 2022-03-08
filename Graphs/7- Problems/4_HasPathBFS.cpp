// 4_HasPathBFS.cpp
// Problem Link - 
// Code Link - 
#include<bits/stdc++.h>
using namespace std;

// Approach: DFS
// TC: O(V+E)
// SC: O(V)
class Graph {
	map<int,list<pair<int,int>>> adjList;
	bool ans = false;
public:
	void addEdge(int x, int y, int wt) {
		adjList[x].push_back({y,wt});
	}
	void recurse(int src, int dest, vector<bool> &isvis) {
		isvis[src] = true;
		if(ans) return;
		if(src == dest) {
			ans = true;
			return;
		}
		for(auto p : adjList[src]) {
			int nbr = p.first;
			if(isvis[nbr] == false) recurse(nbr,dest,isvis);
		}
		return;
	}
	bool hasPath_DFS(int src, int dest, int V) {
		vector<bool> isvis(V,false);
		recurse(src,dest,isvis);
		return ans;
	}
	void printAns(int src, int dest, int V) {
		bool ans = hasPath_DFS(src,dest,V);
		if(ans) cout<<"true";
		else cout<<"false";
		return;
	}
};

// Sample Test Case
// 7
// 8
// 0 1 10
// 1 2 10
// 2 3 10
// 0 3 10
// 3 4 10
// 4 5 10
// 5 6 10
// 4 6 10
// 0
// 6
int main() {
	Graph G;
	int V, E;
	cin>>V>>E;

	for(int i=0; i<E; i++) {
		int x,y,wt;
		cin>>x>>y>>wt;
		G.addEdge(x,y,wt);
	}

	int src,dest;
	cin>>src>>dest;
	G.printAns(src,dest,V);
	return 0;
}