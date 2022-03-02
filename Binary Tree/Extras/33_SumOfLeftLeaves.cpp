// 33_SumOfLeftLeaves.cpp
// https://leetcode.com/problems/sum-of-left-leaves/
// https://ide.codingblocks.com/s/642190
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
public:
    
    int sumOfLeftLeaves(TreeNode* root, int direction=0) {
        if(!root) return 0;
        if(!root->left and !root->right and direction == -1) return root->val;
        return sumOfLeftLeaves(root->left,-1)+sumOfLeftLeaves(root->right,1);
    }
};

int main() {
	return 0;
}