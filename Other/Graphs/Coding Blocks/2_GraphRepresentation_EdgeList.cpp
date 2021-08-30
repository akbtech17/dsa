// 2_GraphRepresentation_EdgeList.cpp
# include<bits/stdc++.h>
using namespace std;

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