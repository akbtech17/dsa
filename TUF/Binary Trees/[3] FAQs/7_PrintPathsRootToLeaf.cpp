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
	void recurse(TreeNode *root, vector<int> &path,
				 vector<vector<int>> &paths) {
		if (!root) return;

		path.push_back(root->data);
		if (!root->left && !root->right) {
			paths.push_back(path);
		} else {
			recurse(root->left, path, paths);
			recurse(root->right, path, paths);
		}

		path.pop_back();
	}

	vector<vector<int>> allRootToLeaf(TreeNode *root) {
		vector<vector<int>> paths;
		vector<int> path;

		recurse(root, path, paths);
		return paths;
	}
};