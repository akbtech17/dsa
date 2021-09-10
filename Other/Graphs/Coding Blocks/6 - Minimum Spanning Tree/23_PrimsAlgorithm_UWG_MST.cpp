// 23_PrimsAlgorithm_UWG_MST.cpp

// Key Points - 
// 1 - Greedy Algorithm.
// 2 - Used to find MST.
// 3 - Applied in Undirected Weighted Connected Graph.
// 4 - TC - O(Elog(V*V)) - O(ElogV)
// 5 - SC - O(E)


// TC - N - to iterate over all edges
//          O(ElogE) - to find min edge for E edges
//          In the worst case E may be directly proportional to V square


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


// Applications of Prims - 
// 


// What we have as a Goal : 
// we have to pick some edges st
// 1 - all vertices are connected
// 2 - total cost should be minimized


// Terms - 

// 1 - V[] =           Contains all nodes, needs to be included.
//                     In the beginning, this set will be full
//                     In the end, this set will become empty

// 2 - MST Set[] =     All the nodes which have been included in the MST till now
//                     In the beginning, this set will be empty
//                     In the end, this set will have all nodes

// 3 - Active Edge[] = any edge from any vertex of MST set 
//                     to any other V which are not part of MST.

// 4 - MST Edge[] =    set of edges that have been included in the MST so far.


// Prims's Algorithm
// 1 - Start from any Source Vertex. (Say V=1), mark vis
// 2 - and start exploring all the active edges related to V1
// 3 - out of all these active edges, pick the min most edge  using MinHeap
//     (Greedy choice, selecting local minima)
// 4 - after picking this edge, 
//     1 - add the second V2 related to the pciked edge in MST
//     2 - add edges starting from V2 in the active edge list
// Repeat 4 till all vertices are not visited 

#include <bits/stdc++.h>
using namespace std;

class Graph {
	// Adjacency List - 
	// we have to check all neighbours of any Vertex
	vector<pair<int,int>> *adjList;
	int V;
public:
	Graph(int V) {
		this->V = V;
		adjList = new vector<pair<int,int>> [V];
	}

	void addEdge(int x, int y, int w) {
		adjList[x].push_back({y,w});
		adjList[y].push_back({x,w});
	}

	int prim_mst() {
		// we will store {W, V2(dest vertex)}
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

		// visited array
		bool *isvis = new bool[V]{0};

		int ans = 0;

		// begin
		pq.push({0,0}); // {W,V} comparison will be pased on first param
		
		while(!pq.empty()) {
			// pick out the edge with min weight
			pair<int,int> best = pq.top();
			pq.pop();

			int destVertex = best.second;
			int weight = best.first;

			if(isvis[destVertex] == true) {
				// discard the edge, and continue
				continue;
			}

			// otherwise take the currenct edge
			ans += weight;
			isvis[destVertex] = true;

			// add the neew edges, in the queue
			for(auto nbr : adjList[destVertex]) {
				if(isvis[nbr.first] == false) pq.push({nbr.second, nbr.first});
			} 
		}
		return ans;
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
	cout<<G.prim_mst();
}