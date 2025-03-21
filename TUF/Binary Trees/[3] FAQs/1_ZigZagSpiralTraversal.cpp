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
	// SC: O(W)
	vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
		if (!root) return {};

		vector<vector<int>> traversal;
		queue<TreeNode *> q;
		q.push(root);
		int level = 0;

		while (!q.empty()) {
			int qs = q.size();
			vector<int> currLevel(qs, 0);

			for (int i = 0; i < qs; i++) {
				TreeNode *node = q.front();
				q.pop();

				if (level % 2 == 0) {
					currLevel[i] = node->data;
				} else {
					currLevel[qs - i - 1] = node->data;
				}

				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
			traversal.push_back(currLevel);
			level++;
		}

		return traversal;
	}
};