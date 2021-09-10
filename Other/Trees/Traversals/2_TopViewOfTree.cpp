// 2_TopViewOfTree.cpp
// https://www.hackerrank.com/challenges/tree-top-view/problem

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};


// Using Level Order Traversal
class Solution1 {
	map<int,int> mp;
public:
	void recurse(TreeNode * root, int hd = 0) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        while(!q.empty()) {
            TreeNode *curr = q.front().first;
            int hd = q.front().second;
            q.pop();
            if(mp.count(hd) == 0) mp[hd] = curr->val;
            if(curr->left) q.push({curr->left,hd-1});
            if(curr->right) q.push({curr->right,hd+1});
        }
  
        return;
    }
    vector<int> topView(TreeNode *root) {
       recurse(root);
       vector<int> ans;
       for(auto p : mp) ans.push_back(p.second);
       return ans;
    }
};

int main() {

}