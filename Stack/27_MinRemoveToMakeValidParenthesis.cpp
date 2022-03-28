// 27_MinRemoveToMakeValidParenthesis.cpp
// Problem Link - https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
// Code Link - https://ide.codingblocks.com/s/658928
// Resource Link - https://www.youtube.com/watch?v=wsikPyz0lGo&ab_channel=CodewithAlisha
#include <bits/stdc++.h>
using namespace std;

// Approach: Using Stack
// opening and closing bracket should be in order
// and at each point opening bracket >= closing
// valid solution will contain, ob == cb and all in order
// TC: O(N)
// SC: O(N)
class Solution {
public:
    string minRemoveToMakeValid(string str) {
        stack<int> stk;
        int n = str.size();
        
        for(int i=0; i<n; i++) {
            char ch = str[i];
            switch(ch) {
                case '(':
                    stk.push(i);
                    break;
                case ')':
                    if(!stk.empty() and str[stk.top()] == '(') stk.pop();
                    else stk.push(i);
            }
        }
        
        while(!stk.empty()) {
            str[stk.top()] = ' ';
            stk.pop();
        }
        
        string ans = "";
        for(auto ch: str) {
            if(ch != ' ') ans += ch;
        }
        
        return ans;
    }
};