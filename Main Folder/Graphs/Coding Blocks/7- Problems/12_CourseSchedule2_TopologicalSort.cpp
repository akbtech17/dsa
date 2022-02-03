// 5_CourseSchedule2_TopologicalSort.cpp
// https://leetcode.com/problems/course-schedule-ii/
#include <bits/stdc++.h>
using namespace std;

// Approach - BFS + Indegree Concept 
// TC - O(V+E)
// SC - O(V+E)
class Solution {
    unordered_map<int,vector<int>> adjList;
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites){
        map<int,int> indegree;
        for(int i=0; i<n; i++) indegree[i] = 0;
        
        for(auto v: prerequisites) {
            adjList[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }
        
        queue<int> q;
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
        return ans.size() == n ? ans : vector<int>();
    }
};

int main() {
	Solution S;
	return 0;
}