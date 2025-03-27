#include <iostream>
using namespace std;

struct TreeNode {
public:
	TreeNode *left, *right;
	int data;
};

// Approach1: Using Recursion
// TC: O(LogN)
// SC: O(LogN)
class Solution1 {
public:
	TreeNode *searchBST(TreeNode *root, int val) {
		if (!root) return nullptr;

		if (root->data == val)
			return root;
		else if (root->data < val)
			return searchBST(root->right, val);
		return searchBST(root->left, val);
	}
};

// Approach2: Iterative
// TC: O(LogN)
// SC: O(1)
class Solution2 {
public:
	TreeNode *searchBST(TreeNode *root, int val) {
		while (root) {
			if (root->data == val)
				return root;
			else if (root->data < val)
				root = root->right;
			else
				root = root->left;
		}

		return nullptr;
	}
};