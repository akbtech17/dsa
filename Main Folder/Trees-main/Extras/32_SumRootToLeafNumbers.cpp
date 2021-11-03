// 32_SumRootToLeafNumbers.cpp
// https://leetcode.com/problems/sum-root-to-leaf-numbers/
// https://ide.codingblocks.com/s/642106

#include <bits/stdc++.h>
using namespace std;

// Approach - Preorder Traversal
// TC - O(N)
// SC - O(height)
class TreeNode {
public:
	int val;
	TreeNode *left, *right;

	TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution {
    vector<string> paths;
public:
    void recurse(TreeNode* root, string path="") {
        if(!root) return;
        if(root and !root->left and !root->right) {
            path+=char(root->val+'0');
            if(path.size()>0) paths.push_back(path);
            return;
        }
        path+=char(root->val+'0');
        recurse(root->left,path);
        recurse(root->right,path);
        return;
    }
    int sumNumbers(TreeNode* root) {
        recurse(root);
        int ans = 0;
        for(auto el : paths) {
            cout<<el<<endl;
            ans += stoi(el);
        }
        
        return ans;
    }
};

int main() {
	return 0;
}