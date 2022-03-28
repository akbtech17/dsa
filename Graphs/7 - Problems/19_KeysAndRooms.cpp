// 19_KeysAndRooms.cpp
// Problem Link - https://leetcode.com/problems/keys-and-rooms/
// Code Link - https://ide.codingblocks.com/s/658510
#include <bits/stdc++.h>
using namespace std;

// Approach: DFS 
// TC: O(V+E)
// SC: O(V)
class Solution {
    int n;
public:
    void dfs(vector<vector<int>> &rooms, int cr, vector<bool> &isvis) {
        isvis[cr] = true;
        n++;
        // cout<<cr<<" unlocked\n";
        
        for(auto el : rooms[cr]) {
            if(!isvis[el]) dfs(rooms,el,isvis);
        }
        
        return;
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        n = 0;
        vector<bool> isvis(rooms.size(), false);
        dfs(rooms, 0, isvis);
        
        return n == rooms.size();
    }
};