// 6-SumReplacement.cpp
// https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1

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

// Time Complexcity = O(N*N) - 
// Space Complexcity = e
int replaceWithSum(TreeNode *root) {
	if(!root) return 0;
	// if the leaf nodes, dont change them
	if(!root->left and !root->right) return root->val;
	int ch1 = replaceWithSum(root->left);
	int ch2 = replaceWithSum(root->right);

	int temp = root->val+ch1+ch2;
	root->val = ch1+ch2;
	return temp;
}

void preorder(TreeNode *root) {
	if(!root) return;
	cout<<root->val<<" ";
	preorder(root->left);
	preorder(root->right);

	return;
}

void solve(TreeNode *root) {
	cout<<"largest diameter : "<<replaceWithSum(root)<<endl;
	preorder(root);
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
	solve(root);

	return 0;
}