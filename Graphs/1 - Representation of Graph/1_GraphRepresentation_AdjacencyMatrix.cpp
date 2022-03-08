// 1_GraphRepresentation_AdjacencyMatrix.cpp
// Code Link - https://ide.codingblocks.com/s/657918
#include <bits/stdc++.h>
using namespace std;

// Adjacency Matrix:

// Adjacency Matrix is a 2D array of size V x V 
// where V is the number of vertices in a graph. 
// Let the 2D array be adj[][], 
// a slot adj[i][j] = 1 indicates that there is an edge from vertex i to vertex j. Adjacency matrix for undirected graph is always symmetric. 
// Adjacency Matrix is also used to represent weighted graphs. 
// If adj[i][j] = w, then there is an edge from vertex i to vertex j with weight w. 

// Pros: 
// Representation is easier to implement and follow. 
// Removing an edge takes O(1) time. 
// Queries like whether there is an edge from vertex ‘u’ to vertex ‘v’ are efficient and can be done O(1).

// Cons: 
// Consumes more space O(V^2). 
// Even if the graph is sparse(contains less number of edges), 
// it consumes the same space. Adding a vertex is O(V^2) time. 


// TC: O(V^2)
// SC: O(V^2)

// A1: Adjacency Matrix [2D Grid] 
class Graph1 {
	bool **adjMatrix;    
	int n;   // total number of vertices [0..n-1]
public:
	Graph(int vertices) {
		this->n = vertices;
		
		this->adjMatrix = new bool*[n];
		for(int i=0; i<n; i++) {
			adjMatrix[i] = new bool[n];
			memset(adjMatrix[i], false, sizeof(adjMatrix[i]));
		}
	
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

// A2: Adjacency Matrix [2D Vector]
class Graph2 {
	vector<vector<int>> adjMatrix;
	int n;   // total number of vertices [0..n-1]
public:
	Graph2(int vertices) {
		this->n = vertices;
		this->adjMatrix = vector<vector<int>> (n, vector<int>(n, 0));
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
				if(adjMatrix[i][j]) {
					cout<<"("<<i<<","<<j<<"),";
				}
			}
		}
		cout<<"}\n";
	}
	
};

istream& operator>>(istream &in, Graph1 &obj) {
		obj.inputGraph();
		return in;
}

ostream& operator<<(ostream &out, Graph1 &obj) {
		obj.inputGraph();
		return out;
}

istream& operator>>(istream &in, Graph2 &obj) {
		obj.inputGraph();
		return in;
}

ostream& operator<<(ostream &out, Graph2 &obj) {
		obj.inputGraph();
		return out;
}

// Sample Test Case
// 1 0 1
// 0 1 0
// 1 1 0
int main() {
	Graph2 g1(3);
	g1.inputGraph();
	g1.printGraph();
	cin>>g1;
	cout<<g1;
	return 0;
}