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
	void recurse(TreeNode *root, vector<vector<int>> &traversal, int d = 0) {
		if (!root) return;

		if (traversal.size() <= d) {
			traversal.resize(d + 1);
		}
		traversal[d].push_back(root->data);

		recurse(root->left, traversal, d + 1);
		recurse(root->right, traversal, d + 1);

		return;
	}

	vector<vector<int>> levelOrder(TreeNode *root) {
		vector<vector<int>> traversal;
		recurse(root, traversal);
		return traversal;
	}
};