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
	vector<int> topView(TreeNode *root) {
		if (!root) return {};

		map<int, int> mp;
		queue<pair<TreeNode *, int>> q;
		q.push({root, 0});

		while (!q.empty()) {
			pair<TreeNode *, int> nodeDet = q.front();
			q.pop();

			TreeNode *node = nodeDet.first;
			int x = nodeDet.second;

			if (mp.count(x) == 0) mp[x] = node->data;

			if (node->left) q.push({node->left, x - 1});
			if (node->right) q.push({node->right, x + 1});
		}

		vector<int> traversal;
		for (pair<int, int> p : mp) {
			traversal.push_back(p.second);
		}

		return traversal;
	}
};