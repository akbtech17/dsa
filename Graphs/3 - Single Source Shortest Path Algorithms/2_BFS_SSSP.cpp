// 2_BFS_SSSP.cpp
// Undirected Unweighted Graph

// Distance Traveled by the Level Order / BFS
// is the shortest distance in Unweighted Graph.

// we have to find the shortest path from the source node
// to all other nodes.

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    unordered_map<T,list<T>> mp;
public:
    
    void addEdge(int x,int y){
        mp[x].push_back(y);
        mp[y].push_back(x);
    }

    void bfs(T src){
        
        map<T,int> dist;
        queue<T> q;
        q.push(src);
       
        //all other nodes will have dist = INF
        for(auto node_pair:mp) {
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }
        dist[src] = 0;

        while(!q.empty()) {
            T node = q.front();
            //cout<<node<<",";
            q.pop();

            for(auto nbr:mp[node]) {
                if(dist[nbr] == INT_MAX) {
                    q.push(nbr);
                    dist[nbr] = dist[node]+1;
                }
            }
        }
        //print the distance to every node
        for(auto vis: dist) {
            cout<<vis.first<<"->"<<vis.second<<endl;
        }
    }
};

int main() 
{
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,3);
    g.addEdge(3,4);
    g.addEdge(4,5);

    g.bfs(0);

    return 0;
}
