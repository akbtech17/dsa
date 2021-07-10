// 1-BuildBinaryTreeFromPreorderValues.cpp

// Program to buil a Binary Tree using preorder values,
// if value = -1 then there is no node present => NULL

// Sample IP -> 3 1 -1 -1 2 4 -1 -1 -1

// Time Complexcity = O(Linear)
// Space Complexcity = Height of Binary Tree

#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left, *right;

	TreeNode(int val) {
		this->val = val;
		left = right = NULL;
	}
};

void preorder(TreeNode *root) {
	if(root == NULL) return;
	cout<<root->val<<" ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(TreeNode *root) {
	if(root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->val<<" ";
}

void inorder(TreeNode *root) {
	if(root == NULL) return;
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}

void traverse(TreeNode *root) {
	cout<<"preorder : ";
	preorder(root);
	cout<<endl;

	cout<<"inorder : ";
	inorder(root);
	cout<<endl;

	cout<<"postorder : ";
	postorder(root);
	cout<<endl;
	return;
}

// 3 1 -1 -1 2 4 -1 -1 -1
// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
// preorder build
TreeNode* buildTree() {	
	int val;
	cin>>val;
	if(val == -1) return NULL;

	TreeNode *root = new TreeNode(val);
	root->left = buildTree();
	root->right = buildTree();

	return root;
} 


int main() {
	TreeNode* root = buildTree();
	traverse(root);

	return 0;
}