#include <iostream>
using namespace std;

struct TreeNode {
public:
	TreeNode *left, *right;
	int data;
};

// TC: O(H)
// SC: O(1)
// Note: They can be calc in 1 function call
class Solution {
public:
	int getFloorOfBST(TreeNode *root, int key) {
		int floor = -1;
		while (root) {
			if (root->data == key) {
				return key;
			} else if (root->data < key) {
				floor = root->data;
				root = root->right;
			} else {
				root = root->left;
			}
		}
		return floor;
	}

	int getCeilOfBST(TreeNode *root, int key) {
		int ceil = -1;
		while (root) {
			if (root->data == key) {
				return key;
			} else if (root->data < key) {
				root = root->right;
			} else {
				ceil = root->data;
				root = root->left;
			}
		}
		return ceil;
	}

	vector<int> floorCeilOfBST(TreeNode *root, int key) {
		// vector<int> ans;

		int floorVal = getFloorOfBST(root, key);
		int ceilVal = getCeilOfBST(root, key);

		return {floorVal, ceilVal};
	}
};