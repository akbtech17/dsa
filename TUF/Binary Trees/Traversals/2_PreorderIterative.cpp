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
	vector<int> preorder(TreeNode *root) {
		vector<int> ans;
		if (!root) return ans;

		stack<TreeNode *> stk;
		stk.push(root);

		while (!stk.empty()) {
			TreeNode *node = stk.top();
			stk.pop();

			// Display
			ans.push_back(node->data);
			// Right
			if (node->right) stk.push(node->right);
			// Left
			if (node->left) stk.push(node->left);
		}

		return ans;
	}
};