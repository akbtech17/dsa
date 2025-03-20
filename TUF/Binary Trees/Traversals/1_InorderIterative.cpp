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
	vector<int> inorder(TreeNode *root) {
		vector<int> ans;
		stack<TreeNode *> stk;

		while (root || !stk.empty()) {
			if (root != nullptr) {
				// Left
				stk.push(root);
				root = root->left;
			} else {
				// Display
				TreeNode *node = stk.top();
				stk.pop();
				ans.push_back(node->data);
				// Right
				root = node->right;
			}
		}

		return ans;
	}
};