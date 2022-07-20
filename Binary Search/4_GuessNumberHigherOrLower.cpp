// 4_GuessNumberHigherOrLower.cpp
// Problem Link - https://leetcode.com/problems/guess-number-higher-or-lower/
// Code Link - https://ide.codingblocks.com/s/635298
#include <bits/stdc++.h>
using namespace std;

// Approach: Recursive
// TC: O(LogN)
// SC: O(LogN)
class Solution {
public:
    int recurse(int s, int e) {
        if(s>e) return -1;
        
        int m = s + (e-s)/2;
        int temp = guess(m);
        
        if(temp == 0) return m;
        else if(temp == -1) e = m-1;
        else s = m+1;
        
        return recurse(s,e);
    }
    int guessNumber(int n) {
        return recurse(1,n);
    }
};