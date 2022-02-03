// 2_BSTUsingPreorderTraversal.cpp
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

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
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = helper(preorder,0,preorder.size()-1);
        return root;
    }
    
    TreeNode* helper(vector<int> v,int s, int e){
        if(s>e) return NULL;
        TreeNode* root = new TreeNode(v[s]);
        int pos = e+1;
        for(int i=s+1;i<=e;i++){
            if(v[s]<v[i]){
                pos = i;
                break;
            }
        }
        root->left = helper(v,s+1,pos-1);
        root->right = helper(v,pos,e);
        return root;         
    }
};