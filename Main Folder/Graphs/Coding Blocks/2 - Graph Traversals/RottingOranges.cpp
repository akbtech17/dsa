// RottingOranges.cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.size();


        queue<pair<int,int>> q;
        int tot = 0; // tot of non-empty cells 
        int cnt = 0;
        for(int i=0; i<m; i++) {
        	for(int j=0; j<n; j++) {
        		// if the orange is rotten, 
        		// add it into our Q
        		if(grid[i][j] == 2) q.push({i,j});
        		if(grid[i][j] != 0) tot++;
        	}
        }

        int minutes = 0;
        // now we will start the bfs
        while(!q.empty()) {
        	int nro = q.size();  // no of rotten oranges
        	cnt += nro;
        	while(nro--) {
        		int ci = q.front().first;
        		int cj = q.front().second;
        		q.pop();

        		vector<pair<int,int>> nbrs({{ci+1,cj},{ci-1,cj},{ci,cj+1},{ci,cj-1}});
        		for(auto nbr : nbrs) {
        			int ni = nbr.first, nj = nbr.second;
        			if(ni<0 or ni>=m or nj<0 or nj>=n or grid[ni][nj] != 1) continue;
        			grid[ni][nj] = 2;
        			q.push({ni,nj});
        		}
        	}

        	if(q.empty() == false) minutes++; 
        }

        return tot == cnt ? minutes : -1;
    }
};