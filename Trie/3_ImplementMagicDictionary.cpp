// 3_ImplementMagicDictionary.cpp
// Question Link - https://leetcode.com/problems/implement-magic-dictionary/
// Solution Link - https://ide.codingblocks.com/s/654130
#include <bits/stdc++.h>
using namespace std;

// Approach: Using trie data-structure
// TC: O(26*N*S)
// SC: O(N*S)
class TrieNode {
public:
    unordered_map<char,TrieNode*> children;
    bool isTerminal;
    
    TrieNode() {
        isTerminal = false;
    }
};

class MagicDictionary {
    TrieNode *root;
public:
    MagicDictionary() {
        root = new TrieNode();
    }
    void insert(string str) {
        TrieNode *curr = root;
        for(auto ch: str) {
            if(curr->children[ch] == NULL) curr->children[ch] = new TrieNode();
            curr = curr->children[ch];
        }
        curr->isTerminal = true;
        return;
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto w: dictionary) insert(w);
    }
    
    bool recurse(TrieNode *root, string word, int i=0, bool isChanged = false) {
        if(!root) return false;
        if(i == word.size()) return root->isTerminal and isChanged;
        bool ans = false;
        char cch = word[i];
        
        if(root->children[cch] != NULL) {
            // char is presesnt
            bool case1 = recurse(root->children[cch], word,i+1, isChanged);
            bool case2 = false;
            if(!isChanged) {
                for(auto p : root->children) {
                    if(p.first!=cch) {
                        case2 = case2 or recurse(p.second,word,i+1,true);
                    }
                }
            }
            ans = ans or case1 or case2;
        }
        else {
            // char is not present
            bool case2 = false;
            if(!isChanged) {
                for(auto p : root->children) {
                    if(p.first!=cch) {
                        case2 = case2 or recurse(p.second,word,i+1,true);
                    }
                }
            }
            ans = ans or case2;
        }
        return ans;
    }
    
    bool search(string str) {
        if(str.size() == 0) return true;
        return recurse(root,str);
    }
};