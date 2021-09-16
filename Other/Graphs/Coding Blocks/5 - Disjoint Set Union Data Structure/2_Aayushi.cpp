// 2_Aayushi.cpp
#include <bits/stdc++.h>
using namespace std;

// int ans = 0;
int globalAns = 0;
void recurse(vector<vector<int>> &mat, int i, int j, int m, int n, map<pair<int,int>,bool> &isvis,int sum = 0, int ans = 0) {
	if(i<0 or j>=n) {
		cout<<"out of bounds\n";
		return;
	}
	if(i == 0 and j == n-1) {
		cout<<"reached dest";
		globalAns = min(ans,globalAns);
		return;
	}
	cout<<"im here\n";

	// suppose i am standing on a neg grid
	if(mat[i][j] < 0) {
		while(mat[i][j]<0 and sum>0) {
			mat[i][j]++;
			sum--;
		}
		if(mat[i][j] < 0) ans = min(mat[i][j],ans);
	}
	else {
		sum += mat[i][j];
	}

	isvis[{i,j}] = true;

	// i can move in right
	if(isvis.count({i,j+1}) == 0) recurse(mat,i,j+1,m,n,isvis,sum,ans);
	// or up
	if(isvis.count({i-1,j}) == 0) recurse(mat,i-1,j,m,n,isvis,sum,ans);
	
	return;
}

int main() {
	vector<vector<int>> mat({{11,-10},{-2,0}});
	map<pair<int,int>,bool> isvis;
	recurse(mat,1,0,2,2,isvis);
	cout<<globalAns;

	return 0;
}