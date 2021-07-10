// 3-LevelOrderIterative.cpp

// Time Complexcity = O(N) - because we see every node at one time only
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


// do the level order traversal, in same line
void levelorderIterative(TreeNode *root) {
	queue<TreeNode*> q;
	q.push(root);

	while(!q.empty()) {
		TreeNode *curr = q.front();
		q.pop();

		cout<<curr->val<<" ";

		if(curr->left!=NULL) q.push(curr->left);
		if(curr->right!=NULL) q.push(curr->right);
	}

	return;
}

// do the level order traversal, in different lines
void levelorderIterativeNewLine(TreeNode *root) {
	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		TreeNode *curr = q.front();
		q.pop();

		if(curr == NULL) {
			if(q.empty() == false) q.push(NULL);
			cout<<endl;
			continue;
		}
		else {
			cout<<curr->val<<" ";
			if(curr->left!=NULL) q.push(curr->left);
			if(curr->right!=NULL) q.push(curr->right);
		}
	}

	return;
}

// do the level order traversal, in different lines
// approach 2
void levelorderIterativeNewLine2(TreeNode *root) {
	// pair of node and clevel
	queue<pair<TreeNode*,int>> q;
	q.push({root,1});
	int level_so_far = 1;
	while(!q.empty()) {
		TreeNode *curr = q.front().first;
		int clevel = q.front().second;
		q.pop();
		if(clevel > level_so_far) {
			level_so_far = clevel;
			cout<<endl;
		}
		cout<<curr->val<<" ";
		if(curr->left!=NULL) q.push({curr->left,clevel+1});
		if(curr->right!=NULL) q.push({curr->right,clevel+1});
	}

	return;
}



void traverse(TreeNode *root) {
	cout<<"levelorder : ";
	levelorderIterative(root);
	cout<<endl;

	cout<<"levelorder2 : \n";
	levelorderIterativeNewLine(root);
	cout<<endl;

	cout<<"levelorder3 : \n";
	levelorderIterativeNewLine2(root);
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