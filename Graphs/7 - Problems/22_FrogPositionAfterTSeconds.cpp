// 22_FrogPositionAfterTSeconds.cpp
// Problem Link - https://leetcode.com/problems/frog-position-after-t-seconds/
// Code Link - https://ide.codingblocks.com/s/660004
#include <bits/stdc++.h>
using namespace std;

// Approach: 
// TC: O(V+E)
// SC: O(V)
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        // make adj list
        vector<vector<int>> adjList(n);
        for(auto ed: edges) {
            adjList[ed[0]-1].push_back(ed[1]-1);
            adjList[ed[1]-1].push_back(ed[0]-1);
        }
        
        vector<bool> isvis(n,false);
        vector<double> prob(n, 0.0);
        
        queue<pair<int,int>> q;
        q.push({0,0});
        
        isvis[0] = true;
        prob[0] = 1.0;
        
        int mxlev = 0;
        
        while(!q.empty()) { 
            int cnode = q.front().first;
            int lev = q.front().second;
            q.pop();
            
            if(cnode+1 == target) {
                // check if cnode is leaf or not
                bool flag = 1;
                for(auto nbr: adjList[cnode]) {
                    if(!isvis[nbr]) {
                        flag = 0;
                        break;
                    }
                }
                if(lev>t) return 0.00;
                else if(lev < t) {
                    cout<<"t is greater"<<flag;
                    if(flag) return prob[cnode];
                    else return 0;
                }
                else return prob[cnode];
            }
            
            int nbrs_cnt = 0;
            
            for(auto nbr: adjList[cnode]) if(!isvis[nbr]) nbrs_cnt++;
            for(auto nbr: adjList[cnode]) {
                if(!isvis[nbr]) {
                    
                    q.push({nbr,lev+1});
                    isvis[nbr] = true;
                    prob[nbr] = prob[cnode] / nbrs_cnt;
                }
            }
        }
        
        return 0;
    }
};