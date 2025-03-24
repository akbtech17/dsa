#include <iostream>
#include <map>
using namespace std;

struct TreeNode {
public:
	TreeNode *left, *right;
	int data;
};

// Approach1: Simple DS
// TC: O(NLogN)
// SC: O(N)
class Solution {
public:
	bool static comp(const pair<int, int> &p1, const pair<int, int> &p2) {
		if (p1.first == p2.first) return p1.second < p2.second;
		return p1.first < p2.first;
	}

	vector<vector<int>> verticalTraversal(TreeNode *root) {
		if (!root) return {};

		vector<vector<int>> traversal;
		queue<pair<TreeNode *, pair<int, int>>> q;
		map<int, vector<pair<int, int>>> mp;
		q.push({root, {0, 0}});

		while (!q.empty()) {
			pair<TreeNode *, pair<int, int>> nodeDet = q.front();
			q.pop();

			TreeNode *node = nodeDet.first;
			int x = nodeDet.second.first, y = nodeDet.second.second;
			mp[x].push_back({y, node->data});

			if (node->left) q.push({node->left, {x - 1, y + 1}});
			if (node->right) q.push({node->right, {x + 1, y + 1}});
		}

		for (pair<int, vector<pair<int, int>>> p : mp) {
			sort(p.second.begin(), p.second.end(), comp);
			vector<int> clevel;
			for (pair<int, int> pp : p.second) {
				clevel.push_back(pp.second);
			}
			traversal.push_back(clevel);
		}

		return traversal;
	}
};