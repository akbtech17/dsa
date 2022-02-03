// 3_PostorderRecursive.cpp
// https://leetcode.com/problems/binary-tree-postorder-traversal/


// TC - O(Nodes)
// SC - O(height) = O(Nodes) {in skewed trees}

#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) : val(val), left(NULL), right(NULL) {} 
};

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


TreeNode* buildTree(vector<int> vals, int &i) {
	// grab the first val
	// and check
	if(i == vals.size()) return NULL;
	int val = vals[i];
	if(val == -1) return NULL; // no node exists
	// else 
	TreeNode *newnode = new TreeNode(val);
	i++;
	newnode->left = buildTree(vals,i);
	i++;
	newnode->right = buildTree(vals,i);

	return newnode;
}

int main() {
	Solution S;
	int i = 0;
	TreeNode *root = buildTree({3,1,-1,-1,2,4,-1,-1,-1},i);
	vector<int> ans = S.postorderTraversal(root);
	for(auto el : ans) cout<<el<<" ";
	return 0;
}