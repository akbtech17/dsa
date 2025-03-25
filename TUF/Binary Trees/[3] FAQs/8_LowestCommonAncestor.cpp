#include <iostream>
using namespace std;

struct TreeNode {
public:
	TreeNode *left, *right;
	int data;
};

// TC: O(N)
// SC: O(H)
class Solution {
public:
	pair<bool, bool> recurse(TreeNode *root, TreeNode *p, TreeNode *q,
							 TreeNode *&lca) {
		if (!root) return {false, false};

		pair<bool, bool> leftAns = recurse(root->left, p, q, lca);
		pair<bool, bool> rightAns = recurse(root->right, p, q, lca);

		int pPresent = leftAns.first || rightAns.first || (p == root);
		int qPresent = leftAns.second || rightAns.second || (q == root);

		if (pPresent && qPresent && (lca == nullptr)) lca = root;
		return {pPresent, qPresent};
	}

	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
		TreeNode *lca = NULL;
		recurse(root, p, q, lca);
		return lca;
	}
};