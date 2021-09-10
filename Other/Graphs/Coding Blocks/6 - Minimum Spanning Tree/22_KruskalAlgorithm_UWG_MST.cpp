// 22_KruskalAlgorithm_UWG_MST.cpp
// https://www.spoj.com/problems/MST/

// Key Points - 
// 1 - Greedy Algorithm
// 2 - Used to find MST
// 3 - Applied in Undirected Weighted Connected Graph
// 4 - TC - O(ElogV)

// 5 - SC - O(E)


// Time Complexity
//          O(E) - as we have to make decision for each edge, 
//                 whether to include it or leave it.
// 			O(ElogE) - as we have to sort the set of edges.
//          In the worst case E may be directly proportional to V square
//          O(ElogV2) -> O(ElogV)




// Differences between Prims and Kruskals - 

// Prims - It starts to build the Minimum Spanning Tree from any vertex in the graph.	
// Kruskals - It starts to build the Minimum Spanning Tree from the vertex carrying minimum weight in the graph.

// Prims - It traverses one node more than one time to get the minimum distance.	
// Kruskals - It traverses one node only once.

// Prim’s algorithm has a time complexity of O(V2), V being the number of vertices and can be improved up to O(ElogV) using Fibonacci heaps.	
// Kruskal’s algorithm’s time complexity is O(ElogV), V being the number of vertices.

// Prim’s algorithm gives connected component as well as it works only on connected graph.	
// Kruskal’s algorithm can generate forest(disconnected components) at any instant as well as it can work on disconnected components.

// Prim’s algorithm runs faster in dense graphs.	
// Kruskal’s algorithm runs faster in sparse graphs.





// What we have as a Goal : 
// we have to pick some edges st
// 1 - all vertices are connected
// 2 - total cost should be minimized


// Kruskal's Algorithm
// 1 - Consider all vertices without any edges
// 2 - Sort all edges based on weight
// 3 - Now start picking edges from the sorted list of edges
// 4 - check if two vertices, if they belong to different set (using dsu)
//     we can join them, as they dont form a cycle.
// 5 - if cycle is formed, leave that edge, and try for other edges.



#include <bits/stdc++.h>
using namespace std;

// DSU Data Structure
// Path Compression, Union by Rank
// So rank basically denotes here the number of vertices
// in each component
class DSU {
	vector<int> par;
	vector<int> rank;

    public:
	DSU(int V) {
		par.resize(V);
		for(int i=0; i<V; i++) par[i] = i;

		// each component will have only one vertex initially
		rank.resize(V,1); 
	} 

	// get_sp funtion
	int get_sp(int x) {
		// base case
		if(x == par[x]) return x;
		// else, recurse
		return par[x] = get_sp(par[x]);
	}

	// do_union function
	void do_union(int x, int y) {
		int sp1 = get_sp(x);
		int sp2 = get_sp(y);

		// if they dont lie in the same componenet
		if(sp1 != sp2) {
			// union by rank
			// here we will megre 
			// comp with lower rank with 
			// higher rank
			if(rank[sp1] > rank[sp2]) {
				par[sp2] = sp1;
				rank[sp1] += rank[sp2];
				rank[sp2] = 0;
			}
			else {
				par[sp1] = sp2;
				rank[sp2] += rank[sp1];
				rank[sp1] = 0;
			}
		}
	}
};

// class edge {
// public:
// 	int src;
// 	int dest;
// 	int wt;
// };

class Graph {
	// edge list
	vector<vector<int>> edgeList;
	int V;
public:
	Graph(int V) {
		this->V = V;
	}

	void addEdge(int x, int y, int w) {
		// here we are taking weight as first 
		// el in our edgeList vector
		// to avoid the custom comparator

		// when we will use sorting on the edge list
		// it will automatically sort on the basis of first
		// el which is wieght of the edge
		edgeList.push_back({w,x,y});
	}

	// return the MST cost
	int kruskal_mst() {
		int total_mst_cost = 0;
		// Initialize the DSU
		DSU dsu(this->V);
		// 1 Sort the edgeList
		sort(edgeList.begin(), edgeList.end());
		// 2 Iterate over the edgeList
		for(auto edge : edgeList) {
			int w = edge[0];
			int x = edge[1];
			int y = edge[2];

			// take the edge in MST if and only if
			// it does not form a cycle
			int sp1 = dsu.get_sp(x);
			int sp2 = dsu.get_sp(y);

			// means they lie in different componenets
			if(sp1 != sp2) {
				// we can unite them in the same set
				dsu.do_union(x,y);
				total_mst_cost += w;
			}
		}
		return total_mst_cost;
	}
};

// 4 5
// 1 2 10
// 2 3 15
// 1 3 5
// 4 2 2
// 4 3 40

// Output - 17

int main() {
	// Graph G(4);
	// G.addEdge(0,1,1);
	// G.addEdge(1,3,3);
	// G.addEdge(3,2,4);
	// G.addEdge(2,0,2);
	// G.addEdge(0,3,2);
	// G.addEdge(1,2,2);
	// cout<<"MST Cost using Kruskal is : "<<G.kruskal_mst();
	

	int V,E;
	cin>>V>>E;
	Graph G(V);
	for(int i=0; i<E; i++) {
		int x,y,w;
		cin>>x>>y>>w;
		x--;
		y--;
		G.addEdge(x,y,w);
	}
	cout<<G.kruskal_mst();
	
	return 0;
}