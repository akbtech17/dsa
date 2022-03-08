// 4_GraphRepresentation_AdjacenyListGenericData.cpp
// Code Link - https://ide.codingblocks.com/s/657929
#include <bits/stdc++.h>
using namespace std;

// TC: O(V^2)
// SC: O(V^2)
template<typename T>
class Graph {
    //adjacency list
    unordered_map<T,list<pair<T,int>>> adjList;
public:
    void addEdge(T x,T y,int wt,bool bidir = true) {
        adjList[x].push_back(make_pair(y,wt));
        if(bidir)
            adjList[y].push_back(make_pair(x,wt));
    }

    void prinAdjList() {
        for(auto p:adjList) {
            T city = p.first;
            list<pair<T,int>> nbrs = p.second;
            cout<<city<<"->";
            for(auto nbr:nbrs) {
                T dest = nbr.first;
                int dist = nbr.second;
                cout<<dest<<"::"<<dist<<" ";
            }
            cout<<endl;
        }
    }
};


int main() 
{
    Graph<string> g;
    g.addEdge("A","B",20,true);
    g.addEdge("B","D",40,true);
    g.addEdge("A","C",10,true);
    g.addEdge("C","D",40,true);
    g.addEdge("A","D",50,false);
    g.prinAdjList();
    return 0;
}
