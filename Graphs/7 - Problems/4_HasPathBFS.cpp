// 4_HasPathBFS.cpp
// Problem Link - https://www.pepcoding.com/resources/online-java-foundation/graphs/has-path-official/ojquestion
// Code Link - https://ide.codingblocks.com/s/657996
#include<bits/stdc++.h>
using namespace std;

class Edge {
public:
  int src;
  int nbr;
  int wt;

  Edge(int src, int nbr, int wt) {
    this->src = src;
    this->nbr = nbr;
    this->wt = wt;
  }
};

// Approach: BFS
// TC: O(V+E)
// SC: O(V)
int main() {
    int vtces;
    cin >> vtces;
    vector<Edge>graph[vtces];

    int edges;
    cin >> edges;
    for (int i = 0; i < edges; i++) {
        int v1 ;
        int v2 ;
        int wt ;
        cin >> v1 >> v2 >> wt;
        graph[v1].push_back( Edge(v1, v2, wt));
        graph[v2].push_back( Edge(v2, v1, wt));
    }

    int src;
    cin >> src;
    int dest;
    cin >> dest;
    
    // write your code here
    queue<int> q;
    q.push(src);
    
    vector<bool> isvis(vtces, false);

    while(!q.empty()) {
        int cnode = q.front();
        
        q.pop();
        
        if(isvis[cnode]) continue;
        // cout<<cnode<<" ";
        if(cnode == dest) {
            cout<<"true";
            return 0;
        }
        
        isvis[cnode] = true;
        
        for(int i=0; i<graph[cnode].size(); i++) {
            q.push(graph[cnode][i].nbr);
        }
    } 
    
    cout<<"false";
    return 0;
}


