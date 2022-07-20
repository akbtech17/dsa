// 18_ValidPerfectSquare.cpp
// Problem Link - https://leetcode.com/problems/valid-perfect-square/
// Code Link - https://ide.codingblocks.com/s/660555
#include <bits/stdc++.h>
using namespace std;

// Approach: Binary Search
// TC: O(LogN)
// SC: O(1)
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        int s = 0, e = num/2;
        
        while(s<=e) {
            long long m = (e-s)/2 + s;
            long long p = m*m;
            if(p == num) return true;
            else if(p < num) s = m+1;
            else e = m-1;
        }
        
        return false;
    }
};