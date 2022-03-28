// 26_SimplyfyPath.cpp
// Problem Link - https://leetcode.com/problems/simplify-path/
// Code Link - https://ide.codingblocks.com/s/658927
// Resource Link - https://www.youtube.com/watch?v=aNONtwL2T60&ab_channel=AyushiSharma
#include <bits/stdc++.h>
using namespace std;

// Approach: Using Stack
// . => curr directory
// .. => par dir
// /// => multiple slashes should be considered only once
// no trailing slash
// always start with /
// TC: O(N)
// SC: O(N)
class Solution {
public:
    string simplifyPath(string path) {
        // string ans = "/";
        int i = 0, n = path.size();
        stack<string> stk;
        
        for(int i=0; i<n; i++) {
            if(path[i] == '/') continue;
            else {
                // extract the current string
                string curr = "";
                while(i+1<n and path[i+1]!='/') {
                    curr += path[i++];
                }
                curr += path[i];
                
                if(curr == ".") {
                    continue;
                }
                else if(curr == "..") {
                    if(!stk.empty()) stk.pop();
                    else continue;
                }
                else {
                    stk.push(curr);
                }
            }
        }        
        string ans = "";
        while(!stk.empty()) {
            ans.insert(0,stk.top());
            ans.insert(0,"/");
            stk.pop();
        }
        
        return ans.empty() ? "/" : ans;
    }
};