// 5_BreadthFirstTraversal.cpp
// Iterative Way to Traverse the Graph.

// You start from teh given node
// and then you go to nbrs of the curr node
// we cant go to the two nbrs at the same time
// so we need Queue DS to store the order of traversal of nbrs
// just like Level Order Traversal of a Tree.

// BFS
// 1 - Vertex based technique.
// 2 - It uses a Queue data structure. 
// 3 - In BFS, one vertex is selected at a time when it is visited and marked then its adjacent are visited and stored in the queue. 
// 4 - It is slower than DFS. 
// 5 - Used to find SSSP in an Unweigted Graph, 
//     because in BFS we reach to the dest in exploring min number of edges.
// TIME - O(V+E) using adjecency list, O(VE) using Adjacency Matrix
// SPACE - O(V) for storing Vertices in Queue.

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    unordered_map<T,list<T>> mp;     // adjaceny list
public:
    
    void addEdge(int x,int y){
        mp[x].push_back(y);
        mp[y].push_back(x);
    }

    void bfs(T src){
    	// 1 - track while visiting each node
        unordered_map<T,bool> visited;
        // 2 - maintaing queue of type node
        queue<T> q;

        // 3 - push source node and mark it visited
        q.push(src);
        visited[src] = true;

        // 4 - pop the first node,
        //     traverse its all nbrs and check for each nbr,
        //     it the nbr is not yet visit push it in the Queue 
        //     and mark it vis
        while(!q.empty()) {
            T node = q.front();
            cout<<node<<",";
            q.pop();

            for(auto nbr:mp[node]) {
                if(!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
};


int main() 
{
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(4,3);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(1,3);

    g.bfs(0);

    return 0;
}
