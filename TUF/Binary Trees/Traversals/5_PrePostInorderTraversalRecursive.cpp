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
	void recurse(TreeNode *root, vector<vector<int>> &traversals) {
		if (!root) return;

		traversals[1].push_back(root->data);
		recurse(root->left, traversals);
		traversals[0].push_back(root->data);
		recurse(root->right, traversals);
		traversals[2].push_back(root->data);

		return;
	}

	vector<vector<int>> treeTraversal(TreeNode *root) {
		vector<vector<int>> traversals(3);
		recurse(root, traversals);
		return traversals;
	}
};