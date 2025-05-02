#include <iostream>
using namespace std;

struct TreeNode {
public:
	TreeNode *left, *right;
	int data;

	TreeNode(int val) {
		data = val;
		left = nullptr;
		right = nullptr;
	}
};

// Approach1: Recursive (Recommended)
// TC: O(H) ~ O(LogN) in case of Height Balanced BST
// SC: O(H) ~ O(LogN) in case of Height Balanced BST
class Solution1 {
public:
	TreeNode *insertIntoBST(TreeNode *root, int val) {
		// Base Case
		if (root == nullptr) return new TreeNode(val);

		// Recursive Cases
		if (val < root->data)
			root->left = insertIntoBST(root->left, val);
		else
			root->right = insertIntoBST(root->right, val);

		return root;
	}
};

// Approach2: Iterative
// TC: O(H) ~ O(LogN) in case of Height Balanced BST
// SC: O(1)
class Solution2 {
public:
	TreeNode *insertIntoBST(TreeNode *root, int val) {
		if (root == nullptr) return new TreeNode(val);

		TreeNode *temp = root;
		while (true) {
			if (val < temp->data) {
				if (temp->left == nullptr) {
					temp->left = new TreeNode(val);
					break;
				} else
					temp = temp->left;
			} else {
				if (temp->right == nullptr) {
					temp->right = new TreeNode(val);
					break;
				} else
					temp = temp->right;
			}
		}

		return root;
	}
};