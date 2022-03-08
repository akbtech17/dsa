// 3_GraphRepresentation_AdjacencyList.cpp
// Code Link - https://ide.codingblocks.com/s/657928
#include <bits/stdc++.h>
using namespace std;

// Adjacency List:

// Storing the list of neighbors in the array of lists
// so for each vertex, there will be some nbrs,
// which we will store in the associated list

// Pros: Saves space O(|V|+|E|) . 
// In the worst case, there can be C(V, 2) number of edges in a graph 
// thus consuming O(V^2) space. Adding a vertex is easier.

// Cons: 
// Queries like whether there is an edge from vertex u to vertex v are not efficient 
// and can be done O(V).

// TC: O(V^2)
// SC: O(V^2)
class Graph {
    int V;                // total number of vertices
    list<int> *adjList;   // pointer to the  array of list of vertices
public:
    Graph(int V){
        this->V = V;
        // array of list
        adjList = new list<int>[V];
    }

    void addEdge(int u,int v,bool bidir = true){
        adjList[u].push_back(v);
        if(bidir)
            adjList[v].push_back(u);
    }

    void printAdjList(){
        for(int i=0;i<V;i++){
            cout<<i<<"->";
            for(int vertex:adjList[i])
                cout<<vertex<<"::";
            cout<<endl;
        }
    }
};

int main() {
    //has 5 vertices from 0 to 4
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(4,3);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(1,3);

    g.printAdjList();

    return 0;
}
