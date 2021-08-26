// 01Matrix_Leetcode.cpp
// https://leetcode.com/problems/01-matrix/
#include<bits/stdc++.h>
using namespace std;


int minVal(vector<vector<int>>& mat, int i, int j, int row, int col) {
	int min_val = INT_MAX;

	if(j-1>=0) min_val = min(min_val,mat[i][j-1]);  
	if(i-1>=0) min_val = min(min_val,mat[i-1][j]);  
	if(i+1<row) min_val = min(min_val,mat[i+1][j]);   
	if(j+1<col) min_val = min(min_val,mat[i][j+1]);  

	return min_val;
}


// Approach2 - Using BFS
// TC - 
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
	int rows = mat.size();
	int cols = mat[0].size();

	vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));

	queue<pair<int,int>> q;
	for(int i=0;i<rows;i++) {
		for(int j=0;j<cols;j++) {
			if(mat[i][j] == 0) {
				dist[i][j] = 0;
				q.push({i,j});
			}
		}
	}

	while(!q.empty()) {
		pair<int,int> curr = q.front();
		int i = curr.first;
		int j = curr.second;
		int cdist = dist[curr.first][curr.second]+1;
		q.pop();

		// access its neighbours
		if(i-1>=0) {
			if(cdist<dist[i-1][j]) {
				dist[i-1][j] = cdist;
				q.push({i-1,j});
			}
		}  
		if(j-1>=0) {
			if(cdist<dist[i][j-1]) {
				dist[i][j-1] = cdist;
				q.push({i,j-1});
			}
		}
		if(i+1<rows) {
			if(cdist<dist[i+1][j]) {
				dist[i+1][j] = cdist;
				q.push({i+1,j});
			}
		}
		if(j+1<cols) {
			if(cdist<dist[i][j+1]) {
				dist[i][j+1] = cdist;
				q.push({i,j+1});
			}
		}
	}

	return dist;
}


int main() {
	
}