// 5-Diameter.cpp
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

int height(TreeNode *root) {
	if(!root) return 0;
	return 1+max(height(root->left),height(root->right));
}

// Time Complexcity = O(N*N) - as we are calc height for each node, and their are total N nodes
// Space Complexcity = Height of Binary Tree
int findDiameter(TreeNode *root) {
	if(!root) return 0;
	// case 1 - diameter through Root node
	int c1 = height(root->left)+height(root->right);
	// case 2 - diameter lies in Left Subtree
	int c2 = findDiameter(root->left);
	// case 3 - diameter lies in Right Subtree
	int c3 = findDiameter(root->right);
	return max(c1,max(c2,c3));
}

// Time Complexcity = O(N) - Number of Nodes
// Space Complexcity = Height of Binary Tree

// using postorder approach
pair<int,int> findDiameterOptimized(TreeNode *root) {
	if(!root) return {0,0};
	// case 1 - find the asnwer while recursing on left subtree
	pair<int,int> c1 = findDiameterOptimized(root->left);
	// case 2 - find the asnwer while recursing on right subtree
	pair<int,int> c2 = findDiameterOptimized(root->right);

	// now form the answer for current node
	int cdia = max(c2.second,max((c1.first + c2.first),c1.second));
	int cheight = 1+max(c1.first,c2.first);

	return {cheight,cdia};
}


void solve(TreeNode *root) {
	cout<<"largest diameter : "<<findDiameter(root)<<endl;

	cout<<"largest diameter2 : "<<findDiameterOptimized(root).second<<endl;
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