#include <iostream>
#include <map>
using namespace std;

struct TreeNode {
public:
	TreeNode *left, *right;
	int data;

	TreeNode(int data) {
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
	}
};

class Solution {
public:
	// TC: O(N)
	// SC: O(H) + O(N)
	TreeNode *recurse(vector<int> &postorder, vector<int> &inorder,
					  unordered_map<int, int> &mp, int postStart, int postEnd,
					  int inStart, int inEnd) {
		// Base Case
		if (inStart > inEnd || postStart > postEnd) return nullptr;

		// Root node is the last element of postorder
		int rootData = postorder[postEnd];
		int rootIdx = mp[rootData];
		int leftSubtreeSize = rootIdx - inStart;

		TreeNode *root = new TreeNode(rootData);

		// Recursively construct the left and right subtrees
		root->left =
			recurse(postorder, inorder, mp, postStart,
					postStart + leftSubtreeSize - 1, inStart, rootIdx - 1);
		root->right =
			recurse(postorder, inorder, mp, postStart + leftSubtreeSize,
					postEnd - 1, rootIdx + 1, inEnd);

		return root;
	}

	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		int n = inorder.size();
		unordered_map<int, int> mp;

		// Store the index of each value in inorder traversal
		for (int i = 0; i < n; i++)
			mp[inorder[i]] = i;

		return recurse(postorder, inorder, mp, 0, n - 1, 0, n - 1);
	}
};