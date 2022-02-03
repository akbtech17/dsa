// CherryPickup.cpp
// Question - https://leetcode.com/problems/cherry-pickup/
// Code - 
// Resource - https://www.youtube.com/watch?v=juJ0j-Otgko
#include <bits/stdc++.h>
using namespace std;

// A1 - 
// collect max cherries while going down + 
// collect max cherries while comming back
// valid? - NO, it will FAIL!


// A2 - 
// collect OPTIMAL number of cherries while going down + 
// collect OPTIMAL number of cherries while comming back
// YES it will work!

// A2:Bruteforce - 
// Explore every path from TL->BR
//   and for each path, explore every path from BR->TL
// the max pair will be our ans
// TC - O{(All Path TL->BR) X (All Path BR->TL)}
// SC - O(MN)

class Solution {
	// to store the maximum cherry count
	int mcc;
public:
    Solution() : mcc(0) {}
	void recurse1(vector<vector<int>> &grid, int m, int n, int i=0, int j=0, int ccsf = 0) {
		// invalid steps
		if(i == m or j == n or grid[i][j] == -1) return;

		// base cases
		if(i == m-1 and j == n-1) {
            int curr_cherries = grid[i][j];
            grid[i][j] = 0; // as we have collected all cherries
            ccsf += curr_cherries;
			recurse2(grid,m,n,m-1,n-1,ccsf);
            // bactracking step
            grid[i][j] = curr_cherries;
			return;
		}

		// recursive cases
		int curr_cherries = grid[i][j];
		grid[i][j] = 0; // as we have collected all cherries
		ccsf += curr_cherries;
		recurse1(grid,m,n,i+1,j,ccsf);
		recurse1(grid,m,n,i,j+1,ccsf);
		
		// bactracking step
		grid[i][j] = curr_cherries;
		
		return;
	}

	void recurse2(vector<vector<int>> &grid, int m, int n, int i, int j, int ccsf) {
		// invalid steps
		if(i < 0 or j < 0 or grid[i][j] == -1) return;

		// base cases
		if(i == 0 and j == 0) {
			mcc = max(mcc,ccsf);
			return;
		}

		// recursive cases
		int curr_cherries = grid[i][j];
		grid[i][j] = 0; // as we have collected all cherries
		ccsf += curr_cherries;
		recurse2(grid,m,n,i-1,j,ccsf);
		recurse2(grid,m,n,i,j-1,ccsf);

		// bactracking step
		grid[i][j] = curr_cherries;

		return;
	}
    int cherryPickup(vector<vector<int>>& grid) {
    	recurse1(grid,grid.size(),grid[0].size());
        return mcc;
    }
};

int main() {

}