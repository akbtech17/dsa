// 2_InorderRecursive.cpp
// Problem Link - https://leetcode.com/problems/binary-tree-inorder-traversal/
// Code Link - https://ide.codingblocks.com/s/623581
#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) : val(val), left(NULL), right(NULL) {} 
};

// Approach: LDR
// TC: O(Nodes)
// SC: O(height) = O(Nodes) {in skewed trees}
class Solution {
	vector<int> ans;
public:
	void recurse(TreeNode *root) {
		// base case
		if(!root) return;

		// recursive cases
		recurse(root->left);
		ans.push_back(root->val);
		recurse(root->right);
	}
    vector<int> inorderTraversal(TreeNode* root) {
        recurse(root);
        return ans;
    }
};
