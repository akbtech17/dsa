// 4_WordBreak.cpp
// TC - O(NM * NM)
// SC - 
#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
	char val;
	bool isTerminal;
	unordered_map<char,TrieNode*> children;

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
        return;
    }
};

class Solution {
    Trie tr;
    TrieNode* root;
public:
    bool solve(string str, TrieNode* localRoot, vector<int> &dp, int i=0) {
        if(i == str.size()) {
        	return dp[i] = localRoot->isTerminal;
        }
        if(localRoot->children.count(str[i]) == 0) return dp[i] = false;
        localRoot = localRoot->children[str[i]];
      	if(dp[i] != -1) return dp[i];
      	bool ans = false;
        if(localRoot->isTerminal) {
        	ans = ans or solve(str,root,dp,i+1); 
        	if(ans) return dp[i] = ans;
        }
        ans = ans or solve(str,localRoot,dp,i+1);
        return dp[i] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto word: wordDict) {
        	tr.insert(word);
        }
        root = tr.root;
        vector<int> dp(s.size()+1,-1);
        return solve(s,root,dp);
    }
};
