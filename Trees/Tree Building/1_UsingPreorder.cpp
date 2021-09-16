// 1_UsingPreorder.cpp
// Program to build a Binary Tree using preorder values,
// if value = -1 then there is no node present => NULL

// Sample IP -> 3 1 -1 -1 2 4 -1 -1 -1

// Time Complexcity = O(Linear)
// Space Complexcity = Height of Binary Tree


#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) : val(val), left(NULL), right(NULL) {} 
};

void traverse(TreeNode *root) {
	// base case
	if(!root) return;

	// recursive cases
	cout<<root->val<<" ";
	traverse(root->left);
	traverse(root->right);
	return;
}

TreeNode* buildTree() {	
	// take the nput for the first node
	int val;
	cin>>val;

	// if the node is null return null
	if(val == -1) return NULL;

	// else create node for curr value
	TreeNode *root = new TreeNode(val);

	// recurse to build left and right subtrees
	root->left = buildTree();
	root->right = buildTree();
	return root;
} 


int main() {
	TreeNode *root = buildTree();
	traverse(root);
	return 0;
}