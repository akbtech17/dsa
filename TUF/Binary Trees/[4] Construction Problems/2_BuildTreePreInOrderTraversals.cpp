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
	TreeNode *recurse(vector<int> &preorder, vector<int> &inorder,
					  unordered_map<int, int> &mp, int preStart, int preEnd,
					  int inStart, int inEnd) {
		// Base Case
		if (inStart > inEnd) return nullptr;

		// Recursive Cases
		int rootData = preorder[preStart];
		int rootIdx = mp[rootData];
		int leftSubtreeSize = rootIdx - inStart;

		TreeNode *root = new TreeNode(rootData);

		root->left = recurse(preorder, inorder, mp, preStart + 1,
							 preStart + leftSubtreeSize, inStart, rootIdx - 1);
		root->right =
			recurse(preorder, inorder, mp, preStart + leftSubtreeSize + 1,
					preEnd, rootIdx + 1, inEnd);

		return root;
	}

	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		int n = inorder.size();
		unordered_map<int, int> mp;
		for (int i = 0; i < n; i++)
			mp[inorder[i]] = i;

		TreeNode *root = recurse(preorder, inorder, mp, 0, n - 1, 0, n - 1);
		return root;
	}
};