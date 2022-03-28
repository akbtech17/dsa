// 21_NumberOfOperationsToMakeNetworkConnected.cpp
// Problem Link - https://leetcode.com/problems/number-of-operations-to-make-network-connected/
// Code Link - 
// Resource Link - https://www.youtube.com/watch?v=kEXU1nP54NM&ab_channel=Pepcoding
#include <bits/stdc++.h>
using namespace std;

// A1: BFS (TLE)
//     When KeyNode is closer to the LeafNode, 
//     we use DFS, it is faster than BFS in this case
//     While when the when KeyNode is closer to the RootNode/StartNode,
//     we use BFS, it is faster than DFS in this case
// TC: O(V+E)
// SC: O(V)
class Solution1 {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int tw = connections.size();
        int rw = n-1;
        if(tw<rw) return -1;
        
        vector<vector<int>> adjList(n);
        for(auto e: connections) {
            adjList[e[0]].push_back(e[1]);              
            adjList[e[1]].push_back(e[0]);
        }
        
        
        int t_comp = 0;
        vector<bool> isvis(n,0);
        
        for(int i=0; i<n; i++) {
            if(isvis[i]) continue;
            
            t_comp++;
            queue<int> q;
            q.push(i);
            
            while(!q.empty()) {
                int cnode = q.front();
                q.pop();
                
                isvis[cnode] = true;
                for(auto nbr: adjList[cnode]) {
                    if(!isvis[nbr]) q.push(nbr);
                }
            }
        }   
        return t_comp-1;
    }
};

// A2: DFS (Accepted)
//     When KeyNode is closer to the LeafNode, 
//     we use DFS, it is faster than BFS in this case
//     While when the when KeyNode is closer to the RootNode/StartNode,
//     we use BFS, it is faster than DFS in this case
// TC: O(V+E)
// SC: O(V)
class Solution2 {
public:
    void dfs(vector<vector<int>> &adjList, int cnode, vector<bool> &isvis) {
        isvis[cnode] = true;
        
        for(auto nbr: adjList[cnode]) {
            if(!isvis[nbr]) dfs(adjList,nbr,isvis);
        }
        
        return;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int tw = connections.size();
        int rw = n-1;
        if(tw<rw) return -1;
        
        vector<vector<int>> adjList(n);
        for(auto e: connections) {
            adjList[e[0]].push_back(e[1]);              
            adjList[e[1]].push_back(e[0]);
        }
        
        
        int t_comp = 0;
        vector<bool> isvis(n,0);
        
        for(int i=0; i<n; i++) {
            if(isvis[i]) continue;
            
            t_comp++;
            dfs(adjList,i,isvis);
        }   
        return t_comp-1;
    }
};


// A3: Disjoint Set Union
// TC: O(E) to unite, O(1) to get total comps
// SC: O(V)
class DSU {
    vector<int> par;
    int total_comps;
public:
    DSU(int n) {
        this->par.resize(n);
        for(int i=0; i<n; i++) par[i] = i;
        total_comps = n;
    }
    int get_sp(int x) {
        if(x == par[x]) return x;
        return par[x] = get_sp(par[x]);
    }
    void do_union(int x, int y) {
        int sp1 = get_sp(x);
        int sp2 = get_sp(y);
        
        if(sp1 != sp2) {
            par[sp1] = sp2;
            total_comps--;
        }
    }
    int get_cc() {return total_comps;}
};


class Solution3 {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int tw = connections.size();
        int rw = n-1;
        if(tw<rw) return -1;
        
        DSU dsu(n);
        for(auto e: connections) {
            dsu.do_union(e[0],e[1]);
        }
        int t_comp = dsu.get_cc();
        return t_comp-1;
    }
};