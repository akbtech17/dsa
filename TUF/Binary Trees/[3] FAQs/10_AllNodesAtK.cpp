#include <iostream>
#include <map>
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
	unordered_map<TreeNode *, TreeNode *> getParentMap(TreeNode *root) {
		unordered_map<TreeNode *, TreeNode *> mp;
		queue<TreeNode *> q;

		q.push(root);
		mp[root] = nullptr;

		while (!q.empty()) {
			TreeNode *node = q.front();
			q.pop();

			if (node->left) {
				mp[node->left] = node;
				q.push(node->left);
			}

			if (node->right) {
				mp[node->right] = node;
				q.push(node->right);
			}
		}

		return mp;
	}

	vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
		vector<int> ans;

		if (root == nullptr || target == nullptr) return ans;

		unordered_map<TreeNode *, TreeNode *> parentMap = getParentMap(root);
		unordered_map<TreeNode *, bool> isvis;
		queue<TreeNode *> q;

		int dist = 0;
		q.push(target);
		isvis[target] = true;

		while (!q.empty()) {
			int levelSize = q.size();

			for (int i = 0; i < levelSize; i++) {
				TreeNode *node = q.front();
				q.pop();

				if (dist == k)
					ans.push_back(node->data);
				else if (dist < k) {
					if (node->left && !isvis[node->left]) {
						q.push(node->left);
						isvis[node->left] = true;
					}
					if (node->right && !isvis[node->right]) {
						q.push(node->right);
						isvis[node->right] = true;
					}
					if (parentMap[node] && !isvis[parentMap[node]]) {
						q.push(parentMap[node]);
						isvis[parentMap[node]] = true;
					}
				}
			}
			dist++;
		}

		return ans;
	}
};