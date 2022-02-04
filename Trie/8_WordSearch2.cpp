// 8_WordSearch2.cpp
// Question Link - https://leetcode.com/problems/word-search-ii/
// Solution Link - 
// Resource - https://www.youtube.com/watch?v=h0kSTsLaZ-U
#include <bits/stdc++.h>
using namespace std;

// Approach: using the previous trie approach, with some sorting
//           and manipulation of idxes
// TC: O(Q*N*32 + QlogQ + NlogN)
// SC: O(N*32)

class TrieNode {
public:
	char val;
	bool isTerminal;
	unordered_map<char,TrieNode*> children;
	string word;

	TrieNode(char val) {
		this->val = val;
		this->isTerminal = false;
	}
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        this->root = new TrieNode('\0');
    }
    void insert(string& word) {
        TrieNode *temp = root;
        for(auto ch : word) {
        	if(temp->children.count(ch)) temp = temp->children[ch];
        	else {
        		TrieNode *newnode = new TrieNode(ch);
        		temp->children[ch] = newnode;
        		temp = newnode;
        	}
        }
        temp->isTerminal = true;
        temp->word = word;
        return;
    }
};

class Solution {
    Trie tr;
    vector<string> ans; 
public:
    void dfs(vector<vector<char>>& board, int i, int j, int m ,int n, TrieNode* root) {
        if(i<0 or j<0 or i>=m or j>=n) return;

        char ch = board[i][j];
        if(board[i][j] == '$' or root->children.count(ch) == 0) 
            return;

        root = root->children[ch];
        if(root->isTerminal) {
            ans.push_back(root->word);
            root->isTerminal = false;
        }

        board[i][j] = '$';                // marking vis
        dfs(board,i+1,j,m,n,root);
        dfs(board,i-1,j,m,n,root);
        dfs(board,i,j+1,m,n,root);
        dfs(board,i,j-1,m,n,root);

        board[i][j] = ch;                 // marking unvis
        return;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto word : words) {
            tr.insert(word);
        }
        int m = board.size();
        int n = board[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                dfs(board,i,j,m,n,tr.root);
            }
        }
        return ans;
    }
};