// 3_PostorderRecursive.cpp
// Problem Link - https://leetcode.com/problems/binary-tree-postorder-traversal/
// Code Link - https://ide.codingblocks.com/s/623582
#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) : val(val), left(NULL), right(NULL) {} 
};

// Approach: LRD
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
		recurse(root->right);
		ans.push_back(root->val);

	}
    vector<int> postorderTraversal(TreeNode* root) {
        recurse(root);
        return ans;
    }
};
