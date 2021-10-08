// 7_WordSearch_DFS.cpp
// https://leetcode.com/problems/word-search/
// https://www.youtube.com/watch?v=vYYNp0Jrdv0&t=20s
// https://ide.codingblocks.com/s/632646

// TC - O(M*N*S)
// SC - O(M*N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool dfs(vector<vector<char>> board, int i, int j, int idx, string &word) {
		if(idx == word.size()) {
			return true;
		}
		if(i<0 or i>=board.size() or j<0 or j>=board[0].size())
			return false;
		if(word[idx]!=board[i][j]) return false;
		
		// so that it will mark vis by some means
		char temp = board[i][j];
		board[i][j] = ' ';
		
		bool chotaAns = 
			dfs(board,i+1,j,idx+1,word) or
			dfs(board,i-1,j,idx+1,word) or
			dfs(board,i,j+1,idx+1,word) or
			dfs(board,i,j-1,idx+1,word);

		// backtracking step - mark unvis
		board[i][j] = temp;
		return chotaAns;
	}

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0; i<m; i++) {
        	for(int j=0; j<n; j++) {
        		// if we found starting char of word at any cell
        		// we try to run dfs and see if we are able to recover
        		// the rem string
        		// if true, ret true
        		// else try the same for other blocks.
        		if(board[i][j] == word[0] and dfs(board, i, j, 0, word))
        			return true;
        	}
        }
        return false;
    }
};
