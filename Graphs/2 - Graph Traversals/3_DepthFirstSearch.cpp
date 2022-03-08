// 3_DepthFirstSearch.cpp
// Code Link - https://ide.codingblocks.com/s/657940

// Recursive Way to Traverse the Graph.

// Start form any node
// and recurse on each not vis nbr of each node

// DFS
// 1 - It uses edge based technique. 
// 2 - It uses the Stack data structure, 
// 3 - It performs two stages, first visited vertices are pushed into stack and 
//    second if there is no vertices then visited vertices are popped. 
// 4 - DFS is Faster.
// 5 - DFS is more suitable for game or puzzle problems. 
//     We make a decision, then explore all paths through this decision. 
//     And if this decision leads to win situation, we stop.
#include <bits/stdc++.h>
using namespace std;

// TC: O(V+E) using adjecency list, O(VE) using Adjacency Matrix
// SC: O(V) to Call Stack space.
template<typename T>
class Graph{
    unordered_map<T,list<T>> mp;    // adjaceny list
public:
    void addEdge(int x,int y) {
        mp[x].push_back(y);
        mp[y].push_back(x);
    }

    void recurse(T cnode, map<T,bool>& isvis) {
        if(isvis[cnode]) return;

    	isvis[cnode] = true;
    	cout<<cnode<<" ";
    	
        // go to all nbr of that node(one by one) that is not vis 
    	for(T nbr : mp[cnode]) recurse(nbr,isvis);
    }

    void dfs(T src) {
    	map<T,bool> isvis;
    	// 1 - mark all nodes as not vis in the begining
    	for(auto p : mp) isvis[p.first] = false;

    	recurse(src, isvis);
    	return;
    }
};


int main() {
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(4,3);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(1,3);

    g.dfs(0);

    return 0;
}
