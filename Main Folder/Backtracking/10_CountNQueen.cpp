// 10_CountNQueen.cpp
// https://leetcode.com/problems/n-queens-ii/

// TC - 
// SC - 
#include <bits/stdc++.h>
using namespace std;

int total_ways = 0;

bool isSafe(int board[][12], int n, int i, int j) {
	//check if no queen is present in the same col
	for (int row = 0; row <= i; row++) {
		if (board[row][j] == 1) return false;
	}
	//check for left diagonal
	int x = i;
	int y = j;
	while (x >= 0 and y >= 0) {
		if (board[x][y] == 1) return false;
		x--;
		y--;
	}
	//check fro right diagonal
	x = i;
	y = j;
	while (x >= 0 and y < n) {
		if (board[x][y] == 1) return false;
		x--;
		y++;
	}
	return true;
}

bool solveNQueenProblem(int board[][12], int n, int i = 0) {
	//base case - agar rows exceed hojati hai limit se
	if (i == n) {
		total_ways++;

		//printing config

		for (i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 1) cout << "{" << i + 1 << "-" << j + 1 << "} ";
			}
			cout << " ";
		}

		// return true;
		// instead of true if we do it false, then it will try for all other valid positions
		return false;
	}
	//now for the current row we will try to place the queen
	for (int j = 0; j < n; j++) {

		//check if is it safe to put the Q on curr pos
		if (isSafe(board, n, i, j)) {
			//for the current row now its safe position, but we are assuming for remaining rows also
			board[i][j] = 1;
			bool bakiQRakhPareHain = solveNQueenProblem(board, n, i + 1);
			if (bakiQRakhPareHain == true) return true;
		}
		//if the control reaces here means, curr pos was not appropriate
		//backtrack krte smy us pos ko mark 0 krdo
		board[i][j] = 0;
		//and curr row ki baaki pos ke liye loop check krlega
	}
	//here means, puri row me kahi koi Q place nhi kr pay
	//toh we'll return back false
	return false;
}

class Solution {
    int total_sol;
public:
    bool isSafe(vector<vector<int>> board, int i, int j, int n) {
        // check for col
        for(int row=0; row<=i; row++) 
            if(board[row][j] == 1) return false;
        //left diagnoal
        int x = i;
        int y = j;
        while(x>=0 and y>=0) 
            if(board[x--][y--] == 1) return false;
        
        // right diagonal
        x = i;
        y = j;
        while(x>=0 and y<n) 
            if(board[x--][y++] == 1) return false;
        
        return true;
    }
    bool solve(int n, vector<string> board, int i=0) {
        if(i == n) {
            total_sol++;
            return false;  // to check for all possible solutions
        }
        for(int j=0; j<n; j++) {
            if(isSafe(board,i,j,n)) {
                board[i][j] = 1;
                bool bakiRakhPare = solve(n,board,i+1);
                if(bakiRakhPare) return true;
            }
            board[i][j] = 0;
        }
        return false;
    }
    int totalNQueens(int n) {
        total_sol = 0;
        vector<vector<int>> board(n,vector<int>(n,0));
        solve(n,board);
        return total_sol;
    }
};

int main() {
	int board[12][12] = {0};
	int n = 4;
	cin >> n;
	solveNQueenProblem(board, n);
	cout << endl << total_ways;
	return 0;
}
