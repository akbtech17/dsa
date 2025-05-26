#include <iostream>
using namespace std;

struct TreeNode {
public:
	TreeNode *left, *right;
	int data;

	TreeNode(int val) {
		data = val;
		left = nullptr;
		right = nullptr;
	}
};

// Approach1: Bruteforce
// TC: O(NLogN)
// SC: O(N) + O(LogN)
class Solution1 {
public:
	void recurse(TreeNode *root, vector<int> &nodes) {
		if (root == nullptr) return;

		recurse(root->left, nodes);
		nodes.push_back(root->data);
		recurse(root->right, nodes);

		return;
	}

	void overrideBST(TreeNode *root, vector<int> &nodes, int &i) {
		if (root == nullptr) return;

		overrideBST(root->left, nodes, i);
		root->data = nodes[i++];
		overrideBST(root->right, nodes, i);

		return;
	}

	void recoverTree(TreeNode *root) {
		vector<int> nodes;
		recurse(root, nodes);
		sort(nodes.begin(), nodes.end());

		int i = 0;
		overrideBST(root, nodes, i);
	}
};

// Approach2: Optimized
// TC: O(N)
// SC: O(N)
class Solution2 {
public:
	void recurse(TreeNode *root, TreeNode *&prev, TreeNode *&first,
				 TreeNode *&middle, TreeNode *&last) {
		if (root == nullptr) return;

		recurse(root->left, prev, first, middle, last);

		if (prev != nullptr && root->data < prev->data) {
			if (first == nullptr) {
				first = prev;
				middle = root;
			} else {
				last = root;
			}
		}
		prev = root;

		recurse(root->right, prev, first, middle, last);

		return;
	}

	void recoverTree(TreeNode *root) {
		TreeNode *prev = nullptr;
		TreeNode *first = nullptr;
		TreeNode *middle = nullptr;
		TreeNode *last = nullptr;

		recurse(root, prev, first, middle, last);

		// If we found 2 voilations swap them
		if (first && last) {
			swap(first->data, last->data);
		}
		// Swap the adjacent nodes
		else {
			swap(first->data, middle->data);
		}
		return;
	}
};