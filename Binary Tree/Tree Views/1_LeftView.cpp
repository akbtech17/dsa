// 1_LeftView.cpp
// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

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


// Iterative
class Solution {
	vector<int> ans;
public:
    vector<int> leftView(TreeNode* root) {
    	if(!root) return ans;   // very important edge case
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        while(!q.empty()) {
        	TreeNode *currnode = q.front().first;
        	int currlev = q.front().second;
        	q.pop();

        	if(ans.size()<currlev) ans.push_back(currnode->val);

        	if(currnode->left) q.push({currnode->left,currlev+1});
        	if(currnode->right) q.push({currnode->right,currlev+1});
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
	TreeNode *root = buildTree({10,20,40,-1,-1,60,-1,-1,30,-1,-1},i);
	vector<int> ans = S.leftView(root);
	for(auto el : ans) cout<<el<<" ";
	return 0;
}