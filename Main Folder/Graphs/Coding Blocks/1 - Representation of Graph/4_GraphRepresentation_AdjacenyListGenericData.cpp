// 4_GraphRepresentation_AdjacenyListGenericData.cpp
#include <bits/stdc++.h>
using namespace std;

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
