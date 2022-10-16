// 3_SatisfiabilityOfEqualityEquations_DSU.cpp
// Problem Link - 
// Code Link - 
// Reference Link - 

#include<bits/stdc++.h>
using namespace std;

// Approach
// TC : 
// SC : 
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
        
        if(sp1!=sp2) {
            par[sp1] = sp2;
            total_comps--;
        }
    }
};


class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU dsu(26);
        for(auto equation: equations) {
            if(equation[1] == '=') {
                int num1 = equation[0]-'a', num2 = equation[3]-'a';
                int sp1 = dsu.get_sp(num1), sp2 = dsu.get_sp(num2);
                
                if(sp1 != sp2) dsu.do_union(sp1,sp2);
            }
        }
        
        for(auto equation: equations) {
            if(equation[1] != '=') {
                int num1 = equation[0]-'a', num2 = equation[3]-'a';
                int sp1 = dsu.get_sp(num1), sp2 = dsu.get_sp(num2);
                
                if(sp1 == sp2) return false;
            }
        }
        
        return true;
    }
};