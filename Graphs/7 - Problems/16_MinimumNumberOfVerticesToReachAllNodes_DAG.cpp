// 3_MinimumNumberOfVerticesToReachAllNodes_DAG.cpp
// Problem - https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
// Code - 
#include <bits/stdc++.h>
using namespace std;


// Find all vertices which have indegree 0
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> isvis(edges.size(),false);
        for(auto& e : edges) isvis[e[1]] = true;
        vector<int> ans;
        for(int i=0 ;i<n ;i++) {
            if(!isvis[i]) ans.push_back(i);
        }
		return ans;
    }
};

int main() {

}