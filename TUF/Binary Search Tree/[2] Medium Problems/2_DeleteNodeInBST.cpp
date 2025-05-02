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

// Approach1: Intuitive using InsertNode Logic
// TC: O(H) ~ O(LogN) in case of Height Balanced BST
// SC: O(H) ~ O(LogN) in case of Height Balanced BST
class Solution1 {
public:
	TreeNode *insertNode(TreeNode *root, TreeNode *node) {
		// Base Case
		if (node == nullptr)
			return root;
		else if (root == nullptr)
			return node;

		// Recursive Cases
		if (node->data < root->data)
			root->left = insertNode(root->left, node);
		else
			root->right = insertNode(root->right, node);

		return root;
	}

	TreeNode *deleteNode(TreeNode *root, int key) {
		// Base Case
		if (root == nullptr) return nullptr;

		// Recursive Cases
		if (key < root->data) {
			root->left = deleteNode(root->left, key);
		} else if (key > root->data) {
			root->right = deleteNode(root->right, key);
		} else {
			TreeNode *rightSubtree = root->right;
			TreeNode *leftSubtree = root->left;
			root = rightSubtree;
			if (root == nullptr) return root;
			root->left = insertNode(leftSubtree, root->left);
		}

		return root;
	}
};

// Approach2: More Logical wrt BST
// TC: O(H) ~ O(LogN) in case of Height Balanced BST
// SC: O(H) ~ O(LogN) in case of Height Balanced BST
class Solution2 {
public:
	TreeNode *deleteNode(TreeNode *root, int key) {
		// Base Case
		if (root == nullptr) return nullptr;

		// Recursive Cases
		if (key < root->data) {
			root->left = deleteNode(root->left, key);
		} else if (key > root->data) {
			root->right = deleteNode(root->right, key);
		} else {
			if (!root->left) return root->right;
			if (!root->right) return root->left;

			TreeNode *leftSubtree = root->left;
			TreeNode *rightSubtree = root->right;

			// Make Left as Root
			TreeNode *newRoot = leftSubtree;

			TreeNode *rightMostNode = newRoot;
			while (rightMostNode->right)
				rightMostNode = rightMostNode->right;

			rightMostNode->right = rightSubtree;
			return newRoot;
		}

		return root;
	}
};