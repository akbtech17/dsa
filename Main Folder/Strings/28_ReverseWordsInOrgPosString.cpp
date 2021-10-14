// 28_ReverseWordsInOrgPosString.cpp
// https://leetcode.com/problems/reverse-words-in-a-string-iii/
// https://ide.codingblocks.com/s/635922

#include <bits/stdc++.h>
using namespace std;

// Approach - Two Pointers
// TC - O(N)
// SC - O(1)
class Solution {
public:
    string reverseWords(string str) {
        int n = str.size();
        for(int i=0; i<n;) {
            // extract the str/end pos of curr word
            int s = i;
            while(i<n and str[i]!=' ') i++;
            int e = i-1;
            // swap the curr word
            while(s<e) swap(str[s++],str[e--]);
            // skip the spaces
            while(i<n and str[i] == ' ') i++;
        }
        return str;
    }  
};
