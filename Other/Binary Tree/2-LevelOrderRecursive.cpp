// 2-LevelOrderRecursive.cpp

// Time Complexcity = O(N*N)
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

// print single level
void printKthLevel(TreeNode *root, int level) {
	if(root == NULL) return;
	if(level == 1) cout<<root->val<<" ";

	printKthLevel(root->left, level-1);
	printKthLevel(root->right, level-1);

	return;
}

// find height of Binary Tree
int height(TreeNode *root) {
	if(root == NULL) return 0;
	return 1+max(height(root->left),height(root->right));
}

// do the level order traversal
void levelOrderRecursive(TreeNode *root) {
	int h = height(root);
	// cout<<h;
	for(int ht = 1; ht<=h;ht++) printKthLevel(root,ht);
	return;
}


void traverse(TreeNode *root) {
	cout<<"levelorder : ";
	levelOrderRecursive(root);
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