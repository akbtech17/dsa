// Diagonal_Print.cpp
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

void solve(vector<vector<int>> mat) {
	int m = mat.size()-1;
	int n = mat[0].size()-1;

	for(int i=m; i>=0; i--) {
		int ii = i;
		int jj = 0;
		vector<int> temp;
		while(ii <= m and jj <= n) {
			// cout<<mat[ii][jj]<<",";
			temp.pb(mat[ii][jj]);
			ii++,jj++;
		}
		sort(temp.begin(),temp.end());
		ii = i;
		jj = 0;
		int itr = 0;
		while(ii <= m and jj <= n) {
			mat[ii][jj] = temp[itr++];
			ii++;
			jj++;
		}
		// cout<<endl;
	}	
	for(int j=1; j<=n; j++) {
		int ii = 0;
		int jj = j;
		vector<int> temp;
		while(ii <= m and jj <= n) {
			// cout<<mat[ii][jj]<<",";
			temp.pb(mat[ii][jj]);
			ii++,jj++;
		}
		sort(temp.begin(),temp.end());
		ii = 0;
		jj = j;
		int itr = 0;
		while(ii <= m and jj <= n) {
			mat[ii][jj] = temp[itr++];
			ii++;
			jj++;
		}
		// cout<<endl;
	}

	for(auto v : mat) {
		for(auto el : v) cout<<el<<" ";
		cout<<endl;
	}
	return;
}

int main() {
	solve({
		{3,3,1,1},
		{2,2,1,2},
		{1,1,1,2}
	});
	return 0;
}