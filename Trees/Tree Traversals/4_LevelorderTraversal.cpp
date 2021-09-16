// 4_LevelorderTraversal.cpp
// Printing the traversal in single line.

// TC - O(Nodes)
// SC - O(Nodes)

#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) : val(val), left(NULL), right(NULL) {} 
};

class Solution {
	vector<int> ans;
public:
    vector<int> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
        	TreeNode *currnode = q.front();
        	q.pop();
        	ans.push_back(currnode->val);
        	if(currnode->left) q.push(currnode->left);
        	if(currnode->right) q.push(currnode->right);
        }
        return ans;
    }
};


TreeNode* buildTree(vector<int> vals, int &i) {
	// grab the first val
	// and check
	if(i == vals.size()) return NULL;
	int val = vals[i];
	if(val == -1) return NULL; // no node exists
	// else 
	TreeNode *newnode = new TreeNode(val);
	i++;
	newnode->left = buildTree(vals,i);
	i++;
	newnode->right = buildTree(vals,i);
	return newnode;
}

int main() {
	Solution S;
	int i = 0;
	TreeNode *root = buildTree({3,9,-1,-1,20,15,-1,-1,7,-1,-1},i);
	vector<int> ans = S.levelOrder(root);
	for(auto el : ans) cout<<el<<" ";
	return 0;
}