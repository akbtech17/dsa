// 28_ValidateStackSequences.cpp
// Problem Link - https://leetcode.com/problems/validate-stack-sequences/
// Code Link - https://ide.codingblocks.com/s/658929
#include <bits/stdc++.h>
using namespace std;

// Approach: Using Stack
// TC: O(N)
// SC: O(N)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        
        int ps = 0, pp = 0;
        int n = pushed.size();
        
        while(pp<n and ps<n) {
            if(stk.empty() or popped[pp] != stk.top()) {
                stk.push(pushed[ps]);
                // cout<<"pushed : "<<pushed[ps]<<endl;
                ps++;
            }
            if(!stk.empty() and popped[pp] == stk.top()) {
                stk.pop();
                // cout<<"popped : "<<popped[pp]<<endl;
                pp++;
            }
        }
        
        while(!stk.empty() and pp<n and popped[pp] == stk.top()) {
            stk.pop();
            pp++;
        } 
        
        return pp == n;
    }
};