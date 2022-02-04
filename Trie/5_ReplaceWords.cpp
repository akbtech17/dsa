// 5_ReplaceWords.cpp
// Question Link - https://leetcode.com/problems/replace-words/
// Solution Link - https://ide.codingblocks.com/s/654138
#include <bits/stdc++.h>
using namespace std;

// Approach: Using trie data-structure
// TC: O(N)
// SC: O(N)
class TrieNode {
public:
    bool isTerminal;
    unordered_map<char,TrieNode*> children;
    
    TrieNode () : isTerminal(false) {};
};

class Trie {
    TrieNode *root;
public:
    Trie(): root(new TrieNode()) {}
    
    void insert(string str) { 
        if(str.size() == 0) return;
        TrieNode *temp = root;
        for(auto ch : str) {
            if(temp->children[ch] == NULL) temp->children[ch] = new TrieNode();     
            temp = temp->children[ch];
        }
        temp->isTerminal = true;
    }
    bool find(string str) {
        if(str.size() == 0) return false;
        TrieNode *temp = root;
        for(auto ch : str) {
            if(!temp->children[ch]) return false;     
            temp = temp->children[ch];
        }
        return temp->isTerminal;
    }
    
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string str) {
        Trie trie;
        for(auto str: dictionary) trie.insert(str);
        
        string ans = "";
        for(int i=0; i<str.size();) {
            if(str[i]>= 'a' and str[i]<='z') {
                string cword = "";
                bool isReplaced = false;
                while(i<str.size() and str[i]>= 'a' and str[i]<='z') {
                    cword += str[i++];
                    if(trie.find(cword)) {
                        isReplaced = true;
                        ans += cword;
                        while(i<str.size() and str[i]>= 'a' and str[i]<='z') i++;
                        break;
                    }
                }
                if(!isReplaced) ans += cword;
            }
            else {
                ans += str[i++];
            }
        }
        return ans;
    }
};