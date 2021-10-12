// 8_WordSearch2_DFS.cpp
// Unoptimized - Not Work
// https://leetcode.com/problems/word-search-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
	vector<string> isPresent;
public:
	bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx, vector<vector<bool>>& isvis) {
		if(idx == word.size()) {
			return true;
		}
		if(i<0 or j<0 or i>=board.size() or j>=board[0].size()) return false;
		if(word[idx]!=board[i][j] or isvis[i][j]) return false;
		
		// mark vis
		isvis[i][j] = true;
		bool ans = 
			dfs(board,word,i+1,j,idx+1,isvis) or
			dfs(board,word,i-1,j,idx+1,isvis) or
			dfs(board,word,i,j+1,idx+1,isvis) or
			dfs(board,word,i,j-1,idx+1,isvis);
		
		// backtrack
		isvis[i][j] = false;
		return ans;
	}

	bool helper(vector<vector<char>>& board, string& word, vector<vector<bool>> isvis, unordered_map<char,list<pair<int,int>>>& mp) {
		int m = board.size();
		int n = board[0].size();
		if(mp.count(word[0]) == 0) return false;
		for(auto p : mp[word[0]]) {
			int i = p.first;
			int j = p.second;
			bool ans = dfs(board,word,i,j,0,isvis);
			if(ans) return true;
		}
		return false;
	}
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
		int n = board[0].size();
        vector<vector<bool>> isvis(m,vector<bool>(n,false));

        // hashmap optimization to store the starting postions of the words
        unordered_map<char,list<pair<int,int>>> mp;
        for(int i=0; i<m; i++) {
        	for(int j=0; j<n; j++) {
        		mp[board[i][j]].push_back({i,j});
        	}
        }


        for(auto str : words) {
        	if(helper(board,str,isvis,mp)) isPresent.push_back(str);
        }
        return isPresent;
    }
};

int main() {

} 