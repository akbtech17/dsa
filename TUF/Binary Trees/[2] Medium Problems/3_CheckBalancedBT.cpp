#include <iostream>
using namespace std;

struct TreeNode {
public:
	TreeNode *left, *right;
	int data;
};

// Approach1 - Bruteforce (Top Down)
class Solution1 {
public:
	int getHeightOfBT(TreeNode *root) {
		if (!root) return 0;
		return 1 + max(getHeightOfBT(root->left), getHeightOfBT(root->right));
	}

	// TC: O(N^2)
	// SC: O(N)
	bool isBalanced(TreeNode *root) {
		if (!root) return true;

		int leftHeight = getHeightOfBT(root->left);
		int rightHeight = getHeightOfBT(root->right);

		int heightDiff = abs(leftHeight - rightHeight);
		bool rootBalanced = heightDiff <= 1;

		bool leftBalanced = isBalanced(root->left);
		bool rightBalanced = isBalanced(root->right);

		return rootBalanced && leftBalanced && rightBalanced;
	}
};

// Approach2 - Optimized (Bottom Up)
class Solution2 {
public:
	pair<bool, int> recurse(TreeNode *root) {
		if (!root) return {true, 0};

		pair<bool, int> leftAns = recurse(root->left);
		pair<bool, int> rightAns = recurse(root->right);

		int currHeight = 1 + max(leftAns.second, rightAns.second);
		int heightDiff = abs(leftAns.second - rightAns.second);
		bool currLevelBalanced =
			(heightDiff <= 1) && leftAns.first && rightAns.first;

		return {currLevelBalanced, currHeight};
	}

	// TC: O(N)
	// SC: O(N)
	bool isBalanced(TreeNode *root) {
		pair<bool, int> ans = recurse(root);
		return ans.first;
	}
};

// Approach3 - Slight modification of Approach2
class Solution3 {
public:
	int recurse(TreeNode *root) {
		if (!root) return 0;

		int leftAns = recurse(root->left);
		int rightAns = recurse(root->right);

		if (leftAns == -1 || rightAns == -1) return -1;

		int heightDiff = abs(leftAns - rightAns);
		bool currLevelBalanced = (heightDiff <= 1);
		int currHeight = 1 + max(leftAns, rightAns);

		return currLevelBalanced ? currHeight : -1;
	}

	// TC: O(N)
	// SC: O(N)
	bool isBalanced(TreeNode *root) {
		int ans = recurse(root);
		return ans != -1;
	}
};