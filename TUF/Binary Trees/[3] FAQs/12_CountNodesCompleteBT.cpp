#include <iostream>
#include <map>
using namespace std;

struct TreeNode {
public:
	TreeNode *left, *right;
	int data;
};

// TC: O(N)
// SC: O(LogN)
class Solution1 {
public:
	int countNodes(TreeNode *root) {
		if (root == nullptr) return 0;
		return 1 + countNodes(root->left) + countNodes(root->right);
	}
};

// TC: O(LogN)^2
// SC: O(LogN)
class Solution2 {
public:
	int countNodes(TreeNode *root) {
		// Base Case
		if (root == NULL) return 0;

		// Recursive Case
		int leftHeight = 0, rightHeight = 0;
		TreeNode *temp = root;

		while (temp) {
			temp = temp->left;
			leftHeight++;
		}

		temp = root;
		while (temp) {
			temp = temp->right;
			rightHeight++;
		}

		if (leftHeight == rightHeight) return pow(2, leftHeight) - 1;
		return 1 + countNodes(root->left) + countNodes(root->right);
	}
};