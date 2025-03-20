#include <iostream>
using namespace std;

struct TreeNode {
public:
	TreeNode *left, *right;
	int data;
};

// Approach1 - Bruteforce (Top Down): refer 3_CheckBalancedBT.cpp
// Approach2 - Optimized (Bottom Up)
class Solution {
public:
	// pair<int, int> : { diameter, height }
	// TC: O(N)
	// SC: O(H)
	pair<int, int> recurse(TreeNode *root) {
		if (!root) return {0, 0};

		pair<int, int> leftSubtree = recurse(root->left);
		pair<int, int> rightSubtree = recurse(root->right);

		int diameterThroughRoot = leftSubtree.second + rightSubtree.second;
		int rootHeight = 1 + max(leftSubtree.second, rightSubtree.second);
		int maxDiaForRoot = max(diameterThroughRoot,
								max(leftSubtree.first, rightSubtree.first));

		return {maxDiaForRoot, rootHeight};
	}

	int diameterOfBinaryTree(TreeNode *root) {
		pair<int, int> ans = recurse(root);
		return ans.first;
	}
};