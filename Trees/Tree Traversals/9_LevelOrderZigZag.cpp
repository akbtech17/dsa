// 9_LevelOrderZigZag.cpp
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

// So basically we use 2 stacks to traverse in Zig Zag fashion.

// TC - O(N)
// SC - O(N)

#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) : val(val), left(NULL), right(NULL) {} 
};

class Solution {
	vector<vector<int>> ans;
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return ans;    // most important edge case
        
        stack<TreeNode*> mn_stk, ch_stk;
        mn_stk.push(root);

        vector<int> clevel;
        bool leftToRight = true;

        while(!mn_stk.empty()) {
        	// pop the current node
        	TreeNode *currnode = mn_stk.top();
        	mn_stk.pop();
        	clevel.push_back(currnode->val);

        	// push its children
        	if(leftToRight) {
        		if(currnode->left) ch_stk.push(currnode->left);
        		if(currnode->right) ch_stk.push(currnode->right);
        	}
        	else {
        		if(currnode->right) ch_stk.push(currnode->right);
        		if(currnode->left) ch_stk.push(currnode->left);
        	}

        	// check if the curr level is over
        	if(mn_stk.empty()) {
        		// make next level as curr level
        		swap(mn_stk,ch_stk);
        		// save the values of curr level
        		ans.push_back(clevel);
        		clevel.clear();
        		// change the direction of traversal
        		leftToRight = !leftToRight;
        	}
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
	vector<vector<int>> ans = S.zigzagLevelOrder(root);

	for(auto clevel : ans) {
		for(auto el : clevel) cout<<el<<" ";
		cout<<endl;
	}
	return 0;
}