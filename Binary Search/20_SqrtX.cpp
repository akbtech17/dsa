// 20_SqrtX.cpp
// Problem Link - https://leetcode.com/problems/sqrtx/
// Code Link - https://ide.codingblocks.com/s/660560
#include <bits/stdc++.h>
using namespace std;

// Approach: 
// TC: O(LogN)
// SC: O(1)
class Solution {
public:
    int mySqrt(int x) {
        int s = 0, e = x;
        int ans = 0;
        while(s<=e) {
            long long int m = s+(e-s)/2;
            long long int p = m*m;
            if(p == x) return m;
            else if(p<x) {
                ans = m;
                s = m+1;
            }
            else e = m-1;
        }
        return ans;
    }
};