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
	int maxDepth(TreeNode *root) {
		if (!root) return 0;

		int left_ht = maxDepth(root->left);
		int right_ht = maxDepth(root->right);

		return 1 + max(left_ht, right_ht);
	}
};