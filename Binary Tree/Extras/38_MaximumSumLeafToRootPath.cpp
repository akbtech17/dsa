// 38_MaximumSumLeafToRootPath.cpp
// Problem Link - https://practice.geeksforgeeks.org/problems/maximum-sum-leaf-to-root-path/1
// Code Link - https://ide.codingblocks.com/s/668858
#include <bits/stdc++.h>
using namespace std;

// Approach: Top Down Recursion (Postorder Traversal)
// TC: O(N)
// SC: O(height)
class Solution{
public:
    int maxPathSum(Node* root) {
        //code here
        if(!root) return 0;

        int s1 = maxPathSum(root->left);
        int s2 = maxPathSum(root->right);
    
        return root->data + max(s1,s2);
    }
};