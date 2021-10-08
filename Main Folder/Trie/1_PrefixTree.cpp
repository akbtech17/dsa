// 1_PrefixTree.cpp
// https://leetcode.com/problems/implement-trie-prefix-tree/

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
	TrieNode* root;
public:
    Trie() {
        this->root = new TrieNode('\0');
    }
    
    void insert(string word) {
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
    
    bool search(string word) {
        TrieNode *temp = root;
        for(auto ch : word) {
        	if(temp->children.count(ch)) temp = temp->children[ch];
        	else return false;
        }
        return temp->isTerminal;
    }
    
    bool startsWith(string prefix) {
        TrieNode *temp = root;
        for(auto ch : prefix) {
        	if(temp->children.count(ch)) temp = temp->children[ch];
        	else return false;
        }
        return true;
    }
};

int main() {

}