#include <iostream>
using namespace std;

struct TreeNode {
public:
	TreeNode *left, *right;
	int data;
};

// Approach1 - using NULL to detect the levels
class Solution1 {
public:
	// TC: O(N)
	// SC: O(N)
	vector<vector<int>> levelOrder(TreeNode *root) {
		vector<vector<int>> traversal;
		if (!root) return traversal;

		queue<TreeNode *> q;
		q.push(root);
		q.push(NULL);

		vector<int> currLevel;
		while (!q.empty()) {
			TreeNode *node = q.front();
			q.pop();

			if (node == NULL) {
				traversal.push_back(currLevel);
				currLevel.clear();

				if (!q.empty()) q.push(NULL);
				continue;
			}

			currLevel.push_back(node->data);
			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);
		}

		return traversal;
	}
};

// Approach2 - Using nested loops
class Solution2 {
public:
	// TC: O(N)
	// SC: O(N)
	vector<vector<int>> levelOrder(TreeNode *root) {
		vector<vector<int>> traversal;
		if (!root) return traversal;

		queue<TreeNode *> q;
		q.push(root);

		while (!q.empty()) {
			int qs = q.size();
			vector<int> currLevel;

			for (int i = 0; i < qs; i++) {
				TreeNode *node = q.front();
				q.pop();

				currLevel.push_back(node->data);

				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
			traversal.push_back(currLevel);
		}

		return traversal;
	}
};