// 1_FindBottomLeftTreeValue.cpp
// https://leetcode.com/problems/find-bottom-left-tree-value/

// TC - O(N)
// SC - O(Height)

#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) : val(val), left(NULL), right(NULL) {} 
};

class Solution {
    int prevlevel;
    int ans;
public:
    void recurse(TreeNode *root, int clevel = 0) {
        if(!root) return;
        if(prevlevel < clevel) {
            ans = root->val;
            prevlevel = clevel;
        }
        recurse(root->left,clevel+1);        
        recurse(root->right,clevel+1);
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        prevlevel = -1;
        recurse(root);
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
	int ans = S.findBottomLeftValue(root);

	cout<<ans;
	return 0;
}