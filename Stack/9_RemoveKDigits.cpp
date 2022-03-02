// 9_RemoveKDigits.cpp
// Problem Link - https://leetcode.com/problems/remove-k-digits/
// Code Link - https://ide.codingblocks.com/s/657319
// Resource Link - https://www.youtube.com/watch?v=RCE2L0Zk7xE&t=1333s&ab_channel=Pepcoding
#include <bits/stdc++.h>
using namespace std;

// Approach: Using Stack and String
// TC: O(N)
// SC: O(N)
// 1 => if ch[i-1] > ch[i]... remove all prev ch, till k>0
//      removing the bigger msb will give great effect

// 2 => if ch[i-1] <= ch[i]... dont remove any char,
//      if < case : removing the prev dig, results, greater msb
//      if > case : removing the prev dig, will give no effect

// 3 => if string is processed and k>0, start removing k chars from LSB
//      eg: in case of increasing order of digits :)ss
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> stk;
        
        for(int i=0; i<n; i++) {
            int el = num[i];
            
            while(k>0 and !stk.empty() and stk.top() > el) {
                cout<<stk.top()<<" ";
                stk.pop();
                k--;
            }
            stk.push(el);
        }
        
        while(k>0 and !stk.empty()) {
            stk.pop();
            k--;
        }
        
        string ans = "";
        while(!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        // remove the leading zeroes
        int i = -1;
        while(i+1 < ans.size() and ans[i+1] == '0') i++;
        ans = ans.substr(i+1) ;
        
        return ans.size() == 0 ? "0" : ans;
    }
};