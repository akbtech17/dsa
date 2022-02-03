// HasPath.cpp
// https://www.pepcoding.com/resources/online-java-foundation/graphs/has-path-official/ojquestion
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
public:
	void addEdge(int x, int y, int wt) {
		adjList[x].push_back({y,wt});
	}
	bool hasPath_BFS(int src, int dest, int V) {
		queue<int> q;
		vector<bool> isvis(V,false);

		q.push(src);
		isvis[src] = true;

		while(!q.empty()) {
			int curr = q.front();
			q.pop();

			if(curr == dest) return true;

			for(auto p : adjList[curr]) {
				if(isvis[p.first] == false) {
					isvis[p.first] = true;
					q.push(p.first);
				}
			}
		}

		return false;
	}
	void printAns(int src, int dest, int V) {
		bool ans = hasPath_BFS(src,dest,V);
		if(ans) cout<<"true";
		else cout<<"false";
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
	G.printAns(src,dest,V);
	return 0;
}