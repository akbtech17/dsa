// GenerateSpiralMatrix_LeetCode.cpp
// https://leetcode.com/problems/spiral-matrix-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void printMatrix(vector<vector<int>> &v) {
		for(auto t : v) {
			for(auto el : t) cout<<el<<" ";
			cout<<endl;
		}
		cout<<endl;
		return;
	}
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n,vector<int>(n,0));
        int ri = 0, ci = 0;
        int rj = n-1, cj = n-1;

        int value = 1;
        while(ri<=rj and ci<=cj) {
        	// fill the first row
        	for(int col=ci; col<=cj; col++) mat[ri][col] = value++;
        	ri++;
        	// fill the right col
        	for(int row=ri; row<=rj; row++) mat[row][cj] = value++;
        	cj--;
        	// fill the bottom row
        	for(int col=cj; col>=ci; col--) mat[rj][col] = value++;
        	rj--;
        	// fill the left col
        	for(int row=rj; row>=ri; row--) mat[row][ci] = value++;
        	ci++;
        }
        printMatrix(mat);
        return mat;
    }
};

int main() {
	Solution S;
	S.generateMatrix(3);
	S.generateMatrix(4);

	return 0;
}