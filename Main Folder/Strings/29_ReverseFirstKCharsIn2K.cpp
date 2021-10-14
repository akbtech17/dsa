// 29_ReverseFirstKCharsIn2K.cpp
// https://leetcode.com/problems/reverse-words-in-a-string/
// https://ide.codingblocks.com/s/635923

#include <bits/stdc++.h>
using namespace std;

// Approach - Two Pointers
// TC - O(N)
// SC - O(1)

class Solution {
public:
    string reverseStr(string str, int k) {
        int n = str.size();
        for(int i=0; i<n;) {
            int s = i;
            int e = i+k-1;
            if(e >= n) e = n-1;
            while(s<e) swap(str[s++],str[e--]);
            i += (2*k);
        }
        return str;
    }
};