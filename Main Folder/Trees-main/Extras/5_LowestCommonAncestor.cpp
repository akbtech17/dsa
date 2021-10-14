// 5_LowestCommonAncestor.cpp
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// https://ide.codingblocks.com/s/635377

// TC - O(N)
// SC - O(height)
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    TreeNode *lca;
public:
    pair<bool,bool> recurse(TreeNode* root, TreeNode* p, TreeNode*q) {
        if(root == NULL) return {false,false};
        
        pair<bool,bool> lst = recurse(root->left,p,q);        
        pair<bool,bool> rst = recurse(root->right,p,q);
        
        pair<bool,bool> ans;
        ans.first = lst.first or rst.first or (root == p);        
        ans.second = lst.second or rst.second or (root == q);
        
        if(ans.first and ans.second and lca == NULL) lca = root;
        return ans;
    }
   
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lca = NULL;
        recurse(root,p,q);
        return lca;
    }
};