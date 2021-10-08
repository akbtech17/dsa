// 2_DesignAddAndSearchWordsDataStructure.cpp
// https://leetcode.com/problems/design-add-and-search-words-data-structure/

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

class WordDictionary {
	TrieNode* root;
public:
    WordDictionary() {
        this->root = new TrieNode('\0');
    }
    
    void addWord(string word) {
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
    bool helper(TrieNode *temp, string word, int i=0) {
        int n = word.size();
        char ch = word[i];
      
        if(i == n) return temp->isTerminal;

        bool ans = false;
        if(ch == '.') {
            for(auto p : temp->children) {
                ans = ans or helper(p.second,word,i+1);
                if(ans) return ans;
            }
        }
        else {
            if(temp->children.count(ch)>0) {
                return helper(temp->children[ch],word,i+1);
            }
            else ans= false;
        }
        return ans;
    }
    bool search(string word) {
        if(word.size() == 0) return true;
        return helper(root,word,0);
    }
};
