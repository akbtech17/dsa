#include <iostream>
using namespace std;

struct TreeNode {
public:
	TreeNode *left, *right;
	int data;
};

// Approach1: Recursive
class Solution1 {
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

// Approach2: Iterative using LOT
class Solution2 {
public:
	// TC: O(N)
	// SC: O(W)
	int maxDepth(TreeNode *root) {
		if (!root) return 0;

		int levels = 0;
		queue<TreeNode *> q;
		q.push(root);

		while (!q.empty()) {
			int qs = q.size();

			for (int i = 0; i < qs; i++) {
				TreeNode *node = q.front();
				q.pop();

				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
			levels++;
		}

		return levels;
	}
};