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
	void recurse(TreeNode *root, vector<int> &ans) {
		if (!root)
			return;

		recurse(root->left, ans);
		recurse(root->right, ans);
		ans.push_back(root->data);

		return;
	}

	vector<int> inorder(TreeNode *root) {
		vector<int> ans;
		recurse(root, ans);
		return ans;
	}
};