#include <iostream>
using namespace std;

struct TreeNode {
public:
	TreeNode *left, *right;
	int data;
};

// TC: O(N)
// SC: O(N)
class Solution {
public:
	int widthOfBinaryTree(TreeNode *root) {
		if (root == nullptr) return 0;

		int width = 0;
		queue<pair<TreeNode *, int>> q;
		int left = 0, right = 0;

		q.push({root, 0});

		while (!q.empty()) {
			int levelSize = q.size();
			int mmin = q.front().second;
			int leftMost = 0, rightMost = 0;
			for (int i = 0; i < levelSize; i++) {
				pair<TreeNode *, int> nodeDet = q.front();
				q.pop();

				TreeNode *node = nodeDet.first;
				int curr_idx = nodeDet.second - mmin;

				if (i == 0) leftMost = nodeDet.second;
				if (i == levelSize - 1) rightMost = nodeDet.second;

				if (node->left) q.push({node->left, (2 * curr_idx + 1)});
				if (node->right) q.push({node->right, (2 * curr_idx + 2)});
			}

			width = max(rightMost - leftMost + 1, width);
		}

		return width;
	}
};