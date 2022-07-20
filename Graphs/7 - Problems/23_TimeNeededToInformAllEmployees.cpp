// 23_TimeNeededToInformAllEmployees.cpp
// Problem Link - https://leetcode.com/problems/time-needed-to-inform-all-employees/
// Code Link - https://ide.codingblocks.com/s/660026
#include <bits/stdc++.h>
using namespace std;

// Approach: Using DFS
// TC: O(N+E) N is the time taken for visiting N nodes and E is for traveling through edges.
// SC: O(N) Space for aux.
class Solution {
public:
    int dfs(vector<vector<int>> &adjList, int cnode, vector<int>& informTime) {
        int ctime = 0;
        
        for(auto nbr: adjList[cnode]) {
            ctime = max(ctime,dfs(adjList, nbr, informTime));  
        }
        
        return ctime + informTime[cnode];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // adj list
        vector<vector<int>> adjList(n); 

        for(int i=0; i<n; i++) {
            if(i == headID) continue;
            adjList[manager[i]].push_back(i);
        }

        return dfs(adjList,headID,informTime);
    }
};