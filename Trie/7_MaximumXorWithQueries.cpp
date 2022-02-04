// 7_MaximumXorWithQueries.cpp
// Question Link - https://leetcode.com/problems/maximum-xor-with-an-element-from-array/submissions/
// Solution Link - https://ide.codingblocks.com/s/654140
#include <bits/stdc++.h>
using namespace std;

// Approach: using the previous trie approach, with some sorting
//           and manipulation of idxes
// TC: O(Q*N*32 + QlogQ + NlogN)
// SC: O(N*32)
class TrieNode {
public:
    TrieNode *left, *right;
    TrieNode() : left(nullptr) ,right(nullptr) {}
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        
        TrieNode *curr = root;

        for(int bidx=30; bidx>=0; bidx--) {
            
            int mask = (1<<bidx);
            int ibit = (mask&num)>0 ? 1 : 0;
            
            if(ibit == 0) {
                if(curr->left == NULL) {
                    curr->left = new TrieNode();
                }
                curr = curr->left;
            }
            
            else {
                if(curr->right == NULL) {
                    curr->right = new TrieNode();
                }
                curr = curr->right;
            }
        }
    }
    
    int find(int num) {
        TrieNode *curr = root;
        int ans = 0; 
        if(!root->left and !root->right) return -1;
        for(int bidx = 30; bidx >= 0; bidx--) {
            int mask = (1<<bidx);
            int ibit = (mask&num)>0 ? 1 : 0;
            
            if(ibit == 0) {
            	// we have to look for 1
                if(curr->right == NULL) {
                    curr = curr->left;
                }
                else {
                    ans += pow(2,bidx);
                    curr = curr->right;
                }
            }
            else {
            	// we want 0
                if(curr->left == NULL) {
                	ans += pow(2,bidx);
                    curr = curr->right;
                }
                else {
                    curr = curr->left;
                }
            }
        }
        return ans;
    }
};

bool myComp(pair<int,pair<int,int>> const &v1, pair<int,pair<int,int>> const &v2) {
    return v1.second.second<v2.second.second;
}

class Solution {
public:
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<pair<int,pair<int,int>>> temp;
        for(int i=0; i<queries.size(); i++) {
            temp.push_back({i,{queries[i][0],queries[i][1]}});
        }
        sort(temp.begin(), temp.end(), myComp);
        sort(nums.begin(),nums.end());
        
        int idx = 0;
        vector<int> ans(queries.size());
        Trie trie;
        
        for(auto q: temp) {
            int idx2 = q.first;
            int el1 = q.second.first;
            int mx = q.second.second;
            
            while(idx<nums.size() and nums[idx]<=mx) {
                // cout<<nums[idx]<<" ";
                trie.insert(nums[idx++]);
            }
            // cout<<endl;
            int el2 = trie.find(el1);
            if(el2 == -1) ans[idx2] = el2;
            else ans[idx2] = el2^el1;
        }
        return ans;
    }
};