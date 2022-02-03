// 11-SerializeAndDeserialize.cpp

#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
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

	// cout<<"inorder : ";
	// inorder(root);
	// cout<<endl;

	// cout<<"postorder : ";
	// postorder(root);
	// cout<<endl;
	return;
}

// 3 1 -1 -1 2 4 -1 -1 -1
// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
// 1 2 -1 -1 3 4 -1 -1 5 -1 -1
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


class Codec {
    vector<string> serial;
public:
    void doLevelOrder(TreeNode*root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        int level_so_far = 1;
        bool value = true;
        while(!q.empty()) {
        	TreeNode *curr = q.front().first;
        	int clevel = q.front().second;
        	q.pop();
        	// if(curr == NULL) handle
        	if(level_so_far < clevel) {
        		// new level
        		level_so_far = clevel;
        		value = false;
        	}
        	if(curr) value = true;
        	if(false)	
        	if(curr->left) q.push({curr->left,clevel+1});
        	else q.push({NULL,clevel+1});

			if(curr->right) q.push({curr->right,clevel+1});
        	else q.push({NULL,clevel+1});        	
        }
        return;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root) doLevelOrder(root);
        string fin_ans = "[";
        for(int i=0;i<serial.size();i++) {
            if(i != 0) fin_ans += ',';
            fin_ans+=serial[i];
        }
        fin_ans+=']';
        return fin_ans;
    }

    // Decodes your encoded data to tree.
    // TreeNode* deserialize(string data) {
    //     return NULL;
    // }
};

int main() {
	TreeNode* root = buildTree();
	traverse(root);
	Codec solution;
	cout<<solution.serialize(root);
	return 0;
}