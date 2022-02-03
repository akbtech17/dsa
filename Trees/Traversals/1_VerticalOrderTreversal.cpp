// 1_VerticalOrderTreversal.cpp
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {

	}
};

class Solution {
	// {hd,{level: {nodes}}}
    map<int,map<int,vector<int>>> mp; 
public:
    void traverse(TreeNode* root, int hd = 0) {
        // {Node, {hd,level}}
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        
        while(!q.empty()) {
            TreeNode* curr = q.front().first;
            int hd = q.front().second.first;
            int lev = q.front().second.second;
            q.pop();
            
            mp[hd][lev].push_back(curr->val);
            
            if(curr->left) q.push({curr->left,{hd-1,lev+1}});         
            if(curr->right) q.push({curr->right,{hd+1,lev+1}});

        }
        
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traverse(root);
        
        vector<vector<int>> ans;
        
        for(auto p : mp) {
            vector<int> v;
            for(auto  p2: p.second) {
                sort(p2.second.begin(),p2.second.end());
                for(auto el: p2.second) v.push_back(el);
            }
            ans.push_back(v);
        }
        
        return ans;
    }
};

int main() {

}