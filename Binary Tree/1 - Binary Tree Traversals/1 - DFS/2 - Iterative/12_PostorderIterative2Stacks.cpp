// 12_PostorderIterative2Stacks.cpp
// Problem Link - https://practice.geeksforgeeks.org/problems/postorder-traversal-iterative/1
// Code Link - https://ide.codingblocks.com/s/654474
// Resource - https://www.youtube.com/watch?v=2YBhNLodD8Q

#include <bits/stdc++.h>
using namespace std;

// Approach: Using 2 Stacks
// TC: O(N)
// SC: O(N)
class Solution {
    public:
    vector<int> postOrder(Node* root) {
        
        if(!root) return vector<int>();
        
        vector<int> ans;
        stack<Node*> stk1, stk2;
        
        stk1.push(root);
        
        while(!stk1.empty()) {
            root = stk1.top();
            stk1.pop();
            stk2.push(root);
            
            if(root->left) stk1.push(root->left);
            if(root->right) stk1.push(root->right);
        }
        
        while(!stk2.empty()) {
            ans.push_back(stk2.top()->data);
            stk2.pop();
        }
        return ans;
    }
};

int main() {

}