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
	// Preorder 			Root->Left->Right
	// Postorder 			Left->Right->Root
	// Reverse Postorder 	Root->Right->Left
	//[slight modification of Preorder then reverse]
	vector<int> postorder(TreeNode *root) {
		vector<int> ans;
		if (!root) return ans;

		stack<TreeNode *> stk;
		stk.push(root);

		while (!stk.empty()) {
			TreeNode *node = stk.top();
			stk.pop();

			// Display
			ans.push_back(node->data);
			// Left
			if (node->left) stk.push(node->left);
			// Right
			if (node->right) stk.push(node->right);
		}

		reverse(ans.begin(), ans.end());

		return ans;
	}
};