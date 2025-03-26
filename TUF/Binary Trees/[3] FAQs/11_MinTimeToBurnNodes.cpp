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
	void recurse(TreeNode *root, int target, TreeNode *&targetNode,
				 unordered_map<TreeNode *, TreeNode *> &parentMap,
				 TreeNode *parent = nullptr) {
		// base case
		if (root == nullptr) return;

		// recursive case
		if (root->data == target) targetNode = root;
		parentMap[root] = parent;

		recurse(root->left, target, targetNode, parentMap, root);
		recurse(root->right, target, targetNode, parentMap, root);

		return;
	}

	int timeToBurnTree(TreeNode *root, int start) {
		TreeNode *targetNode = nullptr;
		unordered_map<TreeNode *, TreeNode *> parentMap;
		recurse(root, start, targetNode, parentMap);

		unordered_map<TreeNode *, bool> isvis;
		queue<TreeNode *> q;
		int dist = 0;

		q.push(targetNode);
		isvis[targetNode] = true;

		while (!q.empty()) {
			int levelSize = q.size();

			for (int i = 0; i < levelSize; i++) {
				TreeNode *node = q.front();
				q.pop();

				if (node->left && !isvis[node->left]) {
					isvis[node->left] = true;
					q.push(node->left);
				}
				if (node->right && !isvis[node->right]) {
					isvis[node->right] = true;
					q.push(node->right);
				}
				if (parentMap[node] && !isvis[parentMap[node]]) {
					isvis[parentMap[node]] = true;
					q.push(parentMap[node]);
				}
			}
			dist++;
		}

		return dist - 1;
	}
};