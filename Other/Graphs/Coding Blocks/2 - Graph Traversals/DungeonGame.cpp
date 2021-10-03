// DungeonGame.cpp
// 2_Aayushi.cpp
#include <bits/stdc++.h>
using namespace std;


int globalAns = INT_MIN;
void recurse(vector<vector<int>> &mat, int i, int j, int m, int n, map<pair<int,int>,bool> &isvis,int coins = 0, int ans = 0) {
    if(i>=m or j>=n) {
		return;
	}
	if(i == m-1 and j == n-1) {
		globalAns = max(ans-1,globalAns);
		cout<<endl;
		return;
	}
	if(mat[i][j] <= 0) {
		if(coins > 1) {

		}
		ifcoins += -1*(mat[i][j]-1);
	} 

	recurse(mat,i,j+1,m,n,isvis,coins,ans);
	recurse(mat,i+1,j,m,n,isvis,coins,ans);

	return;
}

int solve(vector<vector<int>> &mat) {
	int m = mat.size();
	int n = mat[0].size();
	map<pair<int,int>,bool> isvis;
	recurse(mat,0,0,m,n,isvis);
	return abs(globalAns);
}

int main() {
	// vector<vector<int>> mat({{11,-10},{-2,0}});
	vector<vector<int>> mat({{-2,-3,3},{-5,-10,1},{10,30,-5}});
	cout<<solve(mat);
	return 0;
}