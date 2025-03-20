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
		stack<TreeNode *> stk;

		while (root || !stk.empty()) {
			if (root != nullptr) {
				// Display
				ans.push_back(root->data);
				stk.push(root);
				// Left
				root = root->left;
			} else {
				TreeNode *node = stk.top();
				stk.pop();
				// Right
				root = node->right;
			}
		}

		return ans;
	}
};