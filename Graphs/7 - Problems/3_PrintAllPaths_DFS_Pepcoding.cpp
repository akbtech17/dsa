// 6_AllPathsFromSourceToTarget_DAG.cpp
// Problem - https://leetcode.com/problems/all-paths-from-source-to-target/
// Code - 
#include <bits/stdc++.h>
#define vii vector<vector<int>>;
using namespace std;


// Appraoch: DFS 
// TC: O()
// SC: O()
class Solution {
    vector<vector<int>> ans;
public:
    void recurse(int src, int dest,vector<bool> isvis, vector<vector<int>> graph,vector<int> path) {
        // base case
        if(src == dest) {
            path.push_back(dest);
            ans.push_back(path);
            return;
        }

        // recursive case
        path.push_back(src);
        isvis[src] = true;
        
        for(auto nbrs : graph[src]) {
            if(!isvis[nbrs]) {
                recurse(nbrs,dest,isvis,graph,path);
            }
        }
        return;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int src = 0;
        int dest = graph.size()-1;
        vector<bool> isvis(dest+1,false);
        recurse(src,dest,isvis,graph,{});
        
        return ans;
    }
};

int main() {

	return 0;
}