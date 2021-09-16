// 9_LevelOrderZigZag.cpp
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// TC - 
// SC - 

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
        queue<TreeNode*> q;

        if(!root) return ans;    // most important edge case

        q.push(root);
        q.push(NULL);

        vector<int> clevel;

        while(!q.empty()) {
        	TreeNode *currnode = q.front();
        	q.pop();

        	if(currnode == NULL) {
        		if(!q.empty()) q.push(NULL);
        		ans.push_back(clevel);
        		clevel.clear();
        		continue;
        	}

        	clevel.push_back(currnode->val);
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
	vector<vector<int>> ans = S.zigzagLevelOrder(root);

	for(auto clevel : ans) {
		for(auto el : clevel) cout<<el<<" ";
		cout<<endl;
	}
	return 0;
}