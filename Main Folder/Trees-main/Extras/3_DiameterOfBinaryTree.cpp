// 3_DiameterOfBinaryTree.cpp
// https://leetcode.com/problems/diameter-of-binary-tree/
// https://ide.codingblocks.com/s/635313

// TC - O(N)
// SC - O(height)
#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) : val(val), left(NULL), right(NULL) {} 
};

class Solution {
public:
    pair<int,int> recurse(TreeNode* root) {
        if(!root) return {0,0};
        pair<int,int> p1 = recurse(root->left);
        pair<int,int> p2 = recurse(root->right);
        
        int cdia = max(p1.first+p2.first,max(p1.second,p2.second));
        int cheight = 1 + max(p1.first, p2.first);
        return {cheight,cdia};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return recurse(root).second;
    }
};