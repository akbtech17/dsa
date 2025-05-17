#include <iostream>
using namespace std;

// Approach: Recursion + Backtracking
// TC: O(9^(MN)) ~ O(9^E) where E is no of empty cells
// SC: O(MN) ~ O(1) ~ 81
class Solution {
public:
	bool isValid(int i, int j, char digit, vector<vector<char>> &board) {
		for (int ii = 0; ii < 9; ii++) {
			if (digit == board[ii][j]) return false;
			if (digit == board[i][ii]) return false;
		}

		int si = (i / 3) * 3;
		int sj = (j / 3) * 3;

		for (int ii = si; ii < si + 3; ii++) {
			for (int jj = sj; jj < sj + 3; jj++) {
				if (board[ii][jj] == digit) return false;
			}
		}

		return true;
	}

	bool solve(int i, int j, vector<vector<char>> &board) {
		// base case
		if (i == 9) return true;

		// recursive case
		if (j == 9)
			return solve(i + 1, 0, board);
		else if (board[i][j] != '.')
			return solve(i, j + 1, board);
		else {
			for (char digit = '1'; digit <= '9'; digit++) {
				if (isValid(i, j, digit, board)) {
					board[i][j] = digit;
					if (solve(i, j + 1, board))
						return true;
					else
						board[i][j] = '.';
				}
			}
			return false;
		}
		return true;
	}

	void solveSudoku(vector<vector<char>> &board) {
		solve(0, 0, board);
	}
};