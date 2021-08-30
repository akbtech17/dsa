// 5_BreadthFirstTraversal.cpp
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
