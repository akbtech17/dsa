// 11_PrintNQueens.cpp
// https://leetcode.com/problems/n-queens/
// https://ide.codingblocks.com/s/636156

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<string>> all_conf;
public:
    bool isSafe(vector<string> board, int i, int j, int n) {
        // no queen should be present in 
        // 1. same column
        for(int row=0; row<=i; row++) 
            if(board[row][j] == 'Q') return false;
        
        // 2. left diagonal        
        int x = i;
        int y = j;
        while(x>=0 and y>=0) 
            if(board[x--][y--] == 'Q') return false;
        
        // 3. right diagonal
        x = i;
        y = j;
        while(x>=0 and y<n) 
            if(board[x--][y++] == 'Q') return false;
        
        return true;
    }
    bool solve(int n, vector<string> board, int i=0) {
        // base case - 
        // agar hum rows exceed krdenge, 
        // toh humari sari Queens place ho chuki hongi
        if(i == n) {
            all_conf.push_back(board);
            // return true;    // to check for only one possible configuration
            return false;   // to try for all possible configuration
        }
        
        // recursive cases
        // now in the current row, 
        // we will try to place Q in each cell if it is safe to do so...
        for(int j=0; j<n; j++) {
            // check if it is safe to place Q here!
            if(isSafe(board,i,j,n)) {
                // if yes, then place the Q
                board[i][j] = 'Q';
                // check for other Q
                bool bakiRakhPare = solve(n,board,i+1);
                if(bakiRakhPare) return true;
            }
            // if the control reaches here means, 
            // curr pos was not appropriate
            // backtrack krte smy us pos pe se Q remove krdo!
            board[i][j] = '.';
            // and curr row ki baaki cells ke liye loop check krlega :)
        }
        // here means, puri row me kahi koi Q place nhi kr pay
        // toh we'll return back false
        return false;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        solve(n,board);
        return all_conf;
    }
};

int main() {
	Solution S;
	vector<vector<string>> ans = S.solveNQueens(4);

    // printing all possible solutions
	for(auto conf : ans) {
		for(auto row : conf) {
			cout<<row<<endl;
		}
		cout<<endl;
	}
	return 0;
}