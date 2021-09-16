// 7_LevelorderRecursive.cpp
// https://leetcode.com/problems/binary-tree-level-order-traversal/

// TC - O(N)[height] + [O(1)+O(2)...+O(N)] [to print each level] = O(N^2)
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
	vector<int> clevel;
public:
	int height(TreeNode *root) {
		if(!root) return 0;
		return 1+max(height(root->left),height(root->right));
	}

	void recurseForKthLevel(TreeNode* root, int k) {
		if(!root) return;
		if(k == 1) {
			clevel.push_back(root->val);
			return;
		}
		recurseForKthLevel(root->left,k-1);
		recurseForKthLevel(root->right,k-1);

		return;
	}

    vector<vector<int>> levelOrder(TreeNode* root) {
        int ht = height(root);

        for(int level=1; level<=ht; level++) {
        	recurseForKthLevel(root,level);
        	ans.push_back(clevel);
        	clevel.clear();
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
	vector<vector<int>> ans = S.levelOrder(root);

	for(auto clevel : ans) {
		for(auto el : clevel) cout<<el<<" ";
		cout<<endl;
	}
	return 0;
}