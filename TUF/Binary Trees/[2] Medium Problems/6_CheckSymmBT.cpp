#include <iostream>
using namespace std;

struct TreeNode {
public:
	TreeNode *left, *right;
	int data;
};

class Solution {
public:
	// TC: O(N)
	// SC: O(H)
	bool helper(TreeNode *root1, TreeNode *root2) {
		if (!root1 && !root2)
			return true;
		else if (!root1 || !root2)
			return false;
		else if (root1->data != root2->data)
			return false;

		return helper(root1->left, root2->right) &&
			   helper(root1->right, root2->left);
	}
	bool isSymmetric(TreeNode *root) {
		if (root == nullptr) return true;
		return helper(root->left, root->right);
	}
};