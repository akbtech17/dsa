#include <iostream>
using namespace std;

struct TreeNode {
public:
	TreeNode *left, *right;
	int data;
};

class Solution {
public:
	// TC: O(3N) - each node processed 3 times
	// SC: O(N)
	vector<vector<int>> treeTraversal(TreeNode *root) {
		vector<vector<int>> traversals(3);
		if (!root) return {};

		stack<pair<TreeNode *, int>> stk;
		stk.push({root, 0});

		while (!stk.empty()) {
			pair<TreeNode *, int> nodeData = stk.top();
			stk.pop();

			TreeNode *node = nodeData.first;
			int state = nodeData.second;

			if (state == 0) {
				traversals[1].push_back(node->data);
				stk.push({node, 1});
				if (node->left) stk.push({node->left, 0});
			} else if (state == 1) {
				traversals[0].push_back(node->data);
				stk.push({node, 2});
				if (node->right) stk.push({node->right, 0});
			} else {
				traversals[state].push_back(node->data);
			}
		}

		return traversals;
	}
};