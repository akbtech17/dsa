// 5_RedundantConnection_DSU_CycleDetection_UG.cpp
// Problem - https://leetcode.com/problems/redundant-connection/
// Code -
#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> par;
public:
    int get_sp(int x) {
        if (x == par[x]) return x;
        return par[x] = get_sp(par[x]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int V = edges.size();
        par.resize(V);
        for(int i=0; i<V; i++) par[i] = i;
        for(auto v: edges) {
            int x = v[0]-1;            
            int y = v[1]-1;
            
            int sp1 = get_sp(x);            
            int sp2 = get_sp(y);
            
            if(sp1 == sp2) return v;
            else {
                par[sp1] = sp2;
            }
        }
        return {};
    }
};

