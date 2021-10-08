// 4_NumberOfProvinces_DSU.cpp
// https://leetcode.com/problems/number-of-provinces/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> par;
    int tcomp;
public:
    int getsp(int x) {
        if(x == par[x]) return x;
        return par[x] = getsp(par[x]);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        par.resize(n);
        for(int i=0; i<n; i++) par[i] = i;
        tcomp = n;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(isConnected[i][j]) {
                    int sp1 = getsp(i);                                     int sp2 = getsp(j);
                    if(sp1 != sp2) {
                        par[sp1] = sp2;
                        tcomp--;
                    }
                }
            }
        }
        return tcomp;
    }
};