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
	// SC: O(H)
	bool isSameTree(TreeNode *p, TreeNode *q) {
		if (!p && !q)
			return true;
		else if (!p || !q)
			return false;
		else if (p->data != q->data)
			return false;

		bool isLeftIdentical = isSameTree(p->left, q->left);
		bool isRightIdentical = isSameTree(p->right, q->right);

		return isLeftIdentical && isRightIdentical;
	}
};