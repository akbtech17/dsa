#include <iostream>
#include <map>
using namespace std;

struct TreeNode {
public:
	TreeNode *left, *right;
	int data;
};

// TC: O(NLogN)
// SC: O(N)
class Solution {
public:
	vector<int> rightSideView(TreeNode *root) {
		if (!root) return {};

		vector<int> traversal;
		queue<TreeNode *> q;
		q.push(root);

		while (!q.empty()) {
			int qs = q.size();

			for (int i = 0; i < qs; i++) {
				TreeNode *node = q.front();
				q.pop();
				if (i == qs - 1) traversal.push_back(node->data);

				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
		}

		return traversal;
	}
};