// 1_GraphRepresentation_AdjacencyMatrix.cpp
#include <bits/stdc++.h>
using namespace std;

// 1 - Adjacency Matrix [2D Grid] 
class Graph1 {
	bool **adjMatrix;
	int n;
public:
	Graph(int vertices) {
		this->n = vertices;
		// cout<<n;
		this->adjMatrix = new bool*[n];
		for(int i=0; i<n; i++) {
			adjMatrix[i] = new bool[n];
			memset(adjMatrix[i], false, sizeof(adjMatrix[i]));
		}
		// printGraph();
	}
	void inputGraph() {
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				cin>>adjMatrix[i][j];
			}
		}
	}
	void printGraph() {
		cout<<"{";
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(adjMatrix[i][j]) 
					cout<<"("<<i<<","<<j<<"),";
			}
		}
		cout<<"}\n";
	}
	
};

// 2 - Adjacency Matrix [2D Vector]
class Graph2 {
	vector<vector<bool>> adjMatrix;
	int n;
public:
	Graph2(int vertices) {
		this->n = vertices;
		vector<vector<bool>> v(n, vector<bool>(n,false));
		adjMatrix = v;
	}
	void inputGraph() {
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				
			}
		}
	}
	void printGraph() {
		cout<<"{";
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(adjMatrix[i][j]) 
					cout<<"("<<i<<","<<j<<"),";
			}
		}
		cout<<"}\n";
	}
	
};

// istream& operator>>(istream &in, Graph &obj) {
// 		obj.inputGraph();
// 		return in;
// }

// ostream& operator<<(ostream &out, Graph &obj) {
// 		obj.inputGraph();
// 		return out;
// }

// 1 0 1
// 0 1 0
// 1 1 0


int main() {
	// Graph1 g1(3);
	// g1.inputGraph();
	// g1.printGraph();
	// cin>>g1;
	// cout<<g1;
	return 0;
}