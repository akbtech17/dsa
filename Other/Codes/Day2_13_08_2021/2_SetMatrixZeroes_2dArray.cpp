// 2_SetMatrixZeroes_2dArray.cpp
// https://leetcode.com/problems/set-matrix-zeroes/
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
	void displayAns(vector<vector<int>>& mat) {
		for(auto v : mat) {
			for(auto el : v) cout<<el<<" ";
			cout<<endl;
		}
		cout<<endl;
		return;
	}

	void setZeroes(vector<vector<int>>& mat) {
        displayAns(mat);
        
        int n = mat.size();
        int m = mat[0].size();

        for(int i=0; i<n; i++) {
        	for(int j=0; j<m; j++) {
        		if(mat[i][j] == 0) {
 					
        			mat[i][0] = 0;
        			mat[0][j] = 0;
        		}
        	}
        }

        displayAns(mat);
        return;
    }

    // Space Constant
    void setZeroes2(vector<vector<int>>& mat) {
        displayAns(mat);
        
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


        displayAns(mat);
        return;
    }
};

int main() {
	vector<vector<int>> mat({
		{0,1,2,0},
		{3,4,5,2},
		{1,3,1,5}
	});
	Solution S;
	S.setZeroes(mat);
	return 0;
}