// 26_ReverseString.cpp
// https://leetcode.com/problems/reverse-string/
// https://ide.codingblocks.com/s/635919

// Approach - Two Pointers
// TC - O(N)
// SC - O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& str) {
        int s = 0;
        int e = str.size()-1;
        while(s<e) swap(str[s++],str[e--]);    
        return;
    }
};
