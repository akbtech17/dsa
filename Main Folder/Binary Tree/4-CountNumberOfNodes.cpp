// 4-CountNumberOfNodes.cpp

// Time Complexcity = O(Number of Nodes)
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

int countNumberOfNodes(TreeNode *root) {
	if(!root) return 0;
	int cl = countNumberOfNodes(root->left);
	int cr = countNumberOfNodes(root->right);
	return 1+cl+cr;
}


void solve(TreeNode *root) {
	cout<<"number of nodes : "<<countNumberOfNodes(root)<<endl;
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