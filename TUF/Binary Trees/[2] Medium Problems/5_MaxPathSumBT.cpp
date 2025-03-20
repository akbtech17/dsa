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
	int recurse(TreeNode *root, int &maxSum) {
		if (!root) return 0;

		int leftMax = max(0, recurse(root->left, maxSum));
		int rightMax = max(0, recurse(root->right, maxSum));

		int pathAccrossRoot = root->data + leftMax + rightMax;
		maxSum = max(pathAccrossRoot, maxSum);

		return root->data + max(leftMax, rightMax);
	}

	int maxPathSum(TreeNode *root) {
		int maxSum = INT_MIN;
		recurse(root, maxSum);
		return maxSum;
	}
};