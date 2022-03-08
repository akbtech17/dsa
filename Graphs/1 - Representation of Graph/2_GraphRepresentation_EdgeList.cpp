// 2_GraphRepresentation_EdgeList.cpp
// Code Link - https://ide.codingblocks.com/s/657935
# include<bits/stdc++.h>
using namespace std;

// Edge List:
// An edge list is a list or array of all the edges in a graph. 
// Edge lists are one of the easier representations of a graph.

// Cons:
// O(E) time for almost all operations.

// TC: O(E)
// SC: O(E)
class Graph {
	int V; // no of vertices
	vector<pair<int,int>> edgeList; // to store the edges
public:
	Graph(int V) {
		this->V = V;
	}

	void addEdge(int src, int dest) {
		edgeList.push_back({src,dest});
	}

	void printGraph() {
		cout<<" Total number of Vertices : "<<V;
		cout<<"\n Edges : \n";
		cout<<"{";
		for(int i=0; i<edgeList.size(); i++) {
			cout<<"("<<edgeList[i].first<<","<<edgeList[i].second<<"),";
		}
		cout<<"}\n";
	}
};

int main() {
	Graph g(3);
	g.addEdge(0,1);
	g.addEdge(2,0);

	g.printGraph();

	return 0;
}