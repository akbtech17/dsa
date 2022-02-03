// 2_UniqueBinarySearchTrees2.cpp
// https://leetcode.com/problems/unique-binary-search-trees-ii/

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};

class Solution {
public:
    vector<TreeNode*> solve(int s, int e) {
        vector<TreeNode*> finans;
        if(s > e) {
            finans.push_back(NULL);
            return finans;
        }
        
        for(int i=s; i<=e; i++) {
            vector<TreeNode*> leftsubtree = solve(s,i-1);            
            vector<TreeNode*> rightsubtree = solve(i+1,e);
            
            for(int j=0; j<leftsubtree.size(); j++) {
                for(int k=0; k<rightsubtree.size(); k++) {
                    TreeNode* ls = leftsubtree[j];                    
                    TreeNode* rs = rightsubtree[k];
                    
                    TreeNode* root = new TreeNode(i);
                    root->left = ls;
                    root->right = rs;

                    finans.push_back(root);
                }
            }
        }
        // cout<<finans.size()<<" ";
        return finans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};