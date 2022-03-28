// 20_NumberOfProvinces.cpp
// Problem Link - https://leetcode.com/problems/number-of-provinces/
// Code Link - https://ide.codingblocks.com/s/658511
#include <bits/stdc++.h>
using namespace std;

// Approach: BFS
// TC: O(V+E)
// SC: O(V)
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        int V = isConnected.size();
        vector<bool> isvis(V,false);
        
        for(int c=0; c<V; c++) {
            if(isvis[c]) continue;
            ans++;
            queue<int> q;
            q.push(c);
            
            while(!q.empty()) {
                int cnode = q.front();
                q.pop();
                
                isvis[cnode] = true;
                for(int n=0; n<V; n++) {
                    if(isConnected[cnode][n] and !isvis[n]) q.push(n);
                }
            }
        }
        
        return ans;
    }
};