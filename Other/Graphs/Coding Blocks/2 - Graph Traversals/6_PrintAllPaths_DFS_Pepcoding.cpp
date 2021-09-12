// 6_PrintAllPaths_DFS_Pepcoding.cpp
// https://www.pepcoding.com/resources/online-java-foundation/graphs/print-all-paths-official/ojquestion

#include <bits/stdc++.h>
using namespace std;

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

class Graph {
	map<int,list<pair<int,int>>> adjList;
	vector<string> ans;
public:
	void addEdge(int x, int y, int wt) {
		adjList[x].push_back({y,wt});
	}
	void recurse(int src, int dest, vector<bool> &isvis, string path = "") {
		isvis[src] = true;
		path += to_string(src);
		if(src == dest) {
			ans.push_back(path);
		}
		for(auto p : adjList[src]) {
			int nbr = p.first;
			if(isvis[nbr] == false) recurse(nbr,dest,isvis,path);
		}
		isvis[src] = false;
		return;
	}
	bool mycomp(string &s1, string &s2) {
		if(s1.size() == s2.size()) return s1>s2;
		else return s1.size()<s2.size();
		return false;
	}
	void printAllPaths_DFS(int src, int dest, int V) {
		vector<bool> isvis(V,false);
		recurse(src,dest,isvis);

		sort(ans.begin(),ans.end(),mycomp);
		for(auto path : ans) cout<<path<<endl;
		return;
	}
};

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
	G.printAllPaths_DFS(src,dest,V);
	return 0;
}