// 29_ScoreOfParenthesis.cpp
// Problem Link - https://leetcode.com/problems/score-of-parentheses/
// Code Link - https://ide.codingblocks.com/s/658930
#include <bits/stdc++.h>
using namespace std;

// Approach: Using Stack
// contains only opening and closing brackets
// TC: O(N)
// SC: O(N)
class Solution {
public:
    int scoreOfParentheses(string str) {
        // 0 marks opening bracket
        stack<int> stk;
        
        for(int i=0; i<str.size(); i++) {
            if(str[i] == '(') stk.push(0);
            else {
                int btw = 0;
                while(stk.top()!=0) {
                    btw += stk.top();
                    stk.pop();
                }
                stk.pop();
                if(btw) {
                    stk.push(btw*2);
                }
                else {
                    stk.push(1);
                }
            }
        }
        
        int ans = 0;
        while(!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};