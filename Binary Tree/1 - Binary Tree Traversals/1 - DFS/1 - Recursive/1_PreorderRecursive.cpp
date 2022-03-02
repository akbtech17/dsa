// 1_PreorderRecursive.cpp
// Problem Link - https://leetcode.com/problems/binary-tree-preorder-traversal/
// Code Link - https://ide.codingblocks.com/s/623579
#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) : val(val), left(NULL), right(NULL) {} 
};

// Approach: DLR
// TC: O(Nodes)
// SC: O(height) = O(Nodes) {in skewed trees}
class Solution {
	vector<int> ans;
public:
	void recurse(TreeNode *root) {
		// base case
		if(!root) return;

		// recursive cases
		ans.push_back(root->val);
		recurse(root->left);
		recurse(root->right);
	}
    vector<int> preorderTraversal(TreeNode* root) {
        recurse(root);
        return ans;
    }
};

