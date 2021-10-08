// 1_FindCenterOfGraph.cpp
// https://leetcode.com/problems/find-center-of-star-graph/
#include<bits/stdc++.h>
using namespace std;

int findCenter(vector<vector<int>> edges) {
	// there will be one node common in every edge
	// so we sill return the common node of first two edges
    return edges[0][0] == edges[1][0] or edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
}

int main() {
	cout<<findCenter({{1,2},{2,3},{4,2}})<<endl;
	cout<<findCenter({{1,2},{5,1},{1,3},{1,4}})<<endl;
	return 0;
}