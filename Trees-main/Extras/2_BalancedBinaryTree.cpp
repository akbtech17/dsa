// 2_BalancedBinaryTree.cpp
// https://leetcode.com/problems/balanced-binary-tree/
// https://ide.codingblocks.com/s/635312

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
    pair<bool,int> solve(TreeNode *root) {
        if(!root) return {true,0};
        pair<bool,int> lans = solve(root->left);
        pair<bool,int> rans = solve(root->right);
        
        pair<bool,int> curr_ans;
        curr_ans.first = lans.first and rans.first and (abs(lans.second-rans.second) <=1);
        curr_ans.second = 1+max(lans.second, rans.second);
        
        return curr_ans;
    }
    bool isBalanced(TreeNode* root) {
        return solve(root).first;
    }
};