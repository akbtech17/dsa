// 1_SetZeroesShikhar_2dArray.cpp
#include <bits/stdc++.h>
#include <vector>
using namespace std;

void printMat(vector<vector<int>>& mat) {
	for(auto v : mat) {
		for(auto el : v) {
			cout<<el<<" ";
		}
		cout<<endl;
	}
	return;
}

int solve(vector<vector<int>>& mat) {
	int ans = 0;
	for(auto v : mat) {
		for(auto el : v) {
			if(el == 0) ans++;
		}
		// cout<<endl;
	}
	// cout<<endl;
	// cout<<"ans"<<ans;
	return ans;
}

int setZeroes(vector<vector<int>>& mat) {
        // displayAns(mat);
        int n = mat.size();
        int m = mat[0].size();

        bool row = false;
        bool col = false;

        for(int i=0; i<n; i++) {
        	for(int j=0; j<m; j++) {
        		if(mat[i][j] == 0) {
 					if(i == 0) row = true;
 					if(j == 0) col = true;
        			mat[i][0] = 0;
        			mat[0][j] = 0;
        		}
        	}
        }

        for(int i=1; i<n; i++) {
        	for(int j=1; j<m; j++) {
        		if(mat[i][0] == 0 or mat[0][j] == 0)
        			mat[i][j] = 0;
        	}
        }

        if(col) {
        	for(int i=0;i<n;i++) mat[i][0] = 0;        
        }
    	if(row) {
        	for(int j=0;j<m;j++) mat[0][j] = 0;        
        }

	printMat(mat);
        // int ans = displayAns(mat);
        return solve(mat); 
}




int main() {
	vector<vector<int>> inp(8, vector<int>(8,1));
	inp[5][5] = 0;
	inp[5][3] = 0;
	// printMat(inp);
	// cout<<solve(n,arr);
	cout<<setZeroes(inp);
	return 0;
}