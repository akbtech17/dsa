// 4_ShortestUniquePrefixForEveryStrings.cpp
// Question Link - https://practice.geeksforgeeks.org/problems/shortest-unique-prefix-for-every-word/1#
// Solution Link - https://ide.codingblocks.com/s/654126
// Resource - https://www.youtube.com/watch?v=fpjfjNh658c&t=85s
#include <bits/stdc++.h>
using namespace std;

// Approach: Using trie data-structure
// TC: O(N*S)
// SC: O(N*S)

class TrieNode {
public:
    int val;
    map<char,TrieNode*> children;
    TrieNode(int n=1) {
        val = n;
    }
};
class Solution {
    TrieNode *root;    
public:
    Solution() {
        root = new TrieNode();  
    }
    void insert(string str) {
        TrieNode *temp = root;
        
        for(int i=0; i<str.size(); i++) {
            char ch = str[i];
            if(temp->children[ch]) {
                temp = temp->children[ch];
                temp->val = temp->val+1;
            }
            else {
                temp->children[ch] = new TrieNode();
                temp = temp->children[ch];
            }
        }
    }
    string findSUP(string str) {
        TrieNode *temp = root;
        string ans = "";
        
        for(int i=0; i<str.size(); i++) {
            char ch = str[i];
            int cnt = temp->children[ch]->val;
            ans += ch;
            if(cnt == 1) return ans;
            temp = temp->children[ch];
        }
        return ans;
    }
    vector<string> findPrefixes(string arr[], int n) {
        for(int i=0; i<n; i++) {
            insert(arr[i]);
        }
        vector<string> ans;
        for(int i=0; i<n; i++) {
            ans.push_back(findSUP(arr[i]));
        }
        return ans;
    }  
};