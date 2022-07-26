// 23_ArrangingCoins.cpp
// Problem Link - https://leetcode.com/problems/arranging-coins/
// Code Link - https://ide.codingblocks.com/s/669057
#include <bits/stdc++.h>
using namespace std;

// Approach: Native Upper Bound
// TC: O(LogN) 
// SC: O(1)
class Solution {
public:
    int upper_bound(long long int s, long long int e, long long int key) {
        int ans = -1;
        while(s<=e) {
            long long int m = s+(e-s)/2;
            long long int val = m*(m+1)/2; 
            if(val <= key) {
                ans = m;
                s = m+1;
            }
            else e = m-1;
        }
        return ans == -1 ? 0 : ans;
    }
    int arrangeCoins(int n) {
        return upper_bound(0,n,n);
    }
};