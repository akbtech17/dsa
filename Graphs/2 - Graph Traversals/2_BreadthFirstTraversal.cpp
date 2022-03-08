// 5_BreadthFirstTraversal.cpp
// Code Link - https://ide.codingblocks.com/s/657938

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
#include <bits/stdc++.h>
using namespace std;

// TC: O(V+E) using adjecency list, O(VE) using Adjacency Matrix
// SC: O(V) for storing Vertices in Queue.
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

        // 3 - push source node 
        q.push(src);

        // 4 - pop the first node,
        //     if it is visited check for other in q
        //     else print it, mark it vis
        //     and traverse all its nbrs, and push it in Q
        while(!q.empty()) {
            T node = q.front();
            q.pop();

            if(visited[node]) continue;
            cout<<node<<",";
            visited[node] = true;

            for(auto nbr: mp[node]) q.push(nbr);  
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
