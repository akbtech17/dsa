// 4_CourseSchedule_TopologicalSort.cpp
// https://leetcode.com/problems/course-schedule/
#include <bits/stdc++.h>
using namespace std;

// Approach - BFS + Indegree Concept 
// TC - O(V+E)
// SC - O(V+E)
class Solution {
    unordered_map<int,vector<int>> adjList;
    unordered_map<int,int> indegree;
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        // building adjecency list and storing indegree of each vertex
        for(int i=0; i<n; i++) indegree[i] = 0; 
        for(auto v: pre) {
            adjList[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }
        
        queue<int> q;
        // pushing the vertex with indegree 0
        for(auto p: indegree) {
            if(p.second == 0) q.push(p.first);
        }
        
        vector<int> ans;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            
            for(auto nbr: adjList[curr]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        } 
        return ans.size() == n;
    }
};

int main() {
	Solution S;
	return 0;
}