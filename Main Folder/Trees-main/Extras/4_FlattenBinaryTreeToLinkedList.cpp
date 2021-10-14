// 4_FlattenBinaryTreeToLinkedList.cpp
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// https://ide.codingblocks.com/s/635315

// TC - O(N)
// SC - O(height)
#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) : val(val), left(NULL), right(NULL) {} 
};
class Solution {
    TreeNode *newroot;
    TreeNode *tail;
public:
    TreeNode* recurse(TreeNode* root) {
    	// base case
        if(!root) return NULL;

        // recursive cases
        TreeNode *lst = recurse(root->left);
        TreeNode *rst = recurse(root->right);

        // connect lst with root
        root->right = lst;
        root->left = NULL;
        TreeNode* temp = root;

        while(temp->right) {
            temp = temp->right;
        }

        // connect rst with root
        temp->right = rst;
        return root;
    }
    void flatten(TreeNode* root) {
        recurse(root);
        return;
    }
};